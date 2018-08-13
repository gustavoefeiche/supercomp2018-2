#include <chrono>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <vector>
#include "funcs.cpp"

void print(auto content, std::string end="\n")
{
	std::cout << content << end;
}

void fill_uniform(int n, double * a, double start=-10.0, double end=10.0)
{
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(start, end);

	for (int i = 0; i < n; ++i)
		a[i] = distribution(generator);
}



int main(int argc, char const *argv[])
{

	std::vector<std::string> funcs = {
		"inner_prod",
		"sum_positive",
		"sqrt_element",
		"exp_element",
		"log_element",
		"gauss"
	};

	std::vector<std::chrono::duration<double>> timings;

	std::chrono::high_resolution_clock::time_point start, end;
	std::chrono::duration<double> elapsed;

	unsigned long n = std::stol(argv[1]);
	double * a = new double[n];
	double * b = new double[n];

	fill_uniform(n, a);
	start = std::chrono::high_resolution_clock::now();
	inner_prod(a, b, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::duration<double>> (end-start);
	timings.push_back(elapsed);

	fill_uniform(n, a);
	start = std::chrono::high_resolution_clock::now();
	sum_positive(a, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::duration<double>> (end-start);
	timings.push_back(elapsed);

	fill_uniform(n, a);
	start = std::chrono::high_resolution_clock::now();
	sqrt_element(a, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::duration<double>> (end-start);
	timings.push_back(elapsed);

	fill_uniform(n, a);
	start = std::chrono::high_resolution_clock::now();
	exp_element(a, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::duration<double>> (end-start);
	timings.push_back(elapsed);

	fill_uniform(n, a);
	start = std::chrono::high_resolution_clock::now();
	log_element(a, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::duration<double>> (end-start);
	timings.push_back(elapsed);

	fill_uniform(n, a);
	start = std::chrono::high_resolution_clock::now();
	gauss(a, b, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::duration<double>> (end-start);
	timings.push_back(elapsed);

	std::cout << std::fixed;

	for(unsigned int i = 0; i < 6; i++)
	{
		std::cout << funcs[i] << " " << timings[i].count() * 1000 << std::endl;
	}

	return 0;
}