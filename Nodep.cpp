#include<iostream>
#include<iomanip>
using namespace std;

typedef struct Node
{
	int data;
	Node *Next;
}Nodetype;
typedef Nodetype *Nodeptr;
Nodeptr CreateNode(int x)
{
	
	Nodeptr p;
	p=(Nodeptr)malloc(sizeof(Nodetype));
	p->data=x;
	p->Next=NULL;
	return p;
}

void InsertFirst(Nodeptr &Head, Nodeptr &Tail,Nodeptr p)
{
	if(Head==NULL)
	{
		Head=p;
		Tail=p;
	}
	else
	{
		p->Next=Head;
		Head=p;
	}
}
void InsertLast(Nodeptr &Head, Nodeptr &Tail,Nodeptr p)
{
	if(Head==NULL)
	{
		Head=p;
		Tail=p;
	}
	else
	{
		Tail->Next=p;
		Tail=p;
	}
}
void InsertListOrder(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
{
	Nodeptr a,b;
	a=Head;
	if(Head==NULL)
	{
		Head=p;
		Tail=p;
	}
	else
	{
		while(a!=NULL)
		{
			if(a->data>=p->data)break;
			b=a;
			a=b->Next;		
		}
		if(a==Head) //InsertFirst(Head,Tail,p);
		{
			p->Next=a;
			Head=p;
		}
		else
		{
			p->Next=b->Next;
			b->Next=p;
		}
	}
	
}
void Print(Nodeptr Head,Nodeptr Tail)
{
	Nodeptr p=Head;
	while(p!=NULL)
	{
		cout<<setw(5)<<p->data;
		p=p->Next;
	}
}
void CreateList(Nodeptr &Head, Nodeptr &Tail)
{
	int x=0;
	Nodeptr p;
	
	while(1)
	{
		cout<<"\n nhap gia tri x khac -1: ";
		cin>>x;
		if(x==-1)break;
		p=CreateNode(x);
		//InsertFirst(Head,Tail,p);
		//InsertLast(Head,Tail,p);
		InsertListOrder(Head,Tail,p);
	
	}
	
}
void DelFirst(Nodeptr &Head, Nodeptr &Tail)
{
	Nodeptr p;
	if(Head!=NULL)
	{
		p=Head;
		Head=Head->Next;
		free(p);
	}
}
void DelLast(Nodeptr &Head, Nodeptr &Tail)
{
	Nodeptr a,b;
	a=Head;
	while(a->Next!=NULL)
	{
		b=a;
		a=b->Next;
	}
	//if(a==Tail)
	if(Head==a)
	{
		free(a);
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		b->Next=NULL;
		Tail=b;
	}
}
int main()
{
	Nodeptr Head,Tail;
	Head=NULL;
	CreateList(Head,Tail);
	Print(Head,Tail);
	/*
	cout<<"\n xoa nut dau xau: ";
	DelFirst(Head,Tail);
	Print(Head,Tail);
	*/
	/*
	cout<<"\n xoa tat ca nut trong xau: ";
	while(Head!=NULL)
		DelFirst(Head,Tail);
		Print(Head,Tail);
		*/
		
	cout<<"\n xoa nut cuoi xau: ";
	DelLast(Head,Tail);
	Print(Head,Tail);
}