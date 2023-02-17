#include "GeneticAlgorithm.h"

void printSol(std::vector<GeneticAlgorithm>& solutions, int numberOfSolutions)
{	/// function for printing number of Algorithm solutions

	std::for_each(solutions.begin(), solutions.begin() + numberOfSolutions,
		[](const auto& sol) {std::cout << std::fixed << "Rank = " << static_cast<int>(sol.rank) <<
		"\n x: " << sol.x << " y: " << sol.y << " z: " << sol.z << "\n"; });
}

bool compareRank(const GeneticAlgorithm& sol1, const GeneticAlgorithm& sol2)
{	/// function fot comparing ranks for std::sort // TODO: replace with lambda 
	return sol1.rank > sol2.rank;
}
