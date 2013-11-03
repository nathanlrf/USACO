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
	/*
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
*/
        ifstream fin("gift1.in");
        ofstream fout("gift1.out");
        const int size=15;
        int NP=0;
        string group_mem[size];
		int mem_money[size];
        int i=0;

        fin>>NP;

        for(i=0;i<NP;i++)//read group from gift1.in
        {
                fin>>group_mem[i];
				mem_money[i]=0;//initialize mem_money to 0
        }

 /*		display NP to file
		fout<<NP<<endl;
		for(i=0;i<NP;i++)
        {
                fout<<group_mem[i]<<endl;
        }
*/		
		string money,rec_num;
		int money_int=0,rec_num_int=0;

		int j=0,temp=0;//array index

		string giver;
		string rec[size];//receivers
		

		while(fin)
		{
			fin>>giver;
		
			fin>>money;//money to give
			money_int=str2int(money);
			fin>>rec_num;//number of receivers
			rec_num_int=str2int(rec_num);
			
			//warning: if rec_num_int=0 error will occur with %
			if(rec_num_int)
				mem_money[index(giver,group_mem,NP)]+=money_int%rec_num_int-money_int;//giver money=left-give+money
			else
				mem_money[index(giver,group_mem,NP)]=mem_money[index(giver,group_mem,NP)];
			
			for(j=0;j<rec_num_int;j++)
			{
				fin>>rec[j];//store receivers' name in rec
				temp=index(rec[j],group_mem,NP);//find this receiver
				//warning: if rec_num_int=0 error will occur with %
				if(rec_num_int)
					mem_money[temp]+=money_int/rec_num_int;//giver money=left-give+money
				else
					mem_money[temp]=mem_money[index(giver,group_mem,NP)];//receiver money=give+money
			}
		}
//output
		/*
			fout<<"giver is "<<giver<<endl;
			fout<<giver<<"'s index is "<<index(giver,group_mem,NP)<<endl;
			fout<<"receivers are"<<endl;
			for(j=0;j<rec_num_int;j++)
			{
				temp=index(rec[j],group_mem,NP);
				fout<<rec[j]<<'\t'<<"index is "<<temp<<endl;//store receivers' name in rec
			}
			
			//fout<<money<<endl;
			fout<<money_int<<endl;
			//fout<<rec_num<<endl;
			fout<<rec_num_int<<endl;
			fout<<giver<<"'s money is "<<mem_money[index(giver,group_mem,NP)]<<endl;
			fout<<"receiver's money"<<endl;
			for(j=0;j<rec_num_int;j++)
			{
				fout<<rec[j]<<'\t'<<mem_money[index(rec[j],group_mem,NP)]<<endl;//store receivers' name in rec
			}
		*/
	for(j=0;j<NP;j++)
		{
			fout<<group_mem[j]<<" "<<mem_money[j]<<endl;
		
		}
		
		return 0;
		

}

int str2int(string str)//string number to integer
{
	int integer;
	stringstream ss;
	ss<<str;
	ss>>integer;
	return integer;
}

int index(string name,string* arr_ptr,int NP)//find index of a given name, error return 111
{
	int i,mem_num;
	mem_num=111;
	for(i=0;i<NP;i++)
	{
		if(arr_ptr[i]==name)
			mem_num=i;
	}
	return mem_num;
}