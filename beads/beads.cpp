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
int cnt_R2L(vector<char>::iterator iter,int L2R,int N);

int main()
{
	
	ofstream test("beads.in");
	test<<29<<endl;
	test<<"wwwbbrwrbrbrrbrbrwrwwrbwrwrrb"<<endl;
	
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	
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
	vector<char>::iterator iter=necklace.begin();//iter initialize to necklace.begin()

	int L2R,R2L;
	int sum,new_sum=0;
	int left_ptr,right_ptr;
	char temp;
	left_ptr=0;
	right_ptr=N-1-left_ptr;
	L2R=cnt_L2R(necklace.begin(),necklace.end());//count from left end to right
	R2L=cnt_R2L(necklace.end()-1,L2R,N);//count from right end to left
	sum=(N==L2R)?N:L2R+R2L;

	for(i=0;i<N;i++)
	{
		temp=*iter;//point to necklace.begin()
		iter=necklace.erase(iter);//not iter is invalid
		necklace.push_back(temp);
		iter=necklace.begin();//reinitialize iter
		L2R=cnt_L2R(necklace.begin(),necklace.end());//count from left end to right
		R2L=cnt_R2L(necklace.end()-1,L2R,N);//erase the elements counted by L2R and count from right to left
		new_sum=(N==L2R)?N:L2R+R2L;
		if(new_sum>sum)//more same color
		{
			sum=new_sum;
			left_ptr=i+1;
			right_ptr=right_ptr=N-1-left_ptr;
		}

	}

//output
//	fout<<N<<endl;
//	fout<<beads<<endl;
/*
	for(iter=necklace.begin();iter!=necklace.end();iter++)
		fout<<*iter;
	fout<<endl;
	fout<<"break between "<<left_ptr<<" and "<<right_ptr<<endl;
	fout<<"from left end to count "<<L2R<<endl;
	fout<<"from right end to count "<<R2L<<endl;
	fout<<"the sum of the same color are "<<sum<<endl;
*/
	fout<<sum<<endl;
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
	return cnt;
	
}

int cnt_R2L(vector<char>::iterator iter,int L2R,int N)
{
	vector<char> ch;
	vector<char>::iterator ch_iter;
	ch_iter=iter+N;
	int i;
	for(i=0;i<N-L2R;i++,iter--)
	{
		ch.push_back(*iter);
	}
	int cnt=0;
	cnt=cnt_L2R(ch.begin(),ch.end());
/*	char start;
	start=*iter;
	if(start!='w')//start is b or r
	{
		for(cnt=0;iter!=necklace.begin()-1;iter--)
		{
			if(*iter==start||*iter=='w')//++cnt when meet with same color or w
				++cnt;
			else
				return cnt;
		}	

	}
	else//start with w
	{
		while(*iter=='w'&&iter!=(necklace.begin()-1))
		{
			++cnt;
			++iter;
		}
		for(start=*iter;iter!=(necklace.begin()-1);iter--)//here *iter is b or r same as not-w start
		{
			if(*iter==start||*iter=='w')//++cnt when meet with same color or w
				++cnt;
			else
				return cnt;
		}	

	}
	*/
	return cnt;
}
