#include<bits/stdc++.h>
using namespace std;
void leader1(int a[],int s)
{
 // order of N*N
 cout<<"\nLeader elements are\n";
 for(int i=0;i<s;i++)
 {   bool flag = true;
     for(int j=i+1;j<s;j++)
     {
       if(a[i]<a[j]) 
       { flag= false;
         break;}
     }
     if(flag==true) cout<<a[i]<<" ";
 }
}
void leader2(int a[], int s)
{
  // order of N
  int max = a[s-1];
  cout<<endl<<max<<" ";
  for(int i=s-1;i>=0;i--)
  {
     if(a[i]>max) 
     {
         max=a[i];
         cout<<max<<" ";
     }
  }
}
int main(){
 int s;
 cout<<"enter size ";
 cin>>s;
 cout<<"\nenter array content ";
 int a[s];
 for(int i=0;i<s;i++) cin>>a[i];
 leader1(a,s);
 leader2(a,s);

return 0;
}
//{16, 17, 4, 3, 5, 2}