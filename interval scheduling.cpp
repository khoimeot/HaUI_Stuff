#include <bits/stdc++.h>
using namespace std;

// Cấu trúc biểu diễn khoảng thời gian
struct Interval {
    int start, end;
};

// Hàm so sánh: sắp xếp theo thời điểm kết thúc tăng dần
bool compare(Interval a, Interval b) {
    return a.end < b.end;
}

int intervalScheduling(vector<Interval> &intervals) {
    // Sắp xếp các khoảng theo thời điểm kết thúc
    sort(intervals.begin(), intervals.end(), compare);
	// quicksort
    int count = 0; // Số lượng khoảng thời gian được chọn
    int lastEnd = -1; // Thời điểm kết thúc của khoảng đã chọn cuối cùng

    for (auto interval : intervals) {
        if (interval.start >= lastEnd) { // Không chồng lấn với khoảng trước
            count++;
            lastEnd = interval.end; // Cập nhật thời điểm kết thúc
        }
    }

    return count; // Trả về số lượng khoảng thời gian không chồng lấn tối đa
}

int main() {
    // Ví dụ danh sách các khoảng thời gian
    vector<Interval> intervals = {{1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8}, {8, 9}};

    // Gọi hàm giải bài toán
    int result = intervalScheduling(intervals);

    // In kết quả
    cout << "So luong khoang thoi gian khong chong lan toi da: " << result << endl;
    return 0;
}
