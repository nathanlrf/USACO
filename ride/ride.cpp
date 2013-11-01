//my first c++ project on USACO
//do:
//get two string from file,change letter into number and calculate their reminder against 47 
/*
ID: nathanlrf	
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
/*	//this section is for test
	ofstream fout1("ride.in");
	fout1<<"COMETQ"<<endl;
	fout1<<"HVNGAT "<<endl;
	//
*/
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
	string comet,group;
    int succ;
	int i,j;
	fin>>comet;//read string to commet and group
	fin>>group;
	int comet_size=comet.size();//get string size
	int group_size=group.size();//get string size
	int* comet_to_int=new int[comet_size];
	int* group_to_int=new int[group_size];
	int comet_num=1,group_num=1;

	for(i=0;i<=comet_size-1;i++)
	{
		comet_to_int[i]=comet[i]-'A'+1;
		comet_num*=comet_to_int[i];
	}
	for(j=0;j<=group_size-1;j++)
	{
		group_to_int[j]=group[j]-'A'+1;
		group_num*=group_to_int[j];
	}

	succ=((group_num%47)==(comet_num%47))?1:0;
	if(succ)	fout<<"GO"<<endl;
	else	fout<<"STAY"<<endl;
/*	fout<<comet<<endl;
	fout<<group<<endl;
	fout<<comet_size<<endl;
	fout<<group_size<<endl;
	for(i=0;i<=comet_size-1;i++)
	{
		fout<<comet_to_int[i]<<endl;
	}
	for(j=0;j<=group_size-1;j++)
	{
		fout<<group_to_int[j]<<endl;
	}
	fout<<comet_num<<endl;
	fout<<group_num<<endl;
	fout<<comet_num%47<<endl;
	fout<<group_num%47<<endl;
	fout<<succ<<endl;
*/
    return 0;
}