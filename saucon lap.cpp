#include <iostream>
#include <string>
using namespace std;

bool isSubstring(const string& T, const string& P) {
    int n = T.size();
    int m = P.size();

    // Duyệt qua xâu T và kiểm tra tại mỗi vị trí có xâu P
    for (int i = 0; i <= n - m; i++) {
        if (T.substr(i, m) == P) {
            return true;
        }
    }
    return false;
}

int main() {
    string T = "ababcababc";
    string P = "cab";

    if (isSubstring(T, P)) {
        cout << "P là xâu con của T." << endl;
    } else {
        cout << "P không phải là xâu con của T." << endl;
    }

    return 0;
}
