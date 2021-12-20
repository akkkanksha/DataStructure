#include<bits/stdc++.h>
using namespace std;
struct num
{
    int freq=1,index=0,val=0;
};
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
bool mycomp(struct num a, struct num b)
{
    return (a.val < b.val);
}
bool mycomp2(struct num a, struct num b)
{
    if (a.freq != b.freq)
        return (a.freq < b.freq);
    else
        return a.index > b.index;
}
void freqsort(int a[],int n)
{
    num ele[n];
    for(int i=0;i<n;i++) 
    {
        ele[i].freq= 0;
        ele[i].index=i;
        ele[i].val=a[i];
    }
    stable_sort(ele, ele + n, mycomp);
    ele[0].freq = 1;
    for (int i = 1; i < n; i++) {
        if (ele[i].val == ele[i - 1].val) {
            ele[i].freq += ele[i - 1].freq + 1;
            ele[i - 1].freq = -1;
            ele[i].index = ele[i - 1].index;
        }
        else
            ele[i].freq = 1;
    }
    stable_sort(ele,ele+n,mycomp2);
    for (int i = n - 1, index = 0; i >= 0; i--)
        if (ele[i].freq != -1)
            for (int j = 0; j < ele[i].freq; j++)
               { a[index++] = ele[i].val;}
    
}
bool fcompare(pair<int, pair<int, int> > p,pair<int, pair<int, int> > p1)
{
    if (p.second.second != p1.second.second)
        return (p.second.second > p1.second.second);
    else
        return (p.second.first < p1.second.first);
}
void freqsort1(int a[],int n)
{
    unordered_map <int, pair <int,int> >hash;
    for(int i=0;i<n;i++) 
    {   if (hash.find(a[i]) != hash.end())
            hash[a[i]].second++;
        else
            hash[a[i]] = make_pair(i, 1);
    }
    auto it = hash.begin();
    vector<pair<int, pair<int, int> > > b;
    for (it; it != hash.end(); ++it)
        b.push_back(make_pair(it->first, it->second));
 
    sort(b.begin(), b.end(), fcompare);
    for (int i = 0; i < b.size(); i++) 
    {
        int count = b[i].second.second;
        while (count--)
            cout << b[i].first << " ";
    }  
}
int main()
{  
    int n;
    cout<<"Enter size of array";
    cin>>n;
    int a[n];
    cout<<"enter array content";
    for(int i=0;i<n;i++) cin>>a[i];
    freqsort(a,n);
    printarr(a,n);
    freqsort1(a,n);
return 0;
}