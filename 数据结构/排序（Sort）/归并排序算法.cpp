#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr, int left, int right) {
    for (int i = left; i <= right; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(vector<int>& A, int left, int mid, int right) {
    vector<int> temp(A.begin() + left, A.begin() + right + 1);
    int i = left, j = mid + 1, k = 0;
    int n = right - left + 1;
    
    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = A[i++];
    }
    
    while (j <= right) {
        temp[k++] = A[j++];
    }
    
    for (int m = 0; m < n; ++m) {
        A[left + m] = temp[m];
    }
    
    cout << "归并 [" << left << ", " << right << "]: ";
    printArray(A, left, right);
}

void MergeSort(vector<int>& A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

int main() {
    vector<int> arr = {35, 68, 12, 35, 26, 78, 14, 11};
    cout << "源数组: ";
    printArray(arr, 0, arr.size() - 1);
    
    MergeSort(arr, 0, arr.size() - 1);
    
    cout << "最后排序好的数组: ";
    printArray(arr, 0, arr.size() - 1);
    
    return 0;
}