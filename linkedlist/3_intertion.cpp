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
void insertbeg(node **head_ref) // refernce for head
{
    node * temp = new node;
    int val;
    cout<<"enter value to insert at begining ";
    cin>>val;
    temp->data =val;
    temp->next=*head_ref;
    *head_ref=temp;
}
void insertend(node ** head_ref) // refernce for head
{   
    node * curr = *head_ref;
    node * temp = new node;
    int val;
    cout<<"enter value to insert at ending ";
    cin>>val;
    temp->data = val;
    while(curr->next!=NULL) 
        { curr=curr->next; }
    curr->next=temp;
}
void insertpos(node ** head_ref)
{   node * curr = *head_ref;
    node * temp = new node;
    int pos;
    cout<<"enter position where you want to insert ";
    cin>>pos;
    if(pos==1) insertbeg(&(*head_ref));
    else if(pos==listsize(*head_ref)+1) insertend(&(*head_ref));
    else if(pos>listsize(*head_ref)+1) cout<<"Cant insert";
    else
    {   int val;
        cout<<"enter value you want to insert ";
        cin>>val;
        temp->data=val;
        for(int i=1;i<pos;i++) curr=curr->next;
        temp->next=curr->next;
        curr->next=temp;
        printlist(*head_ref);
    }
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
    node * temp = new node;
    insertbeg(&head);
    printlist(head);
    insertend(&head);
    printlist(head);
    insertpos(&head);
    //printlist(head);

}