#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <math.h>

#include "GeneticAlgorithm.h"

/// 
/// Genetic Algorithm Pseudo Code:  
// START
/// Generate the initial population
/// Compute fitness
// REPEAT
/// Selection
/// Mutation 
/// Crossover
/// Compute fitness
// UNTIL population has converged
// STOP


inline void error(const GeneticAlgorithm& solution1, double outcome)
 {
	double x = solution1.x; 
	double y = solution1.y;
	double z = solution1.z;

	long double answer = (6 * std::pow(x, 5) + (-y) + std::pow(z, 20)) - outcome;
	std::cout << "Answer = " <<std::fixed<< answer << "\n";  
 }


int main()
{
	GeneticAlgorithm GA;

	// Create initial random guesses
	std::vector<GeneticAlgorithm> solutions;
	solutions.reserve(1000000);
	solutions = GA.generateInitialPop(1000000, 100);
	
	// Ask for what outcome from f(x,y,...) are we looking for
	double desired_outcome{};
	std::cout << "What outcome from f() are you looking for: "; 
	std::cin >> desired_outcome;
	std::cout << "\n"; 
	
	double rank = 0; 

	while (true)
	{ 
		// Compute fitness of initial (and every next) population 
		for (auto& solution : solutions)
		{
			 solution.compute_fitness(desired_outcome); // for every set of rank,x,y,z in vector i call fitness function from struct to check the answer and assigne rank  
		}

		// sort solutions based on rank, higher rank -> better
		std::sort(solutions.begin(), solutions.end(), compareRank); 
	
		// Print top m solutions (10) and show error for the solution with the highest rank
		printSol(solutions, 10); 
		error(solutions.front(), desired_outcome); 

		//take top n solutions
		const int sample_size = 1000;
		std::vector<GeneticAlgorithm> samples;
		samples.reserve(sample_size); 

		std::copy(solutions.begin(), solutions.begin()+sample_size, std::back_inserter(samples));

		solutions.clear(); 

		// Mutate top solution by x % 
		GA.mutate(samples);

		// Cross over
		solutions = GA.cross_over(samples, sample_size); 
	}
	return 0; 
}