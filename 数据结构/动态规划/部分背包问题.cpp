#include <bits/stdc++.h>

using namespace std;

struct Item {
    int index;
    double ratio;
    int p;
    int v;
};

bool compare(const Item &a, const Item &b) {
    if (a.ratio != b.ratio) {
        return a.ratio > b.ratio;
    } else {
        return a.index < b.index; // 保持原始顺序以生成所有排列
    }
}

void generateSolutions(vector<Item> &items, int C, set<vector<double>> &solutions) {
    double max_value = 0.0;
    int remaining = C;
    vector<double> percentages(items.size(), 0.0);

    for (const auto &item : items) {
        if (remaining <= 0) break;
        if (item.v <= remaining) {
            max_value += item.p;
            percentages[item.index] = 100.0;
            remaining -= item.v;
        } else {
            double fraction = static_cast<double>(remaining) / item.v;
            max_value += item.p * fraction;
            percentages[item.index] = fraction * 100.0;
            remaining = 0;
        }
    }

    solutions.insert(percentages);
}

void permute(vector<Item> &items, int start, int C, set<vector<double>> &solutions) {
    if (start >= items.size()) {
        generateSolutions(items, C, solutions);
        return;
    }

    for (int i = start; i < items.size(); ++i) {
        if (i != start && items[i].ratio == items[start].ratio) {
            swap(items[i], items[start]);
            permute(items, start + 1, C, solutions);
            swap(items[i], items[start]);
        }
    }
    permute(items, start + 1, C, solutions);
}

set<vector<double>> fractionalKnapsackAll(int n, vector<int> &p, vector<int> &v, int C) {
    vector<Item> items;
    for (int i = 0; i < n; ++i) {
        double ratio = static_cast<double>(p[i]) / v[i];
        items.push_back({i, ratio, p[i], v[i]});
    }
    sort(items.begin(), items.end(), compare);

    set<vector<double>> solutions;
    permute(items, 0, C, solutions);

    return solutions;
}

int main() {
    int n = 5;
    vector<int> p = {30, 40, 20, 20, 15};
    vector<int> v = {200, 300, 200, 300, 150};
    int C = 650;

    auto solutions = fractionalKnapsackAll(n, p, v, C);

    cout << "所有可能的最优方案及其对应的最大价值:" << endl;
    for (const auto &percentages : solutions) {
        double max_value = 0.0;
        for (int i = 0; i < n; ++i) {
            max_value += p[i] * (percentages[i] / 100.0);
        }
        cout << "最大价值: " << max_value << endl;
        cout << "各饮料调制品的选择百分比:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << fixed << setprecision(2);
            cout << "饮料" << i + 1 << ": " << percentages[i] << "%" << endl;
        }
        cout << "------------------------" << endl;
    }

    return 0;
}