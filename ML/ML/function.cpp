#include "function.h"


template<typename T>
Eigen::MatrixXd CreateMatrixEntries(T* arr, int s, int o)
{
	int rows = s / o;
	int cols = o + 1;
	int cpt = 0;

	Eigen::MatrixXd mat(rows, cols);

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (x == 0) mat(y, x) = 1;
			else
			{
				mat(y, x) = arr[cpt];
				cpt++;
			}
		}
	}

	return mat;
}

template<typename T>
Eigen::MatrixXd CreateMatrix(T* arr, int s, int o)
{
	int rows = s / o;
	int cols = o;
	int cpt = 0;

	Eigen::MatrixXd mat(rows, cols);

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			mat(y, x) = arr[cpt];
			cpt++;

		}
	}

	return mat;
}

float * InitWeight(int size)
{
	float* w = new float[size];

	for (int i = 0; i < size; i++)
		w[i] = -1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1 - (-1))));

	return w;
}

float* ResolveRosenblatt(float* entries, int size, int offset, int* results, float step)
{
	Eigen::MatrixXd mat = CreateMatrixEntries(entries, size, offset);
	int rows = size / offset;
	float* w = InitWeight(offset + 1);

	int* perceptronResult = new int[rows];

	while (!isClassified(perceptronResult, results, rows))
	{
		for (int i = 0; i < rows; i++)
		{
			perceptronResult[i] = Perceptron(mat.row(i), w);
			if (perceptronResult[i] != results[i])
				RuleRosenblatt(mat.row(i), w, perceptronResult[i], results[i], step);
		}
	}

	return w;
}

void RuleRosenblatt(Eigen::VectorXd row, float* w, int p, int r, float s)
{
	int cols = row.rows();

	for (int i = 0; i < cols; i++)
	{
		w[i] = w[i] + s * (r - p) * row(i);
	}
}

float* ResolvePLA(float* entries, int size, int offset, int* results, float step)
{
	Eigen::MatrixXd mat = CreateMatrixEntries(entries, size, offset);
	float* w = InitWeight(offset + 1);
	int rows = size / offset;

	int* perceptronResult = new int[rows];

	while (!isClassified(perceptronResult, results, rows))
	{
		int index = static_cast<int>(rand()) / static_cast<int>(RAND_MAX / rows);
		perceptronResult[index] = Perceptron(mat.row(index), w);
		if (perceptronResult[index] != results[index])
			RulePLA(mat.row(index), w, results[index], step);
	}

	return w;
}

void RulePLA(Eigen::VectorXd row, float* w, int r, float s)
{
	int cols = row.rows();

	for (int i = 0; i < cols; i++)
	{
		w[i] = w[i] + s * r * row(i);
	}
}

int Perceptron(Eigen::VectorXd row, float* w)
{
	float total = 0;

	for (int i = 0; i < row.rows(); i++)
	{
		total += row(i) * w[i];
	}

	return (total < 0) ? -1 : 1;
}

bool isClassified(int* pResult, int* tResult, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (pResult[i] != tResult[i]) return false;
	}
	return true;
}

float * LinearRegressionResolve(float* entries, int size, int offset, int* results)
{
	Eigen::MatrixXd r = CreateMatrix(results, size / offset, 1);
	Eigen::MatrixXd mat = CreateMatrixEntries(entries, size, offset);

	Eigen::VectorXd v = (mat.transpose()*mat).inverse()*(mat.transpose()*r);

	float* w = new float[offset + 1];

	for (int i = 0; i < offset + 1; i++)
	{
		w[i] = v(i);
	}

	return w;
}