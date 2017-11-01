#include "LinearyClassif.h"
#include <cstdlib>



LinearyClassif::LinearyClassif(float** _entries, float* _results, float _step, float _biais)
{
	entries = _entries;
	results = _results;
	step = _step;
	biais = _biais;

	row = sizeof(entries) / sizeof(entries[0]);
	column = sizeof(entries[0]) / sizeof(float);

	w = new float[column];

	for (int i = 0; i < column; i++)
		w[i] = rand() % 2 - 1;

}

LinearyClassif::LinearyClassif()
{

}

void LinearyClassif::SetEntries(float* af, int s, int o)
{
	int size = s / o;

	entries = new float*[size];

	for (int i = 0; i < size; i++)
	{
		entries[i] = new float[3] {af[i], af[i+1], af[i+2]};
	}

	row = size;
	column = o;
}

void LinearyClassif::SetResult(float* af)
{
	results = af;
}

void LinearyClassif::SetStep(float f)
{
	step = f;
}

void LinearyClassif::SetBiais(float f)
{
	biais = f;
}

void LinearyClassif::InitW()
{
	w = new float[column];

	for (int i = 0; i < column; i++)
		w[i] = rand() % 2 - 1;
}

void LinearyClassif::Resolve()
{
	for (int i = 0; i < row; i++)
	{
		int perceptronReturn = Perceptron(i);
		if (perceptronReturn != results[i])
		{
			float total = 0;

			for (int k = 0; k < column; k++)
			{
				total += entries[k][i] * w[i];
			}

			total += biais;

			for (int j = 0; j < column; j++)
			{
				w[j] = w[j] + step * (results[j] - perceptronReturn) * total;
			}

			i = 0;
		}
	}
}

float* LinearyClassif::GetResult()
{
	return w;
}

int LinearyClassif::GetLengthResult()
{
	return sizeof(w) / sizeof(float);
}

int LinearyClassif::Perceptron(int index)
{
	float total = 0;

	for (int i = 0; i < column; i++)
	{
		total += entries[index][i] * w[i];
	}

	total += biais;
	
	return (total < 0) ? -1 : 1;
}

LinearyClassif::~LinearyClassif()
{
}
