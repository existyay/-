#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> greedyChange(int amount, vector<int>& coins) {
    // 将纸币面值按从大到小排序
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
    
    cout << "找零 " << amount << " 元的最优方案（张数最少）为：" << endl;
    for (int i = 0; i < coins.size(); ++i) {
        if (change[i] > 0) {
            cout << coins[i] << " 元纸币: " << change[i] << " 张" << endl;
        }
    }
    
    return 0;
}