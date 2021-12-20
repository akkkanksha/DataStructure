#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[], int s)
{
    cout << "\nARRAY IS - ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void rotate(int a[],int s,int p)
{
    p=p%s;
    int temp[p];
    for(int i=0;i<s;i++) 
    { if(i<p) temp[i]=a[i];
      if(i<s-p) a[i]=a[i+p];
    }
    //printarr(a,s);
    for(int i=s-p;i<s;i++)
    { a[i]=temp[i-s+p];}
    printarr(a,s);
}
void rotate1(int a[],int s,int p)
{
    p=p%s;
    for(int i=0;i<p;i++)
    {
        int temp=a[0];
        for(int j=0;j<s-1;j++)
        {
          a[j]=a[j+1];
        }
        a[s-1]=temp;
    }
    printarr(a,s);
}
int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}
void rotate2(int a[],int s,int p)
{
    int gcd=1;
    for(int i=1;i<=p;i++)
    {
      if(s%i==0 && p%i==0) gcd=i;
    }
    for(int i=0;i<gcd;i++)
    {   
        int temp= a[i];
        for(int j=i;j<s;j+=gcd)
        {
          a[j]=a[j+gcd];
        }
        a[s-gcd+i]=temp;
        //printarr(a,s);
    }
    printarr(a,s);
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
    // rotate(a,s,p);
    // rotate1(a,s,p);
    rotate2(a,s,p);
return 0;
}