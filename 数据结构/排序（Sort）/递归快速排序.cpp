#include <bits/stdc++.h>
using namespace std;
template <class T>
int Partition(vector<T> &a,int l,int r){
    T key=a[l];
    while(l<r){
        while(l<r&&a[r]>=key) r--;
        a[l]=a[r];
        while(l<r&&a[l]<=key) l++;
        a[r]=a[l];
    }
    a[l]=key;
    return l;
}
template <class T>
void quick_sort(vector<T> &a,int l,int r){
    if(l>=r) return;
    int i=Partition(a,l,r);
    quick_sort(a,l,i-1);
    quick_sort(a,i+1,r);
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
/*
input:
10
11 10 38 32 48 57 45 54 50 39
output:
10 11 32 38 39 45 48 50 54 57
*/