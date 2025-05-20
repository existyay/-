#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> selectPackage(int n, vector<int> &p, vector<int> &v,int C) {
    vector<vector<int>> P(n + 1, vector<int>(C + 1, 0));
    vector<vector<int>> Rec(n + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int c = 1; c <= C; ++c) {
            if (v[i-1] <= c && (p[i-1] + P[i-1][c - v[i-1]] > P[i-1][c])) {
                P[i][c] = p[i-1] + P[i-1][c - v[i-1]];
                Rec[i][c] = 1;
            } else {
                P[i][c] = P[i-1][c];
                Rec[i][c] = 0;
            }
        }
    }
    
    vector<int> selected;
    int K = C;
    for (int i = n; i >= 1; --i) {
        if (Rec[i][K] == 1) {
            selected.push_back(i-1); 
            K -= v[i-1];
        }
    }
    sort(selected.begin(), selected.end());
    
    return {P[n][C], selected};
}   

int main() {
    int n = 5,c = 10;
    vector<int> p = {3, 4, 5, 8, 10};
    vector<int> v = {2, 3, 4, 5, 6};
    auto result = selectPackage(n, p, v, c);
    int maxValue = result.first;
    vector<int> selectedItems = result.second;
    cout << "最大价值: " << maxValue << endl;
    cout << "选择的商品索引: ";
    for (int idx : selectedItems) cout << idx << " ";
    cout << endl;
    cout << "选择的商品价值: ";
    for (int idx : selectedItems) cout << p[idx] << " ";
    cout << endl;
    cout << "选择的商品体积: ";
    for (int idx : selectedItems) cout << v[idx] << " ";
    cout << endl;
    return 0;
}