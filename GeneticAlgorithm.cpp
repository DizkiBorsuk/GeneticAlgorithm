#include "GeneticAlgorithm.h"


void GeneticAlgorithm::compute_fitness(double& desired_outcome)
{
	// first part is some function that solves some problem f(x,y,z,..), desired_outcome is the value we want to get from that function 
	double answer = (6 * std::pow(x, 5) + (-y) + std::pow(z, 20)) - desired_outcome; // we check how close the answer is to desired outcome

	if (abs(answer) == 0.0)
		rank = 99999;
	else
		rank = std::abs(1 / answer); //the lower the answer, the higher rank is (higher rank -> better solution)
}

std::vector<GeneticAlgorithm> GeneticAlgorithm::generateInitialPop(int solutions_number, int distribution_width)
{
	// generate initial, random n (x,y,z) solutions / polulation
	std::random_device device;
	std::uniform_real_distribution<double> randomNumbers(-distribution_width, distribution_width);
	std::vector<GeneticAlgorithm> solutions;

	for (int i = 0; i < solutions_number; i++)
	{
		// assign random numbers to x,y,z in struct (and 0 to rank) and place in vector 
		solutions.emplace_back(GeneticAlgorithm{ 0, randomNumbers(device), randomNumbers(device), randomNumbers(device) });
	}

	return solutions;
}

void GeneticAlgorithm::mutate(std::vector<GeneticAlgorithm>& samples, double mutation_procent)
{
	// mutate selected solutions by selected procent, by default mutate by 1% 
	std::random_device device;
	std::uniform_real_distribution<double> mut_dis(1.0 - mutation_procent, 1.0 + mutation_procent);
	for (auto& sample : samples)
	{
		sample.x *= mut_dis(device);
		sample.y *= mut_dis(device);
		sample.z *= mut_dis(device);
	}
}

std::vector<GeneticAlgorithm> GeneticAlgorithm::cross_over(std::vector<GeneticAlgorithm>& samples, const int& sample_size, unsigned int solutions_number)
{
	// take best mutated solutions and from those generate new population
	std::random_device device;
	std::uniform_int_distribution<int> cross(0, sample_size - 1);
	std::vector<GeneticAlgorithm> solutions{};

	// take random x,y,z from every solution in samples and create new population
	for (int i = 0; i < solutions_number; i++)
	{
		solutions.emplace_back(GeneticAlgorithm{
			0,
			samples[cross(device)].x,
			samples[cross(device)].y,
			samples[cross(device)].z });
	}
	return solutions;
}
