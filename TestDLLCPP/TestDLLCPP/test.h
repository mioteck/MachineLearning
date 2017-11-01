#pragma once
#ifdef TESTFUNCDLL_EXPORT
#define TESTFUNCDLL_API __declspec(dllexport) 
#else
#define TESTFUNCDLL_API __declspec(dllimport) 
#endif

#include "LinearyClassif.h"

extern "C" {
//	TESTFUNCDLL_API LinearyClassif* LoadLinearyClassifModel(float **, float *, float, float);
	TESTFUNCDLL_API LinearyClassif* LoadLinearyClassifModel();
	TESTFUNCDLL_API float* GetValueResultLineary(LinearyClassif*);
	TESTFUNCDLL_API int GetLengthResultLineary(LinearyClassif*);
	TESTFUNCDLL_API void DeleteLineary(LinearyClassif*);
	TESTFUNCDLL_API void SetEntries(LinearyClassif*, float*, int, int);
	TESTFUNCDLL_API void SetResult(LinearyClassif*, float*);
	TESTFUNCDLL_API void SetBiais(LinearyClassif*, float);
	TESTFUNCDLL_API void SetStep(LinearyClassif*, float);
	TESTFUNCDLL_API void InitW(LinearyClassif*);

}
