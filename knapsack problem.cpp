#include <bits/stdc++.h>
using namespace std;

void knapsackGreedy(vector<int> &v, vector<int> &w, int n, double capacity, double &totalv, double &totalw, vector<bool> &r) {
    vector<double> ratio(n);  // Store value-to-weight ratio
    vector<int> indices(n);  // Store original indices

    for (int i = 0; i < n; i++) {
        ratio[i] = static_cast<double>(v[i]) / w[i];
        indices[i] = i;
        r[i] = false; // Initialize as not selected
    }

    // Sort indices based on ratios in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[indices[i]] < ratio[indices[j]]) {
                swap(indices[i], indices[j]);
            }
        }
    }

    totalv = 0.0;
    totalw = 0.0;

    for (int i = 0; i < n; i++) {
        int idx = indices[i];  // Get the original index
        if (totalw + w[idx] <= capacity) {
            totalv += v[idx];
            totalw += w[idx];
            r[idx] = true;
        } else {
            break;
        }
    }
}

int main() {
    vector<int> v = {10, 5, 15, 7, 6};
    vector<int> w = {2, 3, 5, 7, 1};

    int n = 5;
    vector<bool> r(n);
    double capacity = 15.0;
    double totalw = 0.0, totalv = 0.0;

    knapsackGreedy(v, w, n, capacity, totalv, totalw, r);

    cout << "Tong trong luong la: " << totalw << endl;
    cout << "Tong gia tri la: " << totalv << endl;
    cout << "Cac do vat duoc lay (1 = lay):" << endl;
    for (int i = 0; i < n; i++) {
        cout << r[i] << " ";
    }

    return 0;
}
