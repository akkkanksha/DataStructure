#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node * next = NULL;
};
void printlist(node * head)
{
  node *curr=head;
  while(curr!=NULL)
  {
        cout<<curr->data<<" ";
        curr= curr->next;
  }
  cout<<"\n";
}
int listsize(node * head)
{   node *curr = head;
    int size=0;
    while(curr->next!=NULL) 
    {
        curr=curr->next;
        size++;
    }
    return size;
}
node * delete_pos(node * head)
{   int pos;
    cout<<"enter the position you want to delete";
    cin>>pos;
    node * curr=head;
    node * temp;
    if(pos==1)
    {
        temp = head;
        head =head->next;
        delete temp;
    }
    else
    {
        for(int i=1;i<pos;i++) curr=curr->next;
        temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
    }
    return head;
}
int main()
{
    cout<<"Enter values for linked-list ";
    node * head= new node;
    node * curr= head;
    for(int i=0;i<5;i++)
    {   
        cin>>curr->data;
        curr->next=new node;
        curr=curr->next;
    }
    cin>>curr->data;
    head=delete_pos(head);
    printlist(head);
return 0;
}