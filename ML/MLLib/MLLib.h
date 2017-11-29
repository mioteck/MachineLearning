#pragma once

#include <Dense>

#ifdef MLLIB_EXPORTS
#define MLLIBDLL_API __declspec(dllexport)
#else
#define MLLIBDLL_API __declspec(dllimport)
#endif

namespace ML {

	template<typename T>
	Eigen::MatrixXd CreateMatrixEntries(T*, int, int);

	template<typename T>
	Eigen::MatrixXd CreateMatrix(T*, int, int);

	float* InitWeight(int size);

	void RuleRosenblatt(Eigen::VectorXd, float*, int, int, float);

	void RulePLA(Eigen::VectorXd row, float* w, int r, float s);

	int Perceptron(Eigen::VectorXd, float*);

	bool isClassified(int*, int*, int);

	extern "C"
	{
		MLLIBDLL_API float* LinearRegressionResolve(float*, int, int, int*);

		MLLIBDLL_API float* ResolveRosenblatt(float*, int, int, int*, float);

		MLLIBDLL_API float* ResolvePLA(float*, int, int, int*, float);

		MLLIBDLL_API int testdll(int a);
	}
}