#include <bits/stdc++.h>
using namespace std;
int binsearch(int a[], int s, int num)
{
    int start = 0, end = s, mid;
    while (end >= start)
    {
        mid = start + end + 1 / 2;
        if (a[mid] == num)
            return mid;
        else if (a[mid] > num)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
// int binarySearch(int arr[], int low, int high, int key)
// {
//     if (high < low)
//         return -1;
//     int mid = (low + high) / 2; /*low + (high - low)/2;*/
//     if (key == arr[mid])
//         return mid;
//     if (key > arr[mid])
//         return binarySearch(arr, (mid + 1), high, key);
//     return binarySearch(arr, low, (mid - 1), key);
// }
void insertval(int arr[], int &s, int max, int val)
{
    if (s >= max)
        cout << "\nOVERFLOW";
    else
    {
        s++;
        int valpos = 0,i;
        for(i=0;i<s;i++)  if(arr[i]>val) break;
        valpos = i;
        for (i = s-1; i >= valpos; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[valpos] = val;
    }
}
void deleteval(int arr[], int &s, int num)
{
    int valpos = binsearch(arr, s, num);
    if (s <= 0 || valpos <= 0)
        cout << "\nERROR";
    else
    {
        for (int i = valpos; i < s; i++)
        {
            arr[i] = arr[i + 1];
        }
        s--;
    }
}
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int max = 100;
    int s;
    cout << "]\nenter size of array less than 100 ";
    cin >> s;
    int a[max];
    cout << "\nenter numbers in array ";
    for (int i = 0; i < s; i++)
        cin >> a[i];
    cout << "\nenter number you want to search ";
    int num;
    cin >> num;
    if (binsearch(a, s, num) >= 0)
        cout << "\nposition of " << num << " is " << binsearch(a, s, num)+1;
    else
        cout << "\nNOT FOUND";
    cout << "\n\nenter value you want to insert ";
    int val;
    cin >> val;
    insertval(a, s, max, val);
    printarr(a, s);
    cout << "\nenter number you want to delete ";
    cin >> num;
    deleteval(a, s, num);
    printarr(a, s);
    return 0;
}