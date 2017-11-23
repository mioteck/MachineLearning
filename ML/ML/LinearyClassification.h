#pragma once
#include <cstdlib>
#include <iostream>
#include "Enum.h"
#include "struct.h"
#include <ctime>

class LinearyClassification
{
public:
	LinearyClassification(LinearyClassificationMode);
	void SetEntries(float*, int, int);
	void SetResult(int*);
	void SetStep(float);
	void SetBiais(float);
	void InitW();
	void Resolve();
	float* w;

	void RosenblattRule(int);
	void ResolveRosenblatt();
	void PLARule(int);
	void ResolvePLA();
	bool isClassified();
	int Perceptron(int);
	~LinearyClassification();

private:

	LinearyClassificationMode mode;

	int row;
	int col;

	float** entries;
	int* results;
	float biais;

	float step;
};

