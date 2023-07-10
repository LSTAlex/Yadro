#include "Tape.h"
#include <iostream>
#include <fstream>

using namespace std;

Tape::Tape(const string FName, int delay)
	:fin{FName, ios::in | ios::out | ios::trunc | ios::binary},
	length{ 0 },
	CurPos{ 0 },
	delay{ delay }
{
	if (!fin.is_open()) cerr << "Fail can't open" << endl;	
}

Tape::Tape(const string FName, bool isCreation, int delay)
	:fin{ FName, ios::in | ios::out | ios::binary },
	length{ 0 },
	CurPos{ 0 },
	delay{ delay }
{
	if (!fin.is_open()) cerr << "Fail can't open" << endl;
	else cout << "File open!" << endl;
}

int Tape::Read()
{
	this_thread::sleep_for(chrono::milliseconds(delay));
	fin.seekg(CurPos, ios::beg);
	int Value = 0;
	fin.read((char*)&Value, sizeof(int));

	return Value;
}

int Tape::Write(int Value)
{
	this_thread::sleep_for(chrono::milliseconds(delay));
	fin.seekp(CurPos, ios::beg);
	fin.write((char*)&Value, sizeof(int));

	return CurPos;
}

void Tape::MoveL()
{
	this_thread::sleep_for(chrono::milliseconds(delay));
	if (CurPos > 0) CurPos -= sizeof(int);
}

void Tape::MoveR()
{
	this_thread::sleep_for(chrono::milliseconds(delay));
	CurPos += sizeof(int);
	if (CurPos > length)
	{
		length = CurPos;
	}
}

void Tape::ResetZeroPos()
{
	while (CurPos > 0 )
	{
		MoveL();
	}
}

void Tape::Print()
{
	for (size_t i = 0; i < length / sizeof(int); i++)
	{
		fin.seekg(i * sizeof(int), ios::beg);
		int Value = 0;
		fin.read((char*)&Value, sizeof(int));
		cout << Value << " ";
	}
}

void Tape::Clear()
{
	CurPos = 0;
	length = 0;
}

Tape::~Tape()
{
	fin.close();
}
