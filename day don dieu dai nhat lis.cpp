#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // Khởi tạo dp[i] = 1
    vector<int> prev(n, -1); // Mảng lưu chỉ số của phần tử trước đó trong LIS

    // Tính toán DP và lưu lại chỉ số phần tử trước đó
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j; // Cập nhật phần tử trước đó
            }
        }
    }

    // Tìm độ dài LIS
    int lisLength = *max_element(dp.begin(), dp.end());

    // Tái tạo dãy con LIS
    int index = distance(dp.begin(), max_element(dp.begin(), dp.end()));
    vector<int> lis;
    while (index != -1) {
        lis.push_back(arr[index]);
        index = prev[index];
    }

    // In ra dãy con LIS (lúc này là đảo ngược, nên phải đảo lại)
    reverse(lis.begin(), lis.end());

    // In ra độ dài LIS và dãy con LIS
    cout << "Độ dài dãy con tăng dài nhất là: " << lisLength << endl;
    cout << "Dãy con tăng dài nhất là: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return lisLength;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    longestIncreasingSubsequence(arr);
    return 0;
}
