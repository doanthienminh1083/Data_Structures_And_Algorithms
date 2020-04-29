
#include<iostream>
using namespace std;
int a[10];
int b[10];
int n;
void init()
{
	for(int i=0;i<n;i++)
		b[i]=0;
}
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
		for(int j=1;j<=3;j++) // tap kha nang lua chon
		{
			if(b[j]==0)
			{
				a[i]=j;//chon kha nag
				b[j]=1;// danh dau kha nang da lua chon
				Try(i+1);// de quy de lua chon kha nang cho vi tri ke tiep
				b[j]=0; //sau khi lua chon xong in du 1 cau hinh thi bo danh dau
			}

		}
	}
	
}
int main()
{
	//phuog phap de quy quay lui la thu -sai
	
	n=3;
	init();
	Try(0);
	
	return 0;
}