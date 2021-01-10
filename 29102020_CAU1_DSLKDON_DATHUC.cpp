#include<iostream>
#include<math.h>
using namespace std;

typedef struct
{
   int heso,bac;
}hangtu;

typedef struct Node
{
  hangtu data;
  struct Node *Next;
}Nodetype;

typedef Nodetype *nodeptr;

nodeptr CreateNode(hangtu x)
{
  nodeptr p;
//  p=(nodeptr)malloc(sizeof(Nodetype));
	p=new Node;
  	p->data=x;
  	p->Next=NULL;
  	return p;
}

void InsertLast(nodeptr &Head,nodeptr &Tail,nodeptr p)
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
void Nhapdt(nodeptr &Head,nodeptr &Tail)
{
  nodeptr p;
  Head=NULL;
  int bac=-1;
  int dem=0;
  hangtu x;
  do{
	   
		cout<<"\n Nhap hang tu thu "<<dem++;
		cout<<"\n Nhap bac, nhap bac=-1 ket thuc:";
		cin>>x.bac;
		if(x.bac==-1) break;
		if(bac==-1)
		{
		 cout<<"\n He so: ";
		 cin>>x.heso;
		}
		else
		{
			while(x.bac>=bac)
			{
 				cout<<"\n Nhap lai bac:";
				cin>>x.bac;
				if(x.bac==-1) break;
			}
			if(x.bac!=-1)
			{
				cout<<"\n He so: ";
		 		cin>>x.heso;
			}
			else break;
		}
		p=CreateNode(x);
		InsertLast(Head,Tail,p);
		bac=x.bac;
	 }while(1);
}
void Indt(nodeptr Head,nodeptr Tail)
{
  nodeptr p=Head;

  while(p!=NULL)
  {
	if(p->data.heso>0)
		cout<<"+"<<p->data.heso<<"X"<<p->data.bac;
	else
		if(p->data.heso<0)
			cout<<p->data.heso<<"X"<<p->data.bac;;
	p=p->Next;
  }
}
double sum(nodeptr Head,nodeptr Tail,int x)
{
  double tong=0;
  nodeptr p;
  p=Head;
  while(p!=NULL)
  {
	tong+=p->data.heso*pow(x,(double)p->data.bac);
	p=p->Next;
  }
  return tong;
}

double daoham(nodeptr &Head,nodeptr &Tail)
{
 nodeptr p,q;
 q=p=Head;
 while(p!=NULL)
 {
   if(p->data.bac>=0)
   {
	 p->data.heso*=p->data.bac;
	 p->data.bac--;
	 if(p->data.bac==-1 && p==q)
	 {
		//free(p);
		delete p;
		Head==NULL;
		return 0;
	 }
	 else if(p->data.bac==-1)
	 {
		//free(p);
		delete p;
		return 1;
	 }
   }
	 q=p;
	 p=p->Next;

 }
 return 1;
}
int main()
{
  nodeptr Head,Tail,k,q,kq;
  int chon;
  do{
		cout<<"\n Chuong trinh minh hoa xau lien ket ";
		cout<<"\n 1.Nhap da thuc ";
		cout<<"\n 2.In da thuc";
		cout<<"\n 3.Nhap x va tinh gia tri da thuc: ";
		cout<<"\n 4.Tinh dao ham: ";
		cout<<"\n 5.Thoat";
		cout<<"\n Ban chon:";
		cin>>chon;
		switch(chon)
		{
		  case 1:Nhapdt(Head,Tail);break;
		  case 2:Indt(Head,Tail);break;
		  case 3:
				 {
	 				 int x;
					 cout<<"\n Nhap x de tinh P(x): ";
					 cin>>x;
					 cout<<"\n Tong la: "<<sum(Head,Tail,x);	
					}
				 break;
	 	  case 4:
	 	  	    	double x=daoham(Head,Tail);
				 if(x==0) cout<<"\n Da thuc px bang 0 "<<endl;
				 else
				  Indt(Head,Tail);break;
		} 
	  }while(chon!=5);
}

