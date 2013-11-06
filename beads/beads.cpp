/*
ID:nathanlrf
LANG:C++
TASK:beads
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int cnt_L2R(vector<char>::iterator iter,vector<char>::iterator iter_end);
int cnt_R2L(vector<char>::iterator iter,vector<char>::iterator iter_begin);

int main()
{
	ofstream test("bead.in");
	test<<29<<endl;
	test<<"wwwbbrwrbrbrrbrbrwrwwrbwrwrbb"<<endl;

	ifstream fin("bead.in");
	ofstream fout("bead.out");
	
	string beads;//string of r/b/w
	int N;//number of beads
	fin>>N;
	fin>>beads;

	//init necklace to store beads in vector
	vector<char> necklace;
	int i;
	for(i=0;i<N;i++)
	{
		necklace.push_back(beads[i]);
	}
	vector<char>::iterator iter=necklace.begin();

	int L2R,R2L;
	int sum,new_sum;
	int left_ptr,right_ptr;
	left_ptr=0;
	right_ptr=N-1-left_ptr;
	L2R=cnt_L2R(necklace.begin(),necklace.end());//count from left end to right
	R2L=cnt_R2L(necklace.end()-1,necklace.begin());//count from right end to left
	sum=L2R+R2L;
//output
	fout<<N<<endl;
	fout<<beads<<endl;
	for(iter=necklace.begin();iter!=necklace.end();iter++)
		fout<<*iter;
	fout<<endl;
	fout<<"from left end to count "<<L2R<<endl;
	fout<<"from right end to count "<<R2L<<endl;
	fout<<"the sum of the same color are "<<sum<<endl;

	return 0;
}

int cnt_L2R(vector<char>::iterator iter,vector<char>::iterator iter_end)
{
	int cnt;
	char start;
	start=*iter;
	for(cnt=0;iter!=iter_end;iter++)
	{
		if(*iter==start)
			++cnt;
		else
			return cnt;
	}
}

int cnt_R2L(vector<char>::iterator iter,vector<char>::iterator iter_begin)
{
	int cnt;
	char start;
	start=*iter;
	for(cnt=0;iter!=iter_begin;iter--)//from right end to left
	{
		if(*iter==start)
			++cnt;
		else
			return cnt;
	}
}
