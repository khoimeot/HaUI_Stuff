#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); // Sắp xếp giảm dần
    int count = 0;
    for (int coin : coins) {
        if (amount == 0) break;
        count += amount / coin;
        amount %= coin;
    }
    return (amount == 0) ? count : -1; // -1 nếu không thể đổi đủ số tiền
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100};
    int amount = 87;
    int result = coinChange(coins, amount);
    if (result != -1) cout << "Minimum coins needed: " << result << endl;
    else cout << "Cannot make the amount with given coins." << endl;
    return 0;
}
