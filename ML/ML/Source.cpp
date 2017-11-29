#include "..\MLLib\MLLib.h"

#include <iostream>

int main()
{
	float* e = new float[8]{ -1,-1,1,-1,-1,-0.5,1,-0.5};
	int e_size = 8;
	int e_offset = 2;
	int* r = new int[4]{ -1, -1,1 ,1 };

	/*float e[] = { 1.0f,0.0f,0.0f,1.0f,1.0f,1.0f };
	int e_size = 6;
	int e_offset = 2;
	int r[] = { -1, -1,1};*/

	//float* w = ML::ResolveRosenblatt(e, e_size, e_offset, r, 0.1);
	float* w = ML::ResolvePLA(e, e_size, e_offset, r, 0.1); // <-- Use MLLib instead of function.cpp
	//float* w = ML::LinearRegressionResolve(e, e_size, e_offset, r);

	for (int i = 0; i < 3; i++)
	{
		std::cout << w[i] << std::endl;
	}

	int quit = 0;
	std::cin >> quit;

	return 0;
}