/*
ID:nathanlrf
LANG:C++
TASK:beads
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ofstream test("bead.in");
	test<<29<<endl;
	test<<"wwwbbrwrbrbrrbrbrwrwwrbwrwrrb"<<endl;

	ifstream fin("bead.in");
	ofstream fout("bead.out");
	
	string beads;//string of r/b/w
	int N;//number of beads
	fin>>N;
	fin>>beads;

//output
	fout<<N<<endl;
	fout<<beads<<endl;

	return 0;
}