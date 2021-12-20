#include<bits/stdc++.h>
using namespace std;
int binsearch(int a[], int s,int e, int num)
{
    int start = s, end = e, mid;
    while (end >= start)
    {
        mid = (start + end + 1) / 2;
        if (a[mid] == num)
            return mid;
        else if (a[mid] > num)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int findpivot(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[low] >= arr[mid])
        return findpivot(arr, low, mid - 1);
    return findpivot(arr, mid + 1, high);
}
int pivot(int a[],int s,int key)
{
    int p=findpivot(a,0,s-1);
    if(p==-1) 
    {   return binsearch(a,0,s,key);
    }
    else if(a[p]==key) return p;
    if (a[0] <= key)
        return binsearch(a, 0, p, key);
 
     return binsearch(a, p+1, s, key);
}
//method 2
int search(int arr[], int l, int h, int key)
{
    if (l > h)  return -1;
    int mid = (l + h) / 2;
    if (arr[mid] == key)  return mid;
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])  return search(arr, l, mid - 1, key);
        /*If key not lies in first half subarray,
           Divide other half  into two subarrays,
           such that we can quickly check if key lies
           in other half */
        return search(arr, mid + 1, h, key);
    }
    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
    must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])   return search(arr, mid + 1, h, key);
    return search(arr, l, mid - 1, key);
}
int main(){
    int s,key;
    cout<<"enter size ";
    cin>>s;
    cout<<"\nenter array content ";
    int a[s];
    for(int i=0;i<s;i++) cin>>a[i];
    cout<<"Enter number you want to search ";
    cin>>key;
    cout<<endl<<pivot(a,s,key);
return 0;
}