#include<bits/stdc++.h>
using namespace std;
int max_sum(int a[],int s)
{
    int max_now=0,max_prev=INT_MIN;
    for(int i=0;i<s;i++)
    {
        max_now=max_now+a[i];
        if(max_prev<max_now) max_prev = max_now;
        if(max_now<0) max_now=0;
    }   
    return max_prev;
}
int max_sum1(int a[],int s)
{
    int max_now=0,max_prev=0;
    for(int i=0;i<s;i++)
    {
        if(a[i]<=max_now+a[i]) max_now+=a[i];
        else max_now=a[i];
        if(max_prev<max_now) max_prev = max_now;
    }
    return max_prev;
}
int max_sum2(int a[],int s)
{
    int max_now=a[0],max_prev=a[0];
    for(int i=0;i<s;i++)
    {
        max_now = max(a[i],max_now+a[i]);
        max_prev= max(max_now,max_prev);
    }
    return max_prev;
}
int max_sum3(int a[],int s)
{
    int max_now=0,max_prev=0,st=0,e=0;
    for(int i=0;i<s;i++)
    {   max_now+=a[i];
        if(max_prev<max_now) 
        { max_prev = max_now; 
          e=i;}
        if(max_now<0) 
        { max_now=0; 
          st++;}
    }
    cout<<"from start "<<st<<" end "<<e<<" ";
    return max_prev;
}
int main(){
    int s,key;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    cout<<"\nLARGEST SUM OF CONTAGIOUS SUBARRAY IS "<<max_sum(a,s);
    cout<<"\nLARGEST SUM OF CONTAGIOUS SUBARRAY IS "<<max_sum1(a,s);
    cout<<"\nLARGEST SUM OF CONTAGIOUS SUBARRAY IS "<<max_sum2(a,s);
    cout<<"\nLARGEST SUM OF CONTAGIOUS SUBARRAY IS "<<max_sum3(a,s);
    return 0;
}