#include<bits/stdc++.h>
using namespace std;
int missing_num(int a[],int s)
{
    int sum=(s+1)*(s+2)/2;
    for(int i=0;i<s;i++) sum=sum-a[i];
    return sum;
}
int missing_num1(int a[],int s)
{
    int sum=1;
    for(int i=2;i<s+2;i++)
    {
        sum+=i;
        sum-=a[i-2];
    }
    return sum;
}
int missing_num2(int a[],int s)
{
    int a1=a[0],a2=1;
    for(int i=1;i<s;i++) a1=a1^a[i];
    for(int i=2;i<s+2;i++) a2=a2^i;
    return a1^a2;
}
int main()
{
    int s,key;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    cout<<"\n"<<missing_num(a,s);
    cout<<"\n"<<missing_num1(a,s);
    cout<<"\n"<<missing_num2(a,s);
    return 0;
}
    