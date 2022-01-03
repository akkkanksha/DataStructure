#include<bits/stdc++.h>
using namespace std;
int main(){
int* L = new int[10]; 
for(int i=0;i<10;i++) cin>>L[i];
for(int i=0;i<10;i++) cout<<L[i]<<" ";
delete[] L;
return 0;
}