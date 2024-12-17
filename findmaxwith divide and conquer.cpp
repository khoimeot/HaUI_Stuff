#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int>& arr, int left, int right) {
    if (left == right) return arr[left]; // Chỉ còn 1 phần tử

    int mid = left + (right - left) / 2;
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);

    return max(maxLeft, maxRight); // So sánh để tìm giá trị lớn nhất
}

int main() {
    vector<int> arr = {1, 5, 3, 9, 2, 10, 4};
    cout << "Maximum element: " << findMax(arr, 0, arr.size() - 1) << endl;
    return 0;
}
