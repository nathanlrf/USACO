/*
ID:nathanlrf
LANG:C++
TASK:milk2
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;


int main()
{
	ofstream test("milk2.in");
    test<<1<<endl;
    test<<100<<" "<<200<<endl;
//	test<<700<<" "<<1200<<endl;
//	test<<1500<<" "<<2100<<endl;
        
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

	int N;//1~5000
	const int size=5000;
	unsigned int farmer[size][2];//1~1000000
	int i=0;
	//result
	int continous=0,idle=0;

	fin>>N;
	for(i=0;i<N;i++)
	{
		fin>>farmer[i][0];
		fin>>farmer[i][1];
	}
	i=0;//reinitialize i
	int con_temp,idle_temp,start,end;
	start=farmer[0][0];//initialize start to first farmer start time
	while(i<N)
	{
		//interval=farmer[i+1][0]-farmer[i][0];//time diffrence in start time
		if(N==1)
		{
			continous=farmer[i][1]-farmer[i][0];
			idle=0;
			break;
		}
		else
		{
			if(farmer[i][1]>=farmer[i+1][0])//at least one cow is milking
			{
				end=farmer[i+1][1];
				con_temp=end-start;
			}
			else//no milking
			{
				start=farmer[i+1][0];//start at next farmer
				idle_temp=farmer[i+1][0]-farmer[i][1];
			}
			if(con_temp>continous)
				continous=con_temp;
			if(idle_temp>idle)
				idle=idle_temp;
			++i;
		}
		
	}

//output
//	fout<<N<<endl;
/*	for(i=0;i<N;i++)
	{
		fout<<farmer[i][0]<<endl;
		fout<<farmer[i][1]<<endl;
	}
*/
	fout<<continous<<" "<<idle<<endl;

	return 0;
}