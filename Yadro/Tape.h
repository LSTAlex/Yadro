#pragma once
#include <chrono>
#include <thread>
#include <fstream>

using std::string;
using std::fstream;

class Tape
{
public:

	Tape(const string FName, int delay);
	Tape(const string FName, bool isCreation, int delay);

	int Read();
	int Write(int Value);
	void MoveL();
	void MoveR();
	void ResetZeroPos();
	void Print();
	void Clear();
	~Tape();

private:
	fstream fin;
	size_t length;
	size_t CurPos;
	int delay;

public:

	int GetLength(){ return length; }
	int GetCurPos() { return CurPos; }
	void SetLength(int length) { this->length = length; }
	void SetCurPose(int CurPos) { this->CurPos = CurPos; };
};

