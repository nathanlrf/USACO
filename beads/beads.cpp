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
	test<<"wwwbbrwrbrbrrbrbrwrwwrbwrwrrr"<<endl;

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
	int sum,new_sum=0;
	int left_ptr,right_ptr;
	left_ptr=0;
	right_ptr=N-1-left_ptr;
	L2R=cnt_L2R(necklace.begin(),necklace.end());//count from left end to right
	R2L=cnt_R2L(necklace.end()-1,necklace.begin());//count from right end to left
	sum=L2R+R2L;
//output
	fout<<N<<endl;
//	fout<<beads<<endl;
	for(iter=necklace.begin();iter!=necklace.end();iter++)
		fout<<*iter;
	fout<<endl;
	fout<<"break between "<<left_ptr<<" and "<<right_ptr<<endl;
	fout<<"from left end to count "<<L2R<<endl;
	fout<<"from right end to count "<<R2L<<endl;
	fout<<"the sum of the same color are "<<sum<<endl;

	return 0;
}

int cnt_L2R(vector<char>::iterator iter,vector<char>::iterator iter_end)
{
	int cnt=0;
	char start;
	start=*iter;
	if(start!='w')//start is b or r
	{
		for(cnt=0;iter!=iter_end;iter++)
		{
			if(*iter==start||*iter=='w')//++cnt when meet with same color or w
				++cnt;
			else
				return cnt;
		}	

	}
	else//start with w
	{
		while(*iter=='w'&&iter!=iter_end)
		{
			++cnt;
			++iter;
		}
		for(start=*iter;iter!=iter_end;iter++)
		{
			if(*iter==start||*iter=='w')//++cnt when meet with same color or w
				++cnt;
			else
				return cnt;
		}	

	}
	
}

int cnt_R2L(vector<char>::iterator iter,vector<char>::iterator iter_begin)
{
	int cnt=0;
	char start;
	start=*iter;
	if(start!='w')//start is b or r
	{
		for(cnt=0;iter!=(iter_begin-1);iter--)
		{
			if(*iter==start||*iter=='w')//++cnt when meet with same color or w
				++cnt;
			else
				return cnt;
		}	

	}
	else//start with w
	{
		while(*iter=='w'&&iter!=(iter_begin-1))
		{
			++cnt;
			++iter;
		}
		for(start=*iter;iter!=(iter_begin-1);iter--)//here *iter is b or r same as not-w start
		{
			if(*iter==start||*iter=='w')//++cnt when meet with same color or w
				++cnt;
			else
				return cnt;
		}	

	}
}
