/*
ID: nathanlrf        
PROG: gift1
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
	test<<"100"<<endl;//try calculate 13th in 1900
	
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	
	const int week_size=7;
	const int month_size=12;
	const start_year=1900;
	int end_year;
	int week[week_size];//week[0]=Monday,week[6]=Sunday
	int _31_day[7];
	int _30_day[4];
	int month[month_size];
	int Feb;
	int N;
	int i;

	fin>>N;
	Feb=leap(N);
	end_year=start_year+N;
	//initialize week[]
	for(i=0;i<week_size;i++)
	{
		week[i]=0;
	}
	for(i=0;i<month_size;i++)
	{
		if(3==i||5==i||8==i||10==i)
			month[i]=30;
		else if(i==1)
			month[i]=leap(N);
		else
			month[i]=31;
	}


//output
	fout<<"from 1900 to "<<end_year<<endl;
	fout<<"there is "<<leap(N)<<"days in feb of "<<end_year<<endl;

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

