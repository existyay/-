#include <bits/stdc++.h>
using namespace std;
// 结构体用于存储结果：最大收益和所有切割方案
struct Result {
    int maxRevenue;
    vector<vector<int>> solutions;
};

// 扩展版本，记录所有最大收益的切割方案
Result extendedBottomUpCutRodAllSolutions(const vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);          // 存储最大收益
    vector<vector<vector<int>>> solutions(n + 1); // 存储所有切割方案
    
    for (int j = 1; j <= n; ++j) {
        int maxRevenue = INT_MIN;
        vector<vector<int>> tempSolutions;
        
        for (int i = 1; i <= j; ++i) {
            int currentRevenue = prices[i] + dp[j - i];
            
            if (currentRevenue > maxRevenue) {
                // 发现更大的收益，重置方案列表
                maxRevenue = currentRevenue;
                tempSolutions.clear();
                
                // 如果剩余长度为0，当前就是完整方案
                if (j - i == 0) {
                    tempSolutions.push_back({i});
                } 
                // 否则组合当前切割和子问题的所有方案
                else {
                    for (auto& sol : solutions[j - i]) {
                        vector<int> newSol = {i};
                        newSol.insert(newSol.end(), sol.begin(), sol.end());
                        tempSolutions.push_back(newSol);
                    }
                }
            } 
            else if (currentRevenue == maxRevenue) {
                // 发现同等收益的方案，添加到方案列表
                if (j - i == 0) {
                    tempSolutions.push_back({i});
                } else {
                    for (auto& sol : solutions[j - i]) {
                        vector<int> newSol = {i};
                        newSol.insert(newSol.end(), sol.begin(), sol.end());
                        tempSolutions.push_back(newSol);
                    }
                }
            }
        }
        
        dp[j] = maxRevenue;
        solutions[j] = tempSolutions;
    }
    
    return {dp[n], solutions[n]};
}

// 辅助函数：打印所有方案
void printAllSolutions(const Result& result) {
    cout << "最大收益: " << result.maxRevenue << endl;
    cout << "所有切割方案 (" << result.solutions.size() << "种):" << endl;
    
    for (const auto& sol : result.solutions) {
        for (int cut : sol) {
            cout << cut << " ";
        }
        cout << endl;
    }
}

int main() {
    // 价格表，prices[i]表示长度为i的钢条的价格
    vector<int> prices = {0, 3, 5, 8, 10, 13, 17};
    
    int n = 7; // 钢条长度
    
    // 获取所有最优解
    Result result = extendedBottomUpCutRodAllSolutions(prices, n);
    
    // 打印结果
    printAllSolutions(result);
    
    return 0;
}