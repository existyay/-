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
    int pivot = A[r]; // ѡ�����һ��Ԫ����Ϊ��׼
    int i = p - 1;    // i��С�ڻ�׼��������ұ߽�

    for (int j = p; j < r; ++j) {
        if (A[j] <= pivot) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]); // ����׼�ŵ���ȷ��λ��
    return i + 1;         // ���ػ�׼������λ��
}

void QuickSort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        cout << "���� [" << p << ", " << r << "]: ";
        printArray(A, p, r);

        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int main() {
    vector<int> arr = {35, 68, 12, 35, 26, 78, 14, 11};
    cout << "Դ����: ";
    printArray(arr, 0, arr.size() - 1);

    QuickSort(arr, 0, arr.size() - 1);

    cout << "��������: ";
    printArray(arr, 0, arr.size() - 1);

    return 0;
}