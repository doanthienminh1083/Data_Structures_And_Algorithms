#include<iostream>
using namespace std;

struct Node
{
    int data;
   struct Node *next;
};
 
typedef Node *Nodeptr;
 
Nodeptr CreateNode(int x)
{
	Nodeptr p;
	p=new Node;
	p->data=x;
	p->next=NULL;
	return p;
}
 
Nodeptr addToEmpty(Nodeptr last, int data)
{
    // This function is only for empty list
    if (last != NULL)
      return last;
 
    // Creating a node dynamically.
    Nodeptr temp = CreateNode(data);
           
    // Assigning the data.
    last = temp;
 
    // Creating the link.
    last -> next = last;
 
    return last;
}
 
Nodeptr addBegin(Nodeptr last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    Nodeptr temp = CreateNode(data);
           
    temp -> next = last -> next;
    last -> next = temp;
 
    return last;
}
 
Nodeptr addEnd(Nodeptr last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
     
    Nodeptr temp = CreateNode(data);
 
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
 
    return last;
}
 
Nodeptr addAfter(Nodeptr last, int data, int item)
{
    if (last == NULL)
        return NULL;
 
    Nodeptr temp, p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            Nodeptr temp = CreateNode(data);
            temp -> next = p -> next;
            p -> next = temp;
 
            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);
 
    cout << item << " not present in the list." << endl;
    return last;
 
}
 
void traverse(Nodeptr last)
{
    Nodeptr p;
 
    // If list is empty, return.
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    // Pointing to first Node of the list.
    p = last -> next;
 
    // Traversing the list.
    do
    {
        cout << p -> data << " ";
        p = p -> next;
 
    }while(p != last->next);
 
}
 
// Driven Program
int main()
{
    Nodeptr last = NULL;
 
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);
 
    traverse(last);
 
    return 0;
}