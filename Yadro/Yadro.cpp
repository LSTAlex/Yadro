#include <iostream>
#include <vector>
#include "Tape.h"
#include "MergeSort.h"

using namespace std;

//int main()
//{ 
//    int M{};
//    int delay{};
//    ifstream settings("C:\\Users\\a.lunyov\\source\\repos\\Yadro\\conf\\settings.txt");
//    settings >> M;
//    settings >> delay;
//
//    string inf{};
//    string outf{};
//    cout << "Write name in file " << endl;
//    cin >> inf;
//    cout << "Write name out file " << endl;
//    cin >> outf;
//
//    string Pathin = "C:\\Users\\a.lunyov\\source\\repos\\Yadro\\input\\";
//    string Pathin1 = Pathin + inf + ".dat";
//    string Pathout = "C:\\Users\\a.lunyov\\source\\repos\\Yadro\\output\\";
//    string Pathout1 = Pathout + outf + ".dat";
//
//    Tape in(Pathin1, delay);
//    Tape out(Pathout1, delay);
//
//    Tape tmp1("C:\\Users\\a.lunyov\\source\\repos\\Yadro\\tmp\\1.dat", delay);
//    Tape tmp2("C:\\Users\\a.lunyov\\source\\repos\\Yadro\\tmp\\2.dat", delay);
//
//    vector<int> data{ 21,53,1,56,8,9,3,56,34,6,76 };
//
//    for (size_t i = 0; i < data.size(); i++)
//    {
//        in.Write(data[i]);
//        in.MoveR();
//    }
//
//    MergeSort ms{};
//    ms.SortMerge(in, out, M, tmp1,tmp2);
// 
//    out.Print();
//
//    cout << "Press enter ot finish..." << endl;
//    cin.get();
//
//}

