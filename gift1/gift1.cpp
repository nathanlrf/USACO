/*
ID: nathanlrf        
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	//this is for test
	ofstream test("gift1.in");
	test<<"5"<<endl;
	test<<"dave"<<endl;
	test<<"laura"<<endl;
	test<<"laura"<<endl;
	test<<"owen"<<endl;
	test<<"vick"<<endl;
	test<<"amr"<<endl;
	test<<"dave"<<endl;
	test<<"200 3"<<endl;
	test<<"laura"<<endl;
	test<<"owen"<<endl;
	test<<"vick"<<endl;
	test<<"owen"<<endl;
	test<<"500 1"<<endl;
	test<<"dave"<<endl;
	test<<"amr"<<endl;
	test<<"150 2"<<endl;
	test<<"vick"<<endl;
	test<<"owen"<<endl;
	test<<"laura"<<endl;
	test<<"0 2"<<endl;
	test<<"amr"<<endl;
	test<<"vick"<<endl;
	test<<"vick"<<endl;
	test<<"0 0"<<endl;
	//comment section above when submit
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	const int size=20;
	int group_num;
	string group_mem[size];
	int i;
	fin>>group_num;
	for(i=0;i<group_num;i++)
	{
		fin>>group_mem[i];
	}

	fout<<group_num<<endl;
	
	for(i=0;i<group_num;i++)
	{
		fout<<group_mem[i]<<endl;
	}

	return 0;
}