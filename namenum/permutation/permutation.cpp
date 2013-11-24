#include<iostream>

void method2(int *a);
void arrangement(int *a,int start,int end,int N);

using namespace std;

int main()
{
	int a[]={1,2,3,4};
	method2(a);
	return 0;
}
void method2(int *a)//not effective when a[] is a large array

{
	int count=0;

	for(int k=0;k<4;k++)

	{
		if(k!=0)
		{
			swap(a[0],a[k]);
		}
		for(int j=1;j<4;j++)
		{
			if(j!=1)
			{
				swap(a[1],a[j]);

            }
			for(int s=2;s<4;s++)
			{
				if(s!=2)
				{
					swap(a[2],a[s]);
				}
				std::cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<endl;
                count++;
                if(s!=2)
				{
					swap(a[2],a[s]);
                }

            } 
			if(j!=1)
			{
				swap(a[1],a[j]);
			}
        }	
        if(k!=0)
        {
            swap(a[0],a[k]);

        }
    }

    std::cout<<count<<endl;

}

void arrangement(int *a,int start,int end,int N)//use recursion to deal with large N

{
             if(start==end)
                {

                           for(int i=0;i<N;++i)

                           std::cout<<a[i]<<" ";

                           std::cout<<endl;

                         

                      return;

                  }

          for(int i=start;i<=end;++i)

        {
                  if(i!=start)                  
                     swap(a[start],a[i]);                 
                  arrangement(a,start+1,end,N);
                  if(i!=start)
                     swap(a[start],a[i]);

        }
}