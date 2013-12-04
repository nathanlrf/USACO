/*
ID: nathanlrf	
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string convert(int number,int base);
int checkpal(string con_num);
string swap(string con_num);
int doublepal(int number);

int main()
{
	// ofstream test("dualpal.in");
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	
	// test<<"3"<<" "<<"25"<<endl;
	int N,S;
	fin>>N;
	fin>>S;

	int number;
	int cnt;
	int result;
	for(number=S+1,cnt=0;cnt<N;number++)
	{
		result=doublepal(number);
		if(result)
		{
			fout<<result<<endl;
			++cnt;
		}
	}
	
	
	return 0;
}
//base is 2 to 20
string convert(int number,int base)
{
	char arr[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	char result;
	int reminder;
	string con_num;
	stringstream temp;
	while(number>base)
	{
		reminder=number%base;
		result=arr[reminder];
		temp<<result;
		con_num=temp.str();//the order in con_num is reversed
		
		number/=base;
	}
	if(number<base)
	{
		result=arr[number];
		temp<<result;
		con_num=temp.str();
	}
	else
	{
		result='0';
		temp<<result;
		con_num=temp.str();

		result='1';
		temp<<result;
		con_num=temp.str();
	}

	return swap(con_num);//fix the order in con_num

}
int checkpal(string con_num)
{
	int i=0;
	int length=con_num.length();
	while(i<=length/2)
	{
		if(con_num[i]!=con_num[length-i-1])
		{
			return 0;
		}
		i++;
	}
	return 1;
}
string swap(string con_num)
{
	int i=0;
	char temp;
	int length;
	length=con_num.length();
	while(i<length/2)
	{
		temp=con_num[i];
		con_num[i]=con_num[length-i-1];
		con_num[length-i-1]=temp;
		i++;
	}
	return con_num;
}

int doublepal(int number)
{
	const int base_start=2;
	const int base_end=10;
	const int limit=2;
	int i;
	int cnt=0;
	for(i=base_start;i<=base_end&&cnt<limit;i++)
	{
		if(checkpal(convert(number,i)))
		{
			++cnt;
		}
	}
	if(cnt==limit)
	{
		return number;
	}
	else
	{
		return 0;
	}
}