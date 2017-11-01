#pragma once
class LinearyClassif
{
public:
	LinearyClassif(float **, float *, float, float);
	LinearyClassif();
	void SetEntries(float*, int, int);
	void SetResult(float*);
	void SetStep(float);
	void SetBiais(float);
	void InitW();
	int Perceptron(int);
	void Resolve();
	float* GetResult();
	int GetLengthResult();
	~LinearyClassif();

private:
	int row;
	int column;
	float biais;
	float step;

	float* w;
	float** entries;
	float* results;

};

