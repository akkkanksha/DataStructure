#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void revfor(int arr[],int s)
{
    for(int i=0;i<=s/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[s-i-1];
        arr[s-i-1]=temp;
    }
}
void revwhile(int arr[],int s)
{   int start=0,end=s-1;
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++; end--;
    }
}
void revrecur(int arr[],int s,int start,int end)
{
    if(start>=end) return;
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    revrecur(arr,s,start+1,end-1);
}
int main()
{
int s;
cout<<"Enter size of array ";
cin>>s;
int a[s];
cout<<"\nEnter array content ";
for(int i=0;i<s;i++) cin>>a[i];
//revfor(a,s);
//revwhile(a,s);
revrecur(a,s,0,s-1);
cout<<"\nAfter reverse";
printarr(a,s);
return 0;
}