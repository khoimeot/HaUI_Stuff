#include <iostream>
using namespace std;

long long power(int a, int n) {
    if (n == 0) return 1; // \(a^0 = 1\)
    if (n == 1) return a; // \(a^1 = a\)

    long long half = power(a, n / 2);
    if (n % 2 == 0) return half * half;      // \(a^n = (a^{n/2})^2\)
    else return half * half * a;            // \(a^n = a \cdot (a^{(n-1)/2})^2\)
}

int main() {
    int a = 2, n = 10;
    cout << a << "^" << n << " = " << power(a, n) << endl;
    return 0;
}
