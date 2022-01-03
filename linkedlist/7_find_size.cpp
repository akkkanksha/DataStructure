#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node * next = NULL;
};
int listsize_itr(node * head)
{   int res=0;
    while(head!=NULL)
    {
        head=head->next;
        res++;
    }
    return res;
}
int listsize_recur(node *head)
{ 
  if(head==NULL) return 0;
  return 1+listsize_recur(head->next);
}
int main(){
    cout<<"Enter values for linked-list ";
    node * head= new node;
    node * curr= head;
    int s;
    for(int i=0;i<5;i++)
    {   
        cin>>curr->data;
        curr->next=new node;
        curr=curr->next;
    }
    cin>>curr->data;
    s=listsize_recur(head);
    cout<<s<<endl;
    s=listsize_itr(head);
    cout<<s<<endl;
return 0;
}