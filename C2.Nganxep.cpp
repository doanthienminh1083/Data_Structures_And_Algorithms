#include<iostream>
#define m 4
using namespace std;
// dinh nghia kieu cau truc luu tru stack
struct Stack
{
	int top;// co hieu cho biet ngan xep rong, day
	int Data[m];// du lieu can luu
};

void Push(Stack &s,int x)
{
	if(s.top==m-1)
	{
		cout<<"\n ngan xep day";
		//exit(1);
	}
	else
	{
		s.top++; // chi so cua data
		s.Data[s.top]=x;
	}
}

int Pop(Stack &s)
{
	int x;
	if(s.top==-1)
	{
		//cout<<"\n ngan xep rong";
		return -1;
	}
	else //return s.Data[s.top--];
	{
		x=s.Data[s.top];
		s.top=s.top-1;
		return x;
	}
		
}
void Print(Stack s)
{
	int t=Pop(s);
	while(t!=-1)
	{
		cout<<t<<"\t";
		t=Pop(s);
	}
}
void Init(Stack &s)
{
	s.top=-1;
	//for(int i=0;i<m;i++)
	//	s.data[i]=-1;
}
int main()
{
	Stack s;
	s.top=-1;// khoi tao ngan xep rong
	Push(s,11);
	Push(s,12);
	Push(s,13);
	Push(s,14);
	Push(s,15);
	
	cout<<"\n Cac gia tri trong ngan xep ";
	Print(s);
	return 0;	
}