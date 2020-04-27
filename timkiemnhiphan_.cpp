#include<iostream>

using namespace std;
int timkiem(int a[],int n,int x)
{
	int left=0;
	int right=n-1;
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]<x) left=mid+1;
		else if(a[mid]>x)right=mid-1;
		else if (a[mid]==x)return mid;
		if(left>right)return -1;	
	}
	return -1;
}
int main()
{
	int a[]	={
		11,12,13,15,17
	};
	int x=1;
	cout<<"\n giai thuat tim kiem nhi phan: ";
	cout<<timkiem(a,5,x);
	return 0;
}