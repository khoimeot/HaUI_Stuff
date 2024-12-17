#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& v, vector<int>& w, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Quy ho?ch d?ng
    for (int i = 1; i <= n; i++) {
        for (int wgt = 1; wgt <= W; wgt++) {
            if (w[i - 1] <= wgt) {
                dp[i][wgt] = max(dp[i - 1][wgt], dp[i - 1][wgt - w[i - 1]] + v[i - 1]);
            } else {
                dp[i][wgt] = dp[i - 1][wgt];
            }
        }
    }

    return dp[n][W];  // Tr? v? gi� tr? t?i da
}

int main() {
    vector<int> values = {60, 100, 120};  // Gi� tr? c?a c�c v?t ph?m
    vector<int> weights = {10, 20, 30};  // Tr?ng lu?ng c?a c�c v?t ph?m
    int W = 50;  // Dung lu?ng c?a c�i t�i
    int n = values.size();  // S? lu?ng v?t ph?m

    cout << "Gi� tr? t?i da c� th? mang theo l�: " << knapsack(W, values, weights, n) << endl;

    return 0;
}
