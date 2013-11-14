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
{/*
	ofstream test("milk2.in");
    test<<4<<endl;
    test<<100<<" "<<200<<endl;
	test<<201<<" "<<301<<endl;
	test<<302<<" "<<402<<endl;
	test<<403<<" "<<503<<endl;
   */     
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

	unsigned int N;//1~5000
	const int size=5000;
	unsigned int farmer[size][2];//1~1000000
	int i=0;
	//result
	unsigned int continous=0,idle=0;

	fin>>N;
	for(i=0;i<N;i++)
	{
		fin>>farmer[i][0];
		fin>>farmer[i][1];
	}

	int j,temp0=0,temp1=0;//插入排序
	for(j=0;j<N;j++)//
		for(i=0;i<N-j-1;i++)//第j趟就比较N-j次，共比较4+3+2+1=10次
			if(farmer[i][0]>farmer[i+1][0])
			{

				temp0=farmer[i][0];
				farmer[i][0]=farmer[i+1][0];
				farmer[i+1][0]=temp0;
				temp1=farmer[i][1];
				farmer[i][1]=farmer[i+1][1];
				farmer[i+1][1]=temp1;
			}



	int con_temp=0,idle_temp=0;
//initialize start to first farmer start time
	int interval[size][2];
	interval[0][0]=farmer[0][0];//start
	interval[0][1]=farmer[0][1];//end
	
//reform the intervals	
	for(i=0,j=0;i<N-1;i++)
	{
		if(N>1)//N must be bigger than 1
		{
			if(interval[j][1]>=farmer[i+1][0])
			{
				interval[j][0]=(farmer[i+1][0]<interval[j][0])?farmer[i+1][0]:interval[j][0];
				interval[j][1]=(farmer[i+1][1]>interval[j][1])?farmer[i+1][1]:interval[j][1];
			//	con_temp=end[j]-start[j];
			}
			else
			{
				++j;//j indicate how many intervals there are 
				interval[j][0]=farmer[i+1][0];
				interval[j][1]=farmer[i+1][1];
			}
		}

	}
	//initializing con_temp and continous to find biggest continous & idle
	con_temp=interval[i][1]-interval[i][0];
	continous=interval[0][1]-interval[0][0];
	idle_temp=(j>1)?(interval[1][0]-interval[0][1]):0;
	idle=0;
	for(i=0;i<=j;i++)
	{
		con_temp=interval[i][1]-interval[i][0];	
		continous=(con_temp>continous)?con_temp:continous;
	}
	for(i=0;i<=j-1;i++)
	{
		idle_temp=interval[i+1][0]-interval[i][1];
		idle=(idle_temp>idle)?idle_temp:idle;
	}
	fout<<continous<<" "<<idle<<endl;

	return 0;
}