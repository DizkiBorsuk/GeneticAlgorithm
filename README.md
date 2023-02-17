# Genetic Algoryithm
This project is simple implementation of Genetic Algorithm in C++. Assume we have some mathematical function f(x,y,z,...) thath describes some process and we know the outcome of that function but we want to know parameters x,y,z. We can use Genetic Algorithm to find those parameters. 
GeneticAlgorithm.cpp contains GenetricAlgorithm class, main.cpp contains algorithm implementation and tools.cpp contains functions i used in main e.g function for printing results. If you want to change function you have to change it in compute_fitness function and error function. 

## How does Genetic Algorithm works? 
Algorithm is based on 3 principles of theory of evolution: Varaiation, Selection and Heredity. 
We want to find values of x,y,z parameters so first we need initial population (Variety), we create n random x,y,z solutions. Then we compute fitness - we check what ansewer does f(x,y,z) return for those initial guesses and how far is it from our desired outcome. Based on that we assign rank to every soluton set, we sort them based on rank and we take 1000 best solutions (Selection). 
In next step we randomly mutate those 1000 best solutions by e.g. 1%. Next is cross-over, randomly chosen x,y,z (randomly from those 1000 muateted solutions) are combined to create new population. Process is repeated untill you think error is small enough. 
If you want to learn more about genetic algorithm here is greate video series about it: https://www.youtube.com/watch?v=9zfeTw-uFCw&list=PLRqwX-V7Uu6bJM3VgzjNV5YxVxUwzALHV

## TO DO: 
- add passing f(x,y,z,...) as an argument to compute_fitness and error functions. 
