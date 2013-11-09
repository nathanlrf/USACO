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
    test<<4<<endl;
    test<<100<<" "<<200<<endl;
	test<<201<<" "<<301<<endl;
	test<<302<<" "<<402<<endl;
	test<<403<<" "<<503<<endl;
        
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

	int con_temp=0,idle_temp=0,start,end;
//initialize start to first farmer start time
	start=farmer[0][0];
	end=farmer[0][1];
	continous=end-start;
	
	for(i=0;i<N;i++)
	{
		if(N>1)//N must be bigger than 1
		{
			if(farmer[i][1]>=farmer[i+1][0])
			{
				end=farmer[i+1][1];
				con_temp=end-start;
			}
			else
			{
				start=farmer[i+1][0];
				idle_temp=start-farmer[i][1];
			}
			continous=(con_temp>continous)?con_temp:continous;
			idle=(idle_temp>idle)?idle_temp:idle;
		}

	}
/* v 1.0:	wrong when N=4
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
*/
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