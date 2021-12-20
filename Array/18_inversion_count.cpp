#include<bits/stdc++.h>
using namespace std;
int inver_count(int a[],int n)
{
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]) count++;
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    int a[n];
    cout<<"enter array content ";
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<inver_count(a,n);
return 0;
}