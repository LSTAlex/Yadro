#include "MergeSort.h"
#include "Tape.h"
#include "string"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

void Merge(Tape* in, Tape* out, std::vector<int> arr);
void CopyTape(Tape* in, Tape* out);

MergeSort::MergeSort(){}

void MergeSort::SortMerge(Tape& in, Tape& out, int M, Tape &tmp1, Tape &tmp2)
{
	M = M / sizeof(int);
	std::vector<int> arrin{};
	in.ResetZeroPos();

	int count{};
	int Step{1};
	int len = in.GetLength() / sizeof(int);
	
	Tape* f1 = &tmp1, * f2 = &tmp2;

	while (count < len)
	{
		size_t i = 1;
		//Read in array and add temp array
		for (i = 1; i <= M; i++)
		{
			count++;
			arrin.push_back(in.Read());
			in.MoveR();
			if (count == len)
			{
				break;
			}
		}
		std::sort(arrin.begin(), arrin.end());

		if (Step % 2 == 0)
		{
			f1 = &tmp1;
			f2 = &tmp2;
		}
		else
		{
			f1 = &tmp2;
			f2 = &tmp1;
		}
		cout << "f1" << "  ";
		f1->Print();
		cout << endl << "f2    ";
		f2->Print();
		cout << endl;
		for (size_t i = 0; i < arrin.size(); i++)
		{
			cout << arrin[i] << " ";
		}
		cout << endl;
		Merge(f1, f2, arrin);
		arrin.clear();
		Step++;
	}

	f2->Print();
	cout << endl << "out  ";
	CopyTape(f2,&out);

}

void CopyTape(Tape* in, Tape* out)
{
	in->ResetZeroPos();
	for (size_t i = 0; i < in->GetLength() / sizeof(int); i++)
	{
		out->Write(in->Read());
		in->MoveR();
		out->MoveR();
	}
}

void Merge(Tape* in, Tape* out , std::vector<int> arr)
{
	out->Clear();
	int len = in->GetLength() / sizeof(int);
	in->ResetZeroPos();
	int i = 0, j = 0;
	for(int l = 0 ; l < len + arr.size(); l++)
	{	
		if (i > len - 1 )
		{
			out->Write(arr[j]);
			out->MoveR();
			j++;
		}
		else if (j > arr.size() - 1)
		{
			out->Write(in->Read());
			in->MoveR();
			out->MoveR();
			i++;
		}
		else
		{
			int x = in->Read();
			if (arr.size() == 0 || x < arr[j])
			{
				out->Write(x);
				in->MoveR();
				out->MoveR();
				i++;
			}
			else
			{
				out->Write(arr[j]);
				out->MoveR();
				j++;
			}
		}
	}
}