#include<iostream>
using namespace std;
int main()
{
	int number=100;
	int base=3;
	const int size=50;
	int result[size];
	int temp;
	int i=0;
	while(number%base!=0)
	{
		result[i]=number%base;
		number/=base;
		i++;
	}
	result[i]=number/base;
	int length=i;
	while(i>=0)
	{
		cout<<result[i];
	}
	cout<<endl;
	return 0;
}