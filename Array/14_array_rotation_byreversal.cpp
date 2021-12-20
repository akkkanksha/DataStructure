#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
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
    int s,p;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    cout<<"enter index from which you want to rotate ";
    cin>>p;
    //printarr(a,s);
    revrecur(a,s,0,p-1);
    //printarr(a,s);
    revrecur(a,s,p,s-1);
    //printarr(a,s);
    revrecur(a,s,0,s-1);
    printarr(a,s);
    return 0;
}