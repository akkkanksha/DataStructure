#include <bits/stdc++.h>
using namespace std;
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void merge(int a1[], int m, int a2[], int n)
{
    int a3[m + n],i=0,j=0,z=0;
    while(i<n || j<m || z<m+n)
    {
        if (a1[i] < a2[j])  a3[z++] = a1[i++];
        else   a3[z++] = a2[j++];
        if (i == m && j < n)  a3[z++] = a2[j++];
        if (i < m && j == n) a3[z++] = a1[i++];
    }
    printarr(a3, m + n);
}
void pushback(int a[],int s)
{   int j=s-1;
    for(int i=s-1;i>=0;i--)
    {
        if(a[i]!=-1) 
        {a[j]=a[i];
        j--;
        }
    }
    printarr(a, s);
}
void mergegfg(int a1[],int m,int a2[],int n)
{ int i=n,j=0,k=0;
  while (k<m+n)
  {
     if(j==n || i<m+n && a1[i]<a2[j]) a1[k++]=a1[i++];
     else a1[k++]=a2[j++];
  }
  printarr(a1,m+n);
}
int main()
{
    int m, n;
    cout << "enter size of array 1 : ";
    cin >> m;
    int a1[m];
    cout << "\nenter content of array ";
    for (int i = 0; i < m; i++)   cin >> a1[i];
    cout << "enter size of array 2 : ";
    cin >> n;
    int a2[n];
    cout << "\nenter content of array ";
    for (int i = 0; i < n; i++)  cin >> a2[i];
    pushback(a1,m);
    mergegfg(a1, m-n, a2, n);
    return 0;
}