#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void majority_ele(int a[],int s) //order of N*N -Akanksha
{
    int maxfreq=0,num=a[0];
    for(int i=0;i<s;i++)
    {   int freq=1;
        for(int j=i+1;j<s;j++)
         if(a[i]==a[j]) freq++;
        if(maxfreq<freq) 
        { maxfreq=freq;
          num=a[i];
        }
    }
    if(maxfreq>s/2) cout<<num<<" is present "<<maxfreq<<" times";
    else cout<<"no majority element";
}
void majority(int arr[], int n) // nishant
{
    int count = 0,a=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                a = arr[i];
                count++;
            }
        }
    }
    if (count > n / 2) cout << "\nThe majority element is " << a << endl;
    else cout<<"\nNo Majority Element\n";
}
// method 2 - Moore’s Voting Algorithm ( 2 step - 1. candidate , 2. check) if +50% then must be sequesnce or at last
// order of N
int find_cand(int a[],int s)
{ int maj_ind=0, cand=a[maj_ind],count=1;
  for(int i=1;i<s;i++)
  {   
      if(a[maj_ind]==a[i]) count++;
      else count--;
      if(count==0) 
      {
          maj_ind=i;
          count=1;
      }
  }
  return a[maj_ind];
}
bool check_cand(int a[],int s)
{
    int num=find_cand(a,s),count=0;
    for(int i=0;i<s;i++)
    {
        if(num==a[i]) count++;
    }
    if(count>s/2) return true;
    return false;
}
void majority_ele1(int a[],int s) //
{   if(check_cand(a,s)) cout<<"\nmajority element is "<<find_cand(a,s);
    else cout<<"\nNo majority element";
}
// end of method 2
// method 3 - By hashmap
void majority_ele2(int a[],int s)
{
  unordered_map <int,int> m;
  for(int i=0;i<s;i++)
  {
      m[a[i]]++;
  }
  int f=0;
  for(auto i:m) 
  {
    if(i.second>s/2) 
    {
        f++;
        cout<<"\nMajority element is "<<i.first;
    }
  }
  if(f==0) cout<<"\nNo Majority element";
}
//
void majority_ele3(int a[],int s)
{
    sort(a,a+s);
    int count = 1;
    int f=0;
    for(int i=0;i<s;i++)
    {   
        if(a[i]==a[i+1])
        {   count++;
            if(count>s/2) 
            {   f++;
                cout<<"\nMajority-element is "<<a[i];
            }
        }
        else 
        { count=1;i--;}
    }
    if(!f) cout<<"NO majority element";
}
int main()
{   int s,key;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    majority_ele(a,s);
    majority_ele1(a,s);
    majority_ele2(a,s);
    majority_ele3(a,s);
    return 0;
}