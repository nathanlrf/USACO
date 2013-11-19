/*
ID:nathanlrf
LANG:C++
TASK:transform
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int size=10;

void clkwise_90(string* ptr,int N,int later[][size]);//90
void clkwise_180(string* ptr,int N,int later[][size]);//180
void clkwise_270(string* ptr,int N,int later[][size]);//270
void reflection(string* ptr,int N,int later[][size]);//reflect
void ref_clk_90(string* ptr,int N,int later[][size]);
void ref_clk_180(string* ptr,int N,int later[][size]);
void ref_clk_270(string* ptr,int N,int later[][size]);
int compare(string* ptr,int N,int later[][size]);//cmp

int main()
{
	ifstream fin("transform.in");
    ofstream fout("transform.out");

	int N;//1<=N<=10

	int later[size][size];
	fin>>N;
	string before[size],after[size];
	int i,j;
	for(i=0;i<N;i++)
	{
		fin>>before[i];
	}
	for(i=0;i<N;i++)
	{
		fin>>after[i];
	}
//	clkwise_90(before,N,later);
//	clkwise_180(later,N,later);
	int result=compare(after,N,later);
//	cout<<later[2][2]<<endl;
//	cout<<result<<endl;

	i=0;
	while(!result&&(i<7))
	{
		++i;
		switch(i)
		{
		case 1:
			clkwise_90(before,N,later);
			result=compare(after,N,later);
			break;
		case 2:
			clkwise_180(before,N,later);
			result=compare(after,N,later);
			break;
		case 3:
			clkwise_270(before,N,later);
			result=compare(after,N,later);
			break;
		case 4:
			reflection(before,N,later);
			result=compare(after,N,later);
			break;
		case 5:
			j=1;
			ref_clk_90(before,N,later);
			result=compare(after,N,later);
			if(!result&&(j==1))
			{
				++j;
				ref_clk_180(before,N,later);
				result=compare(after,N,later);
			}
			if(!result&&(j==2))
			{
				++j;
				ref_clk_270(before,N,later);
				result=compare(after,N,later);

			}
			break;
		case 6:
			result=compare(after,N,later);
			break;
		default:
			break;
	
		}
		

	}

	//output
//	for(i=0;i<N;i++)
//	{
//		fout<<after[i]<<endl;
//	}
/*
	fout<<"transformed :"<<endl;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			fout<<later[i][j];
		}
		fout<<endl;
	}
	*/
	fout<<i<<endl;
	return 0;
}

//no.1
//first transform row to column then column to row,each needs to be done twice
void clkwise_90(string* ptr,int N,int later[][size])
{
	string temp;
	string::iterator iter;
	const int size=10;
	int i,j;
	//row to column
	//row[0][i]=col[i][N-1];
	for(i=0;i<N;i++)
	{
		temp=ptr[i];
		for(iter=temp.begin(),j=0;iter!=temp.end();j++,iter++)
		{
			later[j][N-1-i]=*iter;
		}
	}

}
//no.2
void clkwise_180(string* ptr,int N,int later[][size])
{
	string temp;
	string::iterator iter;
	const int size=10;
	int i,j;
	//row to column
	//row[0][i]=col[i][N-1];
	for(i=0;i<N;i++)
	{
		temp=ptr[i];
		for(iter=temp.begin(),j=0;iter!=temp.end();j++,iter++)
		{
			later[N-1-i][N-1-j]=*iter;
		}
	}

}
//no.3
void clkwise_270(string* ptr,int N,int later[][size])
{
	string temp;
	string::iterator iter;
	const int size=10;
	int i,j;
	//row to column
	//row[0][i]=col[i][N-1];
	for(i=0;i<N;i++)
	{
		temp=ptr[i];
		for(iter=temp.begin(),j=0;iter!=temp.end();j++,iter++)
		{
			later[N-1-j][i]=*iter;
		}
	}

}
//no.4
void reflection(string* ptr,int N,int later[][size])
{
	string temp;
	string::iterator iter;
	const int size=10;
	int i,j;

	for(i=0;i<N;i++)
	{
		temp=ptr[i];
		for(iter=temp.begin(),j=0;iter!=temp.end();j++,iter++)
		{
			later[i][N-1-j]=*iter;
		}
	}
}
//no.5 combination
void ref_clk_90(string* ptr,int N,int later[][size])
{
	string temp;
	string::iterator iter;
	const int size=10;
	int refed[size][size];
	int i,j;
	//do reflection first
	for(i=0;i<N;i++)
	{
		temp=ptr[i];
		for(iter=temp.begin(),j=0;iter!=temp.end();j++,iter++)
		{
			refed[i][N-1-j]=*iter;
		}
	}
	//clkwise_90
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			later[j][N-1-i]=refed[i][j];
		}
	}


}
void ref_clk_180(string* ptr,int N,int later[][size])
{
	string temp;
	string::iterator iter;
	const int size=10;
	int refed[size][size];
	int i,j;
	//do reflection first
	for(i=0;i<N;i++)
	{
		temp=ptr[i];
		for(iter=temp.begin(),j=0;iter!=temp.end();j++,iter++)
		{
			refed[i][N-1-j]=*iter;
		}
	}
	//clkwise_180
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			later[N-1-i][N-1-j]=refed[i][j];
		}
	}

}
void ref_clk_270(string* ptr,int N,int later[][size])
{
	string temp;
	string::iterator iter;
	const int size=10;
	int refed[size][size];
	int i,j;
	//do reflection first
	for(i=0;i<N;i++)
	{
		temp=ptr[i];
		for(iter=temp.begin(),j=0;iter!=temp.end();j++,iter++)
		{
			refed[i][N-1-j]=*iter;
		}
	}
	//clkwise_270
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			later[N-1-j][i]=refed[i][j];
		}
	}

}
//no.6 do nothing
//no.7 cannot be done with methods above
//compare later and after
int compare(string* ptr,int N,int later[][size])
{
	int i,j;
	string::iterator iter;
	int same=0;//if after=later,same=1
	
	for(i=0;i<N;i++)
	{
		for(j=0,iter=ptr[i].begin();j<N;j++,iter++)
		{
			if(*iter!=later[i][j])
				return same;
		}

	}
	same=1;
	return same;
}
