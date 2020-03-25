#include<iostream>
#include<iomanip>
#define m 7
using namespace std;
struct stack
{
	int top;
	int data[m]	;
};

void Push(stack &a,int x)
{
	if(a.top==m-1)
	{
		cout<<"\n full stack";
		//exit(1);
	}
	else{
		a.data[++a.top]=x;
	}
}
int Pop(stack &a)
{
	if(a.top==-1)
	{
		cout<<"\n Stack empty";
		return -1;
	}
	else
	{
		return a.data[a.top--];
	}
}
void CreateS(stack &a)
{
	int x;
	do{	
		cout<<"\n nhap gia tri x, -1 ket thuc:";
		cin>>x;
		if(x==-1)break;
		Push(a,x);
	}while(1);	
}

void Print(stack a)
{
	while(a.top!=-1)
	{
		cout<<Pop(a);
	}
}
int main()
{
	stack a;
	a.top=-1;
	CreateS(a);

	cout<<"\n danh sach luu tru ngan xep:";
	Print(a);
	return 0;
}