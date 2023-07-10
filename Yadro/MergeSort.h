#pragma once
#include <cstdio>
#include <fstream>
#include "Tape.h"


class MergeSort
{
public:

	MergeSort();
	void SortMerge(Tape& in, Tape& out,int M, Tape& tmp1, Tape& tmp2);

private:
};

