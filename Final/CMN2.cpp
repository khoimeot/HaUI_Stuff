#include<bits/stdc++.h>

using namespace std;

struct LopHocPhan {
    string maLop;
    int soHocSinh;
    int soHocSinhNu;
};

int thamlam(vector<LopHocPhan>& danhSach , int n) {
  int tongHocSinh = 0 , lopCanLay = 0;
  for(const auto& lop : danhSach) {
    tongHocSinh += lop.soHocSinh;
    lopCanLay++;
    if(tongHocSinh > n ) {
      break;
    }
  }
  return (tongHocSinh > n) ? lopCanLay : -1;
}

void quyhoachdong(vector<LopHocPhan> danhSach , int k , int &tongSoNu , vector<string>& lopDuocChon) {
  int size = danhSach.size();
  vector<vector<int>>dp(size+ 1 , vector<int> (k+1 , 0));
  vector<vector<bool>>select(size + 1 , vector<bool> (k+1 , false));
  for ( int i =1 ; i <=size ; i++) {
    for(int j = 1 ; j <= k ; j++) {
      if (danhSach[i - 1].soHocSinh <= j) {
        int include = danhSach[i - 1].soHocSinhNu + dp[i - 1][j - danhSach[i - 1].soHocSinh];
        int exclude = dp[i - 1][j];
        if (include > exclude) {
          dp[i][j] = include;
          select[i][j] = true;
        } else {
          dp[i][j] = exclude;
        }
      } else {
         dp[i][j] = dp[i - 1][j];
      }
    }
  }

  tongSoNu = dp[size][k];
  lopDuocChon.clear();
  int w = k;
  for(int i = size ; i >0 ; i--) {
    if (select[i][w]) {
      lopDuocChon.push_back(danhSach[i-1].maLop);
      w-= danhSach[i-1].soHocSinh;
    }
  }
}
int char_in_string(char ch , const char* s) {
	int x = 0 ;
	while (s[x]  != '\0' ) {
		if(s[x] == ch) return x;
		x++;
	}
	return -1;
}
bool BoyerMooreHospool(const char* T , const char* P) {
	int v = strlen(P) , i = v - 1;
	while ( i < strlen(T)) {
		int k = v -1;
		while(k >-1 && T[i] == P[k]) {
			i-- ; k--;
		}
		if(k < 0) return true;
		else {
			int x = char_in_string(T[i] , P);
			if( x < 0) {
				i = i+v;
			}
			else {
				i = i+v-x-1;
			}
		}
	}
	return false;
}
vector<int> computeZ(const string& s) {
    int n = s.size();
    vector<int> Z(n, 0);
    int L = 0, R = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= R) {
            Z[i] = min(R - i + 1, Z[i - L]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            ++Z[i];
        }
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

// Hàm kiểm tra chuỗi con sử dụng thuật toán Z
bool isSubstringZ(const string& pattern, const string& text) {
    string combined = pattern + "$" + text;
    vector<int> Z = computeZ(combined);
    int m = pattern.size();
    for (int i = m + 1; i < Z.size(); ++i) {
        if (Z[i] == m) {
            return true;
        }
    }
    return false;
}
void findITClasses(vector<LopHocPhan>& danhSach, const string& searchTerm) {
    // Chuyển chuỗi tìm kiếm và mã lớp thành chữ thường
    string searchTermLower = searchTerm;
    transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    cout << "Danh sách các lớp CNTT (không phân biệt chữ hoa chữ thường):" << endl;
    for (const auto& lop : danhSach) {
        // Chuyển mã lớp thành chữ thường
        string maLopLower = lop.maLop;
        transform(maLopLower.begin(), maLopLower.end(), maLopLower.begin(), ::tolower);

        // So sánh chuỗi tìm kiếm (chữ thường) với mã lớp (chữ thường)
        if (BoyerMooreHospool(maLopLower.c_str(), searchTermLower.c_str())) {
            cout << lop.maLop << " - Số học sinh: " << lop.soHocSinh
                 << ", Số học sinh nữ: " << lop.soHocSinhNu << endl;
        }
    }
}
vector<vector<LopHocPhan>> combinations;

// Hàm quay lui để tạo hoán vị
void backtrack(vector<LopHocPhan>danhSach, vector<LopHocPhan>& current, int start, int k) {
    if (current.size() == k) {
        combinations.push_back(current);
        return;
    }

    for (int i = start; i < danhSach.size(); i++) {
        current.push_back(danhSach[i]);
        backtrack(danhSach, current, i + 1, k);
        current.pop_back();
    }
}
int main() {
  vector<LopHocPhan> danhSach = {
        {"it005", 80, 40}, {"it002", 70, 30}, {"it003", 60, 25},
        {"it004", 55, 20}, {"it001", 50, 20}, {"chem101", 45, 15},
        {"math101", 40, 10}, {"bio101", 35, 10}, {"phy101", 30, 5}
    };

  findITClasses(danhSach, "iT");
//  cout<<thamlam(danhSach , 264);

  int k = 150; // Sức chứa phòng học
  int tongSoNu = 0;
  vector<string> lopDuocChon;
  quyhoachdong(danhSach, k, tongSoNu, lopDuocChon);

    cout << "Tong hoc sinh nu nhieu nhat: " << tongSoNu << endl;
    cout << "Cac lop duoc chon: ";
    for (const auto& lop : lopDuocChon) {
        cout << lop << " ";
    }
    cout << endl;
    char* T = "abagsdvscab";
    char* P = "cab";
    bool ans = BoyerMooreHospool(T, P);
	if(ans)  cout << "Yes"<< endl;
	else cout<<"Nah";
//  cout << "Danh sách các lớp CNTT:" << endl;
//    for (const auto& lop : danhSach) {
//        if (isSubstringZ("it", lop.maLop)) {
//            cout << lop.maLop << " - Số học sinh: " << lop.soHocSinh
//                 << ", Số học sinh nữ: " << lop.soHocSinhNu << endl;
//        }
//    }
//  cout << "Danh sách các lớp CNTT:" << endl;
//  for (const auto& lop : danhSach) {
//      if (BoyerMooreHospool(lop.maLop.c_str(), "it")) {
//          cout << lop.maLop << " - Số học sinh: " << lop.soHocSinh
//               << ", Số học sinh nữ: " << lop.soHocSinhNu << endl;
//      }
//  }
//  return 0;
    int n1 = 9; // Số học phần
    int k1 = 7; // Số học phần cần chọn
    vector<LopHocPhan> current;
    backtrack(danhSach , current, 0, k1);

    // In số cách chọn
    cout << "Tong so cach chon: " << combinations.size() << endl;

    // In ra từng cách chọn
    cout << "Danh sach cach chon:" << endl;
    for (const auto& comb : combinations) {
        for (const auto& i : comb) {
            cout << i.maLop << " ";
        }
        cout << endl;
    }

    return 0;
}