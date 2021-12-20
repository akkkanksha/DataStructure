#include<bits/stdc++.h>
using namespace std;
int pairsum1(int a[], int s,int k) //order of N*N
{   bool f=false;
    for(int i=0;i<s;i++)
    {   
        for(int j=i+1;j<s;j++)
        {
            if(a[i]+a[j]==k) 
            { cout<<"Pair is "<<a[i]<<" and "<<a[j]<<"\n";
              f=true;}
        }
    }
    if(f) return 1;
    return 0;
}
int pairsum2(int a[], int s,int k) // order depends upon sorting technique , merge/hash - O(nlongn) and quick - O(N*N) in worst case
{   sort(a,a+s);
    bool f=false;
    int start=0,end=s-1;
    while(start<end)
    {
            if(a[start]+a[end]==k) 
            { cout<<"Pair is "<<a[start]<<" and "<<a[end]<<"\n";
              f=true;
              start++;
              end--;
            }
            else if(a[start]+a[end]>k) end--;
            else start++;
    }
    if(f) return 1;
    return 0;
}
void pairsum3(int a[],int s,int k) // by hashing order of N
{
    unordered_set<int> us;
    for (int i=0;i<s;i++)
    {
        int temp = k-a[i];
         if (us.find(temp)!=us.end())
            cout <<" Pair is "<<a[i]<<" and "<<temp<<"\n";
        us.insert(a[i]);
    }
}
// void printPairs(int a[], int n, int x)
// {
// 	int i,rem[x];
// 	for (i = 0; i < x; i++) rem[i] = 0;
// 	for (i = 0; i < n; i++) if (a[i] < x) rem[a[i] % x]++;
// 	for (i = 1; i < x / 2; i++)
// 	{
// 		if (rem[i] > 0 && rem[x - i] > 0)
// 		{  cout << "Yes\n"
// 			break;}
// 	}
// 	if (i >= x / 2)
// 	{   if (x % 2 == 0)
// 		{   if (rem[x / 2] > 1) cout << "Yes\n";
// 			else cout << "No\n";
// 		}
// 		else
// 		{
// 			if (rem[x / 2] > 0 && rem[x - x / 2] > 0) cout << "Yes\n";
// 			else cout << "No\n"'
// 		}
// 	}
// }
int main()
{
    int s,key;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    cout<<"\nEnter sum ";
    cin>>key;
    if(pairsum1(a,s,key)) cout<<"\nPairs available\n";
    else cout<<"\nPairs unavailable\n";
    cout<<endl;
    pairsum2(a,s,key);
    cout<<endl;
    pairsum3(a,s,key);
    return 0;
}