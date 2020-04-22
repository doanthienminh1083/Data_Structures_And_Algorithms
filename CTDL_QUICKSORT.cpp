#include<iostream>

using namespace std;
int doicho(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int quicksort(int a[],int left,int right)
{
	int mid=(left+right)/2;
	int x=a[mid];
	int i,j;
	i=left;
	j=right;
	while(i<=j)
	{
		while(a[i]<x)i++;
		while(a[j]>x)j--;
		if(i<=j)
			{
				doicho(a[i],a[j]);
				i++;j--;
			}
	}
	if(left<j)quicksort(a,left,j);
	if(right>i)quicksort(a,i,right);
}
int main()
{
	
	int a[]={
		6,4,3,5,7,1,2
	};
	quicksort(a,0,6);
	for(int i=0;i<7;i++)
		cout<<a[i]<<" \t ";
	return 0;
}