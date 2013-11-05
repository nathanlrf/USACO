/*
ID: nathanlrf        
PROG: friday
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int leap(int N);

int main()
{ 
	//this is for test
	ofstream test("friday.in");
	test<<"256"<<endl;//try calculate 13th in 1900
	
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	
	const int week_size=7;
	const int month_size=12;
	const int start_year=1900;
	int end_year;
	int week[week_size];//week[0]=Monday,week[6]=Sunday
	int month[month_size];

	int N;//how many years
	int i,j;//array index
	int temp;//calculate the cycle of weeks

	fin>>N;
	end_year=start_year+N;
	//initialize week[]
	for(i=0;i<week_size;i++)
	{
		if(i==5)
			week[i]=1;//jan 13th is sat
		else	
			week[i]=0;
	}
	
	//big loop for N year
	int start=5;//1900 jan 13th is on Saturday 
	for(j=0;j<N;j++)
	{
		if(j>0)
		{
			start=temp+month[i]%7;//i=11; get jan 13th in the next year
			if(start<7)
				start=start;
			else
				start%=7;
			++week[start];
		}

		for(i=0;i<month_size;i++)
		{	
			if(3==i||5==i||8==i||10==i)
				month[i]=30;
			else if(i==1)
				month[i]=leap(j);
			else
				month[i]=31;
		}
		//small loop for 1 year
		//find 13th in each month in 1901
		//1st month is on Sat temp=5;then 31%7=3,temp=5+3=8;then 28%7=0,temp=1;then 31%7=3,temp=1+3=4;then 30%7=2,temp=4+2=6
		for(i=0,temp=start;i<month_size-1;i++)
		{	
			temp+=month[i]%7;
			if(temp<7)
				temp=temp;
			else
				temp%=7;
			++week[temp];
		}
		

	}
	

//output
/*	fout<<"from 1900 to "<<end_year<<endl;
	fout<<"there is "<<leap(N)<<"days in feb of "<<end_year<<endl;
	for(i=0;i<week_size;i++)
	{
		fout<<week[i]<<' ';
	}
	fout<<endl;
*/

	int Sat_to_Fri[week_size];
	for(i=0;i<week_size-1;i++)
	{
		Sat_to_Fri[i]=week[(i+5)%7];
		fout<<Sat_to_Fri[i]<<' ';
	}
	fout<<week[4]<<endl;
	
	return 0;

}
int leap(int N)
{
	int year=1900;
	int feb;
	year+=N;
	if(year%400==0||(year%100!=0&&year%4==0))
		feb=29;
	else
		feb=28;
	return feb;
}

