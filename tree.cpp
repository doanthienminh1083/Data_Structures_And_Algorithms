#include<iostream>
#include<iomanip>
using namespace std;

typedef struct Node
{
	int data;
	Node *Left;
	Node *Right;
}Nodetype;

typedef Nodetype *Nodeptr;

Nodeptr CreateNode(int x)
{
	Nodeptr p;
	p=(Nodeptr)malloc(sizeof(Nodetype));
	p->data=x;
	p->Left=NULL;
	p->Right=NULL;
	return p;
}
void insert(Nodeptr &Root,Nodeptr p)
{
	if(Root==NULL)Root=p;
	else
	{
		if(Root->data>p->data)
			insert(Root->Left,p);
		else if(Root->data<p->data)
			insert(Root->Right,p);
		else
			cout<<"\n Gia tri da co trong cay, Nhap gia tri khac";
	}
}
void LNR(Nodeptr Root)
{
	if(Root!=NULL)
	{
		LNR(Root->Left);
		cout<<setw(5)<<Root->data;
		LNR(Root->Right);
	}
}
void NLR(Nodeptr Root)
{
	if(Root!=NULL)
	{
		cout<<setw(5)<<Root->data;
		LNR(Root->Left);
		LNR(Root->Right);
	}
}
void LRN(Nodeptr Root)
{
	if(Root!=NULL)
	{
		LNR(Root->Left);
		LNR(Root->Right);
		cout<<setw(5)<<Root->data;		
	}
}

void SearchStandfor(Nodeptr &Root)
{
	Nodeptr p,q;
	p=Root->Left;
	while(p->Right!=NULL)
	{
		q=p;
		p=q->Right;
	}
	
	Root->data=p->data;
	q->Right=p->Left;
	free(p);
}
void Deltree(Nodeptr &Root,int x)
{
	Nodeptr p;
	if(Root!=NULL)
	{
		if(Root->data>x) Deltree(Root->Left,x);
		else if(Root->data<x)Deltree(Root->Right,x);
		else{
			if(Root->Left==NULL && Root->Right==NULL)
			{
				free(Root);Root=NULL;
			}	
			else if(Root->Left!=NULL && Root->Right==NULL)
			{
				p=Root;
				Root=Root->Left;
				free(p);
			}
			else if(Root->Left==NULL && Root->Right!=NULL)
			{
				p=Root;
				Root=Root->Right;
				free(p);
			}
			else SearchStandfor(Root);
		}
	}
}
int main()
{
	Nodeptr Root;
	Root=NULL;
	Nodeptr p;
	int chon;
	int x;
	do{
		system("CLS");
		cout<<"\n 1.Nhap cay nhi phan:";
		cout<<"\n 2. Duyet cay nhi phan:";
		cout<<"\n 3. Xoa nhanh trai";

		cout<<"\n Ban chon:";cin>>chon;
		switch(chon)
		{
			case 1:{
					Root=NULL;
					cout<<"\n Nhap cac gia tri cho cay nhi phan:";
					do{
						cout<<"\n nhap gia tri, nhap -1 ket thuc:";
						cin>>x;
						if(x==-1)
							break;
						p=CreateNode(x);
						insert(Root,p);
						}while(1);
					}break;
			case 2:
					{
						cout<<"\n cac gia tri trong cay: "<<endl;
						LNR(Root);
						system("pause");
					}break;
			case 3:
					{
						cout<<"\n xoa nhanh:";
						int x;
						cout<<"\n nhap gia tri can xoa:";
						cin>>x;
						Deltree(Root,x);
					}
		}
	}while(chon!=5);

}