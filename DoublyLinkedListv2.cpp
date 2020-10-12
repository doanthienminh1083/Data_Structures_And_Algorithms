#include<iostream>
#include<iomanip>

using namespace std;


typedef struct Node
{
	int Data;
	Node *Next;
	Node *Prev;
}Nodetype;

typedef Nodetype *Nodeptr;

Nodeptr CreateNode(int x)
{
	Nodeptr p;
	//p=(Nodeptr)malloc(sizeof(Nodetype));
	p=new Node;
	p->Data=x;
	p->Prev=NULL;
	p->Next=NULL;
	return p;
}
Nodeptr p=CreateNode(123);

void InsertFirst(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
{
	if(Head==NULL)Head=Tail=p;
	else
	{
		p->Next=Head;
		Head->Prev=p;
		Head=p;
	}
}
void InsertLast(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
{
	if(Head==NULL)Head=Tail=p;
	else
	{
		Tail->Next=p;
		p->Prev=Tail;
		Tail=p;
	}
}
void InsertBefore(Nodeptr &Head,Nodeptr &Tail,Nodeptr q,Nodeptr p)
{
 	Nodeptr fnode ;//First Node
	if (q != NULL)
	{
		fnode = q->Prev;
		p->Prev = fnode;
		p->Next = q;
		q->Prev= p; 
		if (fnode != NULL)
			fnode->Next=p ;
		if (q == Head)
			Head=p;
	}
}
void InsertAfter(Nodeptr &Head,Nodeptr &Tail,Nodeptr q,Nodeptr p)
{
	Nodeptr anode = q->Next;
	if (q != NULL)
	{
		p->Next = anode;//1
		p->Prev = q;//2
		q->Next = p;//3
		if (anode != NULL)
			anode->Prev = p;//4
		if (q == Tail)
			Tail = p;//5
	}
}

void DelFirst(Nodeptr &Head, Nodeptr &Tail)
{
	Nodeptr p;	
	if(Head==NULL)
		cout<<"\n Linked List Empty";
	else
	if(Head->Next==NULL)
	{
		p=Head;
		Head=p->Next;
		p->Next=NULL;
		Head=Tail=NULL;
		free(p);
	}
	else
	{
		p=Head;
		Head=p->Next;
		p->Next=NULL;
		Head->Prev=NULL;
		free(p);
	}
}
void DelLast(Nodeptr &Head, Nodeptr &Tail)
{
	Nodeptr p;
	if(Head==NULL) // danh sach rong
		cout<<"\n linked list empty";	
	else
	{
		p=Tail;
		if(p==Head) // danh sach co 1 nut
		{
				Head=Tail=NULL;
				free(p);
		}
		else		// danh sach nhieu hon 1 nut
		{
			Tail=Tail->Prev;
			Tail->Next=NULL;
			p->Prev=NULL;
			free(p);
		}
	}
}
void CreateList(Nodeptr &Head,Nodeptr &Tail)
{
	int x;
	Nodeptr p;
	while(1)
	{
		cout<<"\n nhap x, nhap -1 ket thuc: ";
		cin>>x;
		if(x==-1)break;
		p=CreateNode(x);
		InsertLast(Head,Tail,p);
	}
}

void Print(Nodeptr Head,Nodeptr Tail)
{
	while(Head!=NULL)
	{
		cout<<setw(5)<<Head->Data;
		Head=Head->Next;
	}
}


int main()
{
	Nodeptr Head,Tail;
	Head=NULL;
	Tail=NULL;

	int chon;
	do{
		
		cout<<"\n 1. Nhap danh sach ";
		cout<<"\n 2. Xuat danh sach: ";
		cout<<"\n 3. Xoa node dau xau:";
		cout<<"\n 4. Xoa Node cuoi xau:";
		cout<<"\n Ban chon: ";
		cin>>chon;
		switch(chon)
		{
			case 1:	
					Head=NULL;
					Tail=NULL;
					CreateList(Head,Tail);
					break;
			case 2: cout<<"\n danh sach vua nhap:";
					Print(Head,Tail);
					break;
			case 3: 
					cout<<"\n Danh sach sau khi xoa dau:";
					DelFirst(Head,Tail);
					Print(Head,Tail);
					break;
			case 4: 
					cout<<"\n Danh sach sau khi xoa cuoi:";
					DelLast(Head,Tail);
					Print(Head,Tail);
					break;
		}
	}while(chon!=5);
	
}