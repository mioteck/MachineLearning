#include "LinearyClassification.h"

#pragma region Init

LinearyClassification::LinearyClassification(LinearyClassificationMode m)
{
	mode = m;
}

void LinearyClassification::SetEntries(float * af, int s, int o)
{
	int size = s / o;

	entries = new float*[size];

	for (int i = 0; i < size; i++)
	{
		entries[i] = new float[o+1];
		entries[i][0] = 1;
		for (int j = 1; j < o+1; j++)
		{
			entries[i][j] = af[i * o + j ];
		}
	}

	row = size;
	col = o+1;
}

void LinearyClassification::SetResult(int * af)
{
	results = af;
}

void LinearyClassification::SetStep(float f)
{
	step = f;
}

void LinearyClassification::SetBiais(float f)
{
	biais = f;
}

void LinearyClassification::InitW()
{
	srand(static_cast <unsigned> (time(0)));

	w = new float[col];

	for (int i = 0; i < col; i++)
		w[i] = -1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1 - (-1))));
}

#pragma endregion

#pragma region Resolve
#pragma region Base

void LinearyClassification::Resolve()
{
	switch (mode)
	{
	case Rossenblatt:
		ResolveRosenblatt();
		break;
	case PLA:
		ResolvePLA();
		break;
	default:
		break;
	}
}

int LinearyClassification::Perceptron(int index)
{
	float total = 0;

	float* entry = entries[index];
	for (int i = 0; i < col; i++)
	{
		total += entry[i] * w[i];
	}

	return (total < 0) ? -1 : 1;
}


#pragma endregion

#pragma region Rosenblatt

void LinearyClassification::RosenblattRule(int index)
{
	float* Xk = entries[index];
	int Yk = results[index];
	int gXk = Perceptron(index);



	for (int i = 0; i < col; i++)
	{
		w[i] = w[i] + step * (Yk - gXk) * Xk[i];
	}
}

void LinearyClassification::ResolveRosenblatt()
{
	for (int i = 0; i < row; i++)
	{
		int perceptronReturn = Perceptron(i);
		int result = results[i];
		if (perceptronReturn != result)	RosenblattRule(i);
		std::cout << "Biais (W[0]) : "  << w[0] << " , W[1] " << w[1] << " , W[2] " << w[2] << std::endl;
		if(!isClassified()) i = 0;
	}
}
#pragma endregion

#pragma region PLA

void LinearyClassification::PLARule(int index)
{
	float* Xk = entries[index];
	int Yk = results[index];

	for (int i = 0; i < col; i++)
	{
		w[i] = w[i] + step * Yk * Xk[i];
	}
}

void LinearyClassification::ResolvePLA()
{
	while (!isClassified())
	{
		std::cout << w[0] << " , " << w[1] << std::endl;
		int index = static_cast<int>(rand()) / static_cast<int>(RAND_MAX / (row - 1));
		int perceptronReturn = Perceptron(index);
		int result = results[index];
		if (perceptronReturn != result) PLARule(index);
	}
}

#pragma endregion

#pragma endregion

bool LinearyClassification::isClassified()
{
	for (int i = 0; i < row; i++)
	{
		int perceptronReturn = Perceptron(i);
		int result = results[i];
		if (perceptronReturn != result) return false;
	}
	return true;
}


LinearyClassification::~LinearyClassification()
{
}
