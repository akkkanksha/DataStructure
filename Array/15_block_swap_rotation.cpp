//imp
#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void swap(int a[], int fi, int si, int d)
{
    int i, temp;
    for(i = 0; i < d; i++)
    {
        temp = a[fi + i];
        a[fi + i] = a[si + i];
        a[si + i] = temp;
    }
}
void rotate(int a[],int s,int d)
{
   int i, j;
   if (d == 0 || d == s)  return;    
    i = d;
    j = s - d;
    while (i != j)
    {
        if (i < j) 
        {
            swap(a, d - i, d + j - i, i);
            j -= i;
        }
        else /*B is shorter*/
        {
            swap(a, d - i, d, j);
            i -= j;
        }
    }
    swap(a, d - i, d, i);
}
int main(){
int s,p;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    cout<<"enter index from which you want to rotate ";
    cin>>p;
    //printarr(a,s);
    rotate(a,s,p);
    printarr(a,s);
return 0;
}