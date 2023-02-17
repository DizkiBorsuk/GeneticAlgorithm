#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <math.h>

class GeneticAlgorithm
{
public:
	double rank, x, y, z; // rank and function parameters 
	void compute_fitness(double& desired_outcome); 
	std::vector<GeneticAlgorithm> generateInitialPop(int solutions_number, int distribution_width);
	void mutate(std::vector<GeneticAlgorithm>& samples, double mutation_procent = 0.01);
	std::vector<GeneticAlgorithm> cross_over(std::vector<GeneticAlgorithm>& samples, const int& sample_size, unsigned int solutions_number = 1000000);
};

void printSol(std::vector<GeneticAlgorithm>& solutions, int numberOfSolutions); 
bool compareRank(const GeneticAlgorithm& sol1, const GeneticAlgorithm& sol2); 