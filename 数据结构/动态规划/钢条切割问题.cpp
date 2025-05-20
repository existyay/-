#include <bits/stdc++.h>
using namespace std;
// �ṹ�����ڴ洢������������������и��
struct Result {
    int maxRevenue;
    vector<vector<int>> solutions;
};

// ��չ�汾����¼�������������и��
Result extendedBottomUpCutRodAllSolutions(const vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);          // �洢�������
    vector<vector<vector<int>>> solutions(n + 1); // �洢�����и��
    
    for (int j = 1; j <= n; ++j) {
        int maxRevenue = INT_MIN;
        vector<vector<int>> tempSolutions;
        
        for (int i = 1; i <= j; ++i) {
            int currentRevenue = prices[i] + dp[j - i];
            
            if (currentRevenue > maxRevenue) {
                // ���ָ�������棬���÷����б�
                maxRevenue = currentRevenue;
                tempSolutions.clear();
                
                // ���ʣ�೤��Ϊ0����ǰ������������
                if (j - i == 0) {
                    tempSolutions.push_back({i});
                } 
                // ������ϵ�ǰ�и������������з���
                else {
                    for (auto& sol : solutions[j - i]) {
                        vector<int> newSol = {i};
                        newSol.insert(newSol.end(), sol.begin(), sol.end());
                        tempSolutions.push_back(newSol);
                    }
                }
            } 
            else if (currentRevenue == maxRevenue) {
                // ����ͬ������ķ�������ӵ������б�
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

// ������������ӡ���з���
void printAllSolutions(const Result& result) {
    cout << "�������: " << result.maxRevenue << endl;
    cout << "�����и�� (" << result.solutions.size() << "��):" << endl;
    
    for (const auto& sol : result.solutions) {
        for (int cut : sol) {
            cout << cut << " ";
        }
        cout << endl;
    }
}

int main() {
    // �۸��prices[i]��ʾ����Ϊi�ĸ����ļ۸�
    vector<int> prices = {0, 3, 5, 8, 10, 13, 17};
    
    int n = 7; // ��������
    
    // ��ȡ�������Ž�
    Result result = extendedBottomUpCutRodAllSolutions(prices, n);
    
    // ��ӡ���
    printAllSolutions(result);
    
    return 0;
}