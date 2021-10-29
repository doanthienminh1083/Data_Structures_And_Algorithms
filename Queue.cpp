#include<iostream>
#define m 10
using namespace std;

struct Queue
{
	int Head,Tail;
	int Data[m];
};

void Push(Queue &q,int x)
{
	int vt;
	vt=(q.Tail+1)%m;
	if(vt==q.Head)
	{
		cout<<"\n Queue Full";
		exit(1);
	}
	else
	{
		q.Data[vt]=x;
		q.Tail=vt;
	}
}

int IsEmpty(Queue &q)
{
	return (q.Head==q.Tail?1:0);
}
int Pop(Queue &q)
{
	
	int vt;
	int iteam;
	while(!IsEmpty(q))
	{
		vt=(q.Head+1)%m;
		iteam=q.Data[vt];
		q.Head=vt;
		return iteam;
	}
	return -1;
}
void Init(Queue &q)
{
	q.Head=q.Tail=0;
}
void Input(Queue &q)
{

	int x;
	while(1)
	{
		cout<<"\n nhap gia tri x, nhap x=-1 ket thuc:";
		cin>>x;
		if(x==-1)break;
		Push(q,x);
	}
}
void Print(Queue &q)
{
	int t=-1;
	t=Pop(q);
	while(t!=-1)
	{
		cout<<t;
		t=Pop(q);
	}
}

int main()
{
	Queue q;
	Init(q);
	Input(q);
	cout<<"\n cac phan tu trong Queue: ";
	Print(q);
	
	return 0;
}