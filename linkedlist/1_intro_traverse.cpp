#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node * next = NULL;
};
int main()
{ node * head= new node;
  node * curr= head;
  for(int i=0;i<5;i++)
  {  cin>>curr->data;
     curr->next=new node;
     curr=curr->next;
  }
  curr=head;
  while(curr->next!=NULL)
  {
        cout<<curr->data<<" ";
        curr= curr->next;
  }
return 0;
}