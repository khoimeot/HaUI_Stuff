#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonSubstring(const string& A, const string& B) {
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int length = 0;
    int endPos = -1;

    // Duyệt qua các ký tự của A và B để xây dựng bảng DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > length) {
                    length = dp[i][j];
                    endPos = i - 1;
                }
            }
        }
    }

    return (endPos == -1) ? "" : A.substr(endPos - length + 1, length);
}

int main() {
    string A = "abcdef";
    string B = "zcdemf";

    cout << "Xâu con chung dài nhất là: " << longestCommonSubstring(A, B) << endl;

    return 0;
}
