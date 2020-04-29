
#include<iostream>
using namespace std;
int a[10];
int n;
void print()
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";

}
void Try(int i)
{
	if(i>=n)
		print();
	else
	{
		for(int j=0;j<2;j++)
		{
			a[i]=j;
			Try(i+1);

		}
	}
	
}
int main()
{
	//phuog phap de quy quay lui la thu -sai
	
	n=3;
	Try(0);
	
	return 0;
}