#include<bits/stdc++.h>
//Câu 2.1. Cho một số nguyên dương n ≥ 8, một dãy a gồm n số thực được sắp xếp theo
//chiều tăng dần, một số thực C và 2 chuỗi P và Q không quá 255 ký tự chỉ gồm các chữ số,
//chữ cái và dấu cách. Cài đặt chương trình thực hiện:
//- Cài đặt thuật toán tham lam để tính D là số lượng phần tử nhiều nhất có thế lấy
//trong dãy a để được một giá trị M không vượt quá C và cho biết giá trị của các phần
//tử đã lấy trong a (nếu có). Cài đặt thuật toán Boyer Moore Horspool cho biết chuỗi
//ký tự Q có phải là một chuỗi con của chuỗi ký tự P hay không?
//- Khởi tạo số nguyên dương n, mảng số thực a với các số theo chiều tăng dần, khởi
//tạo số C. Khởi tạo 2 chuỗi ký tự P và Q. Sử dụng các thuật toán đã cài đặt ở trên để
//hiển thị ra màn hình các giá trị D, M, các giá trị đã lấy trong mảng a (nếu có phương
//án), thông báo Q có là chuỗi con của chuỗi P không?
using namespace std;

const float C = 45.6;
const char* P = "Viet nam dep qua di mat";
const char* Q = "Viet nam";


vector<float> thamlam(float a[] , int n , float &M , int &sophantu ) {
  M = 0 ;sophantu = 0;
  vector<float> result;
  for(int j = 0 ; j < n ; j++) {
    if (M + a[j] > C) {
            break;  // If yes, stop adding elements
        }

        M += a[j];  // Otherwise, add the current element to M
        result.push_back(a[j]);  // Add the element to the result vector
        sophantu++;
  }
  return result;
}
int char_in_string(char ch , const char* s) {
  int x = 0;
  while (s[x] != '\0') {
    if (s[x] == ch) {
      return x;
    }
    x++;
  }
  return -1;
}

bool BMH(const char *T , const char *P) {
  int v = strlen(P) , i = v-1;
  while (i < strlen(T)) {
    int k = v-1;
    while (k > -1 && T[i] == P[k]) {
      i-- ; k--;
    }
    if ( k<0 ) return true;
    else {
      int x = char_in_string(T[i] , P);
      if(x<0) {
        i = i+v;
      }
      else {
        i = i+v-x-1;
      }
    }
  }
}
bool BMH1(const char *T , const char *P) {
  int v = strlen(P) , i = v-1 , count = 0;
  while (i < strlen(T)) {
    int k = v-1;
    int j = i;
    while (k > -1 && T[j] == P[k]) {
      j-- ; k--;
    }
    if ( k<0 ) {
      count++;
      i++;
  }
    else {
      int x = char_in_string(T[i] , P);
      if(x<0) {
        i = i+v;
      }
      else {
        i = i+v-x-1;
      }
    }
  }
  return count;
}
int main() {

  int n = 14;
  float a[n] = {1.4,3.4,4.4,8.4,9.4,12.4,15.4,17.4,23.4,27.4,34.4,56.4,74.4,79.4,95.4};
  float M ; int sophantu;
  vector<float>result = thamlam(a,n,M,sophantu);
   cout << "Selected values: ";
    for (float val : result) {
        cout << val << " ";
    }
    cout << "\nTotal sum M: " << M << endl;
    cout << "\nNumber for part of array: " << sophantu << endl;

  bool az = BMH1(P , Q);
  if(az) {
    cout<<"Q la sau con cua P"<<endl;
  }
  else {
    cout<<"Deo phai"<<endl;
  }
  return 0;
}