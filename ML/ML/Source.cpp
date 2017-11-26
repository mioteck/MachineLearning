#include "function.h"


int main()
{

	/*float* e = new float[8]{ -1,-1,1,-1,-1,-0.5,1,-0.5};
	int e_size = 8;
	int e_offset = 2;
	int* r = new int[4]{ -1, -1,1 ,1 };*/

	float e[] = { 1.0f,0.0f,0.0f,1.0f,1.0f,1.0f };
	int e_size = 6;
	int e_offset = 2;
	int r[] = { -1, -1,1};

	//float* w = ResolveRosenblatt(e, e_size, e_offset, r, 0.01);
	//float* w = ResolvePLA(e, e_size, e_offset, r, 0.01);
	float* w = LinearRegressionResolve(e, e_size, e_offset, r);

	return 0;
}