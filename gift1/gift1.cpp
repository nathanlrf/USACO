/*
ID: nathanlrf        
PROG: gift1
LANG: C++
*/

/*
relate name with their money:name are stored in group_mem[i],use index i to find an element in money[i]
print the same i in group_mem and money thus they are binded
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include <sstream> 
using namespace std;

int str2int(string rec_num);
int index(string name,string* arr_ptr,int NP);

int main()
{
        //this is for test
        ofstream test("gift1.in");
        test<<"5"<<endl;
        test<<"dave"<<endl;
        test<<"laura"<<endl;
        test<<"owen"<<endl;
        test<<"vick"<<endl;
        test<<"amr"<<endl;
        test<<"dave"<<endl;
        test<<"200 3"<<endl;
        test<<"laura"<<endl;
        test<<"owen"<<endl;
        test<<"vick"<<endl;
        test<<"owen"<<endl;
        test<<"500 1"<<endl;
        test<<"dave"<<endl;
        test<<"amr"<<endl;
        test<<"150 2"<<endl;
        test<<"vick"<<endl;
        test<<"owen"<<endl;
        test<<"laura"<<endl;
        test<<"0 2"<<endl;
        test<<"amr"<<endl;
        test<<"vick"<<endl;
        test<<"vick"<<endl;
        test<<"0 0"<<endl;
        //comment section above when submit

        ifstream fin("gift1.in");
        ofstream fout("gift1.out");
        const int size=20;
        int NP;
        string group_mem[size];
        int i;
		stringstream ss1,ss2;

        fin>>NP;
        for(i=0;i<NP;i++)
        {
                fin>>group_mem[i];
        }

        fout<<NP<<endl;
		for(i=0;i<NP;i++)
        {
                fout<<group_mem[i]<<endl;
        }
		
		string money,rec_num;
		int j;
		string giver;
		string rec;
		int money_int,rec_num_int;
		
		
	//	while(fin)
	//	{
			fin>>giver;
		
			fin>>money;//money to give
			money_int=str2int(money);
			fin>>rec_num;//number of receivers
			rec_num_int=str2int(rec_num);
			
	//		for(j=0;j<rec_num_int;j++)
	//		{
	//			fin>>rec;//store receivers' name in rec
	//		}
			fout<<"giver is "<<giver<<endl;
			fout<<giver<<"'s index is "<<index(giver,group_mem,NP)<<endl;
			//fout<<money<<endl;
			fout<<money_int<<endl;
			//fout<<rec_num<<endl;
			fout<<rec_num_int<<endl;
		
	//	}
		return 0;
		

}
int str2int(string str)
{
	int integer;
	stringstream ss;
	ss<<str;
	ss>>integer;
	return integer;
}
int index(string name,string* arr_ptr,int NP)//find index of a given name, error return 111
{
	int i;
	for(i=0;i<NP;i++)
	{
		if(arr_ptr[i]==name)
			return i;
		else
			return 111;
	}
}