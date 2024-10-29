#include <iostream>
#include <ctime>
#include <stack>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 3000;

// Hàm hoán đổi hai phần tử
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân đoạn mảng
int partition(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2]; // Chọn pivot là phần tử ở giữa
    int i = low - 1;
    int j = high + 1;
    
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        
        do {
            j--;
        } while (arr[j] > pivot);
        
        if (i >= j)
            return j;
        
        swap(arr[i], arr[j]);
    }
}

// Hàm sắp xếp phân đoạn không đệ quy
void iterativeQuicksort(int arr[], int low, int high) {
    // Tạo một stack để lưu các chỉ số phân đoạn
    stack<int> stack;
    
    // Đưa phần đoạn ban đầu vào stack
    stack.push(low);
    stack.push(high);
    
    // Lặp đến khi stack rỗng
    while (!stack.empty()) {
        // Lấy low và high từ stack
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();
        
        // Phân đoạn mảng và lưu các chỉ số phân đoạn mới vào stack
        int pivotIndex = partition(arr, low, high);
        
        if (pivotIndex - 1 > low) {
            stack.push(low);
            stack.push(pivotIndex - 1);
        }
        
        if (pivotIndex + 1 < high) {
            stack.push(pivotIndex + 1);
            stack.push(high);
        }
    }
}

int main() {
    // Khởi tạo mảng ngẫu nhiên
    int arr[MAX_SIZE];
    srand(time(nullptr)); // Khởi tạo seed cho hàm ngẫu nhiên
    
    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = rand() % 1000; // Giới hạn giá trị từ 0 đến 999
    }
    
    // Đo thời gian chạy thuật toán
    clock_t start = clock();
    
    // Sắp xếp mảng bằng quicksort không đệ quy
    iterativeQuicksort(arr, 0, MAX_SIZE - 1);
    
    // Đo thời gian kết thúc
    clock_t end = clock();
    
    // In ra thời gian thực thi
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Thời gian thực thi của thuật toán: " << time_taken << " giây" << endl;
    
    // Kiểm tra mảng đã sắp xếp
    // for (int i = 0; i < MAX_SIZE; ++i) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    
    return 0;
}