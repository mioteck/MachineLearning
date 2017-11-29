#include <iostream>

#include "stdafx.h"

typedef float* (__cdecl * dll_mllib_resolvepla_ptr)(float*, int, int, int*, float);

typedef float* (__cdecl * dll_mllib_resolveros_ptr)(float*, int, int, int*, float);

typedef float* (__cdecl * dll_mllib_linearreg_ptr)(float*, int, int, int*);

typedef int (__cdecl * dll_mllib_test_ptr)(int);

HINSTANCE hGetProcIDDL;

extern "C" {
	__declspec(dllexport) float * ResolvePLA(float*, int, int, int*, float);

	__declspec(dllexport) float * ResolveRosenblatt(float*, int, int, int*, float);

	__declspec(dllexport) float * LinearRegressionResolve(float*, int, int, int*);

	__declspec(dllexport) int testdll(int);
}

void LoadDLL() 
{
	if (!hGetProcIDDL) {
#if _WIN64
		hGetProcIDDL = LoadLibrary(L"..\\..\\ML\\x64\\Debug\\MLLib.dll");
#elif _WIN32
		hGetProcIDDL = LoadLibrary(L"..\\..\\ML\\Debug\\MLLib.dll");
#endif

		if (!hGetProcIDDL) {
			std::cerr << "Could not load MLLib.dll." << std::endl;
		}
	}
}

void freeDLL() 
{
	FreeLibrary(hGetProcIDDL);
	hGetProcIDDL = nullptr;
}

// Note : For finding real function name, opening DLL with Dependency Walker
// Website : http://www.dependencywalker.com/
float * ResolvePLA(float* entries, int size, int offset, int* results, float step)
{
	LoadDLL();

	dll_mllib_resolvepla_ptr func = (dll_mllib_resolvepla_ptr)GetProcAddress(hGetProcIDDL, "ResolvePLA");
	if (!func) {
		std::cerr << "Could not find function ResolvePLA in MLLib.dll" << std::endl;
		return nullptr;
	}

	float * r = func(entries, size, offset, results, step);

	freeDLL();
	return r;
}

float * ResolveRosenblatt(float* entries, int size, int offset, int* results, float step)
{
	LoadDLL();

	dll_mllib_resolveros_ptr func = (dll_mllib_resolveros_ptr) GetProcAddress(hGetProcIDDL, "ResolveRosenblatt");
	if (!func) {
		std::cerr << "Could not find function ResolveRosenblatt in MLLib.dll" << std::endl;
		return nullptr;
	}

	float * r = func(entries, size, offset, results, step);

	freeDLL();
	return r;
}

float * LinearRegressionResolve(float* entries, int size, int offset, int* results)
{
	LoadDLL();

	dll_mllib_linearreg_ptr func = (dll_mllib_linearreg_ptr) GetProcAddress(hGetProcIDDL, "LinearRegressionResolve");
	if (!func) {
		std::cerr << "Could not find function LinearRegressionResolve in MLLib.dll" << std::endl;
		return nullptr;
	}

	float * r = func(entries, size, offset, results);

	freeDLL();
	return r;
}

int testdll(int a) 
{
	LoadDLL();

	dll_mllib_test_ptr func = (dll_mllib_test_ptr)GetProcAddress(hGetProcIDDL, "testdll");
	if (!func) {
		std::cerr << "Could not find function testdll in MLLib.dll" << std::endl;
		return -1;
	}

	int r = func(a);

	freeDLL();
	return r;
}