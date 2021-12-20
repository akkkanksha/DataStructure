#include<bits/stdc++.h>
using namespace std;
int FindMaxSum(int a[], int s)
{
    int incl = a[0],excl = 0,excl_new;
    for (int i = 1; i < s; i++)
    {
        excl_new = (incl > excl) ? incl : excl;
        incl = excl + a[i];
        excl = excl_new;
    }
    return ((incl > excl) ? incl : excl);
}
int main(){
    int s,p;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    cout<<FindMaxSum(a,s);
    return 0;
}