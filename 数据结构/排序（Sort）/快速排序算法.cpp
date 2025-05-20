#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr, int p, int r) {
    for (int i = p; i <= r; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Partition(vector<int>& A, int p, int r) {
    int pivot = A[r]; // 选择最后一个元素作为基准
    int i = p - 1;    // i是小于基准的区域的右边界

    for (int j = p; j < r; ++j) {
        if (A[j] <= pivot) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]); // 将基准放到正确的位置
    return i + 1;         // 返回基准的最终位置
}

void QuickSort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        cout << "分治 [" << p << ", " << r << "]: ";
        printArray(A, p, r);

        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int main() {
    vector<int> arr = {35, 68, 12, 35, 26, 78, 14, 11};
    cout << "源数组: ";
    printArray(arr, 0, arr.size() - 1);

    QuickSort(arr, 0, arr.size() - 1);

    cout << "最终数组: ";
    printArray(arr, 0, arr.size() - 1);

    return 0;
}