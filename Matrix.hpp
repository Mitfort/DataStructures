#pragma once

#include<iostream>
#include<vector>
#include<random>

class Matrix {
private:
	std::vector<std::vector<double>> data;
	size_t rows, cols;
public:
	Matrix(size_t r, size_t c)
	{
		(*this).rows = r;
		(*this).cols = c;

		(*this).data.resize(r, std::vector<double>(c, 0.0));
	};

	size_t const getCols() { return (*this).cols; };
	size_t const getRows() { return (*this).rows; };
	
	std::vector<double>& operator[] (size_t i) { return data[i]; };
	const std::vector<double>& operator[] (size_t i) const { return data[i]; };
	
	void fillRandom(double min = -1.0, double max = 1.0)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dist(min, max);

		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < cols; ++j)
			{
				(*this).data[i][j] = dist(gen);
			}
		}
	}

	void operator*= (size_t scalar)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				(*this).data[i][j] *= scalar;
			}
		}
	}

	void print()
	{
		std::cout << "--Matrix--" << '\n';

		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < cols; ++j)
			{
				std::cout << data[i][j] << ' ';
			}

			std::cout << '\n';
		}
	}

};
