#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> greedyChange(int amount, vector<int>& coins) {
    // ��ֽ����ֵ���Ӵ�С����
    sort(coins.begin(), coins.end(), greater<int>());
    
    vector<int> result(coins.size(), 0);
    
    for (int i = 0; i < coins.size(); ++i) {
        if (amount >= coins[i]) {
            result[i] = amount / coins[i];
            amount %= coins[i];
        }
    }
    
    return result;
}

int main() {
    int amount = 88;
    vector<int> coins = {50, 20, 10, 5, 1};
    
    vector<int> change = greedyChange(amount, coins);
    
    cout << "���� " << amount << " Ԫ�����ŷ������������٣�Ϊ��" << endl;
    for (int i = 0; i < coins.size(); ++i) {
        if (change[i] > 0) {
            cout << coins[i] << " Ԫֽ��: " << change[i] << " ��" << endl;
        }
    }
    
    return 0;
}