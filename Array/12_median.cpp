#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
float median(int a1[], int m, int a2[], int n)
{
    int a3[m + n],i=0,j=0,z=0;
    while(i<m || j<n || z<m+n)
    {
        if (a1[i] < a2[j])  a3[z++] = a1[i++];
        else   a3[z++] = a2[j++];
        if (i == m && j < n)  a3[z++] = a2[j++];
        if (i < m && j == n) a3[z++] = a1[i++];
    }
    printarr(a3, m + n);
    float res;
    if((m+n)%2==1)  res=a3[(m+n)/2];
    else res=(a3[(m+n)/2]+a3[(m+n-1)/2])/2.0;
    return res;
}
int main(){
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
    cout<<median(a1, m, a2, n);
return 0;
}