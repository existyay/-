举一个简单的例子，排序与查找算法本就应该是独立出来的分支，并不一定需要用到结构体

#include<bits/stdc++.h>
using namespace std;

//给定一堆元素，在已经排好序的元素后面直接插入元素，此时仅仅需要在意插入元素在原表中的顺序问题，进行顺序的交换，既是简单的进行下标的对调并且后移

void InsertSort(int a[],int n) {
	int i,j;
	for(i=2; i<=n; i++) {//1位空出来做哨兵 
		if(a[i]<a[i-1]) {
			a[0]=a[i];
			for(j=i-1; a[0]<a[j]; --j) { //寻找合适的位置
				a[j+1]=a[j];
			}
			a[j+1]=a[0];//后移
		}
        for(int k=1;k<n;k++){
        	cout<<a[k]<<" ";
		}
        cout<<endl;//遍历输出 后移的所有过程 
	}
//	for(int i=2;i<=n;i++)
//		cout<<a[i]<<" ";//直接输出最后的结果 
}

int main() {
	int a[11]= {0,2,5,8,3,6,9,1,4,7};
	int n=10;
	InsertSort(a,n);
	return 0;
}
