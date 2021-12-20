// only 1 number with odd frequency
#include<bits/stdc++.h>
using namespace std;
void odd_freq(int a[],int s)  // order of N*N
{   
    for(int i=0;i<s;i++)
    {   int count=0;
        for(int j=0;j<s;j++)
        {
            if(a[i]==a[j]) count++;
        }
        if(count%2==1) 
        { cout<<"\nNUMBER with odd frequency is "<<a[i];
          return;}
    }
}
void odd_freq1(int a[],int s) // time - O(N) , space - O(N) // random order
{
    unordered_map <int,int> m;
    for(int i=0;i<s;i++) m[a[i]]++;
    for(auto i:m)
    { 
      if(i.second%2==1) 
      { cout<<"\nNUMBER with odd frequency is "<<i.first;
        return;}
    }
}
int odd_freq2(int a[],int s) // order of N // works only if 1 number has odd freq
{
    int res=0;
    for(int i=0;i<s;i++)
    {
        res=res^a[i];
    }
    return res;
}
int main()
{   int s,key;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    odd_freq(a,s);
    odd_freq1(a,s);
    cout<<"\nNUMBER with odd frequency is "<<odd_freq2(a,s);
return 0;
}