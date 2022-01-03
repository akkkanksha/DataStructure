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
node * delete_itr(node * head)
{
    node * curr=head;
    node * temp;
    int key,f=0;
    cout<<"Enter value you want to delete ";
    cin>>key;
    while(curr->next!=NULL)
    {   
        if(curr->next->data==key)
        {
            f++;
            break;
        }
        curr=curr->next;
    }
    if(f==0) cout<<"node not found \n";
    else
    {
      temp=curr->next;
      curr->next=curr->next->next;
      delete temp;
    }
    return head;
}
void deleterecur(node*& head, int val)
{
    if (head == NULL) {
        cout << "Element not present in the list\n";
        return;
    }
    if (head->data == val) {
        node* t = head;
        head = head->next;
        delete (t);
        return;
    }
    deleterecur(head->next, val);
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
    head=delete_itr(head);
    printlist(head);
    int key;
    cout<<"Enter value you want to delete ";
    cin>>key;
    deleterecur(head,key);
    printlist(head);
return 0;
}