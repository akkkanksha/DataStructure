#include <bits/stdc++.h>
using namespace std;
int findpos(int arr[], int s, int num)
{
    for (int i = 0; i < s; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}
void deleteval(int arr[], int &s, int num)
{
    int valpos = findpos(arr, s, num);
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
void insertval(int arr[], int &s, int max, int val)
{
    if (s >= max)
        cout << "\nOVERFLOW";
    else
    {
        arr[s] = val;
        s++;
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
    if (findpos(a, s, num) >= 0)
        cout << "\nposition of " << num << " is " << findpos(a, s, num) + 1;
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