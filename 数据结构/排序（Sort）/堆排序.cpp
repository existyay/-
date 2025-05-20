#include <bits/stdc++.h>
using namespace std;
void sift_down(int a[],int l,int r){
    int i=l,j=2*i+1;
    while(j<=r){
        if(j+1<=r&&a[j+1]>a[j]) j++;
        if(a[i]>a[j]) return;
        swap(a[i],a[j]);
        i=j;
        j=2*i+1;
    }
}
void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--) sift_down(a,i,n-1);
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        sift_down(a,0,i-1);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    heap_sort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
/*
input:
10
19 45 39 32 48 57 45 54 50 39
output:
19 32 39 39 45 45 48 50 54 57
*/