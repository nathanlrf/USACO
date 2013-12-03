/*
ID: nathanlrf	
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

string convert(int number,int base);
int checkpal(string con_num);
string swap(string con_num);

int main()
{
//	ofstream test("palsquare.in");
//	test<<10<<endl;
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	
	const int MAX=300;

	int base;
	fin>>base;
	int i=0;

	for(i=1;i<=MAX;i++)
	{
		int square=i*i;
		if(checkpal(convert(square,base)))
		{
			fout<<convert(i,base)<<" "<<convert(square,base)<<endl;
		}
	}
	
	return 0;
}
//base is 2 to 20
string convert(int number,int base)
{
	char arr[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	const int size=50;
	char result;
	int i=0;
	int reminder;
	string con_num;
	stringstream temp;
	while(number>base)
	{
		reminder=number%base;
		result=arr[reminder];
		temp<<result;
		con_num=temp.str();
		
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

	int length=i;
	string str;
	str=swap(con_num);
//	cout<<con_num<<endl;
	return str;

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