#include "LinearyClassification.h"
#include "struct.h"

int main()
{
	/*float* e = new float[8]{ -1,-1,1,-1,-1,-0.5,1,-0.5};
	int e_size = 8;
	int e_offset = 2;
	int* r = new int[4]{ -1, -1,1 ,1 };*/

	float * e = new float[6]{ 1,0,0,1,1,1 };
	int e_size = 6;
	int e_offset = 2;
	int* r = new int[3]{ -1, -1,1};

	

	float s = 0.0001f;

	LinearyClassification* lc = new LinearyClassification(Rossenblatt);

	lc->SetEntries(e, e_size, e_offset);
	lc->SetResult(r);
	lc->SetStep(s);
	lc->InitW();

	lc->Resolve();

	int result = lc->Perceptron(0);
	int result1 = lc->Perceptron(1);
	int result2 = lc->Perceptron(2);
	//int result3 = lc->Perceptron(3);

	return 0;
}