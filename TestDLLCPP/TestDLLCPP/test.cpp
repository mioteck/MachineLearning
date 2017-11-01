#include "test.h"
#include "LinearyClassif.h"

#include <iostream>
#include <fstream>
using namespace std;

extern "C" {
	/*LinearyClassif* LoadLinearyClassifModel(float ** _entries, float * _results, float _step, float _biais)
	{
		LinearyClassif* lc = new LinearyClassif(_entries, _results, _step, _biais);
		return lc;
	}*/

	LinearyClassif* LoadLinearyClassifModel()
	{
		LinearyClassif* lc = new LinearyClassif();
		return lc;
	}


	void SetEntries(LinearyClassif* lc, float* af, int s , int o)
	{
		lc->SetEntries(af, s, o);
	}

	void SetResult(LinearyClassif* lc, float* af)
	{
		lc->SetResult(af);
	}

	void SetBiais(LinearyClassif* lc, float f)
	{
		lc->SetBiais(f);
	}

	void SetStep(LinearyClassif* lc, float f)
	{
		lc->SetStep(f);
	}

	void InitW(LinearyClassif* lc)
	{
		lc->InitW();
	}

	float* GetValueResultLineary(LinearyClassif* lc)
	{
		lc->Resolve();
		return lc->GetResult();
	}

	int GetLengthResultLineary(LinearyClassif* lc)
	{
		return lc->GetLengthResult();
	}

	void DeleteLineary(LinearyClassif* lc)
	{
		delete lc;
	}


}