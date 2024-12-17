#include<bits/stdc++.h>

using namespace std;

struct SanPham {
    string maSP;
    string tenSP;
    int khoiLuong;
    int giaTri;
};
void chonViTriChen(vector<SanPham> & danhSach , SanPham& spMoi) {
  int left = 0 ; int right = danhSach.size()-1;
  int viTriChen = danhSach.size();
  while(left <= right) {
    int mid = left + (right - left) /2;
    if(danhSach[mid].tenSP == spMoi.tenSP) {
      viTriChen = mid;
      break;
    }
    if(danhSach[mid].tenSP < spMoi.tenSP) {
      left = mid+1;
    }
    else {
      right = mid -1;
    }
  }
  if (viTriChen == danhSach.size()) {
        viTriChen = left;
    }
  danhSach.insert(danhSach.begin()+viTriChen , spMoi);
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

int longestCommonSubstring(const string &str1 ,const string &str2) {
  int m = str1.size() , n = str2.size();
  vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
  int maxlength = 0;

  for(int i = 1 ; i <=m ; i++) {
    for(int j = 1 ; j <= n ; j++) {
      if(str1[i-1] == str2[j-1]) {
        dp[i][j] = dp[i-1][j-1] +1;
        maxlength = max(maxlength , dp[i][j]);
      }
    }
  }
  return maxlength;
}


void findSimilarProducts(const vector<SanPham> &danhSach , const string& maSP) {
  string tenSP = "Dieu hoa Daikin";
  cout<<"Cac san pham giong "<<maSP<<" : "<<endl;
  for(const auto& sp : danhSach) {
    int commonlength = longestCommonSubstring(tenSP , sp.tenSP);
    if(commonlength >=10) {
       cout<<sp.maSP << " - "<<sp.tenSP<<endl;;
    }
  }
}
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
void findTiviProducts(const vector<SanPham>& danhSach) {
   string keyword = "tivi"; // Từ khóa tìm kiếm

    cout << "Các sản phẩm có tên chứa từ 'tivi':\n";
    for (const auto& sp : danhSach) {
        string tenSPLower = toLowerCase(sp.tenSP); // Chuyển tên sản phẩm thành chữ thường
        // Sử dụng thuật toán Boyer-Moore để tìm từ "tivi" trong tên sản phẩm (không phân biệt chữ hoa hay thường)
        if (BoyerMooreHospool(tenSPLower.c_str(), keyword.c_str())) {
            cout << sp.maSP << " - " << sp.tenSP << endl;
        }
    }
}

int main() {
  vector<SanPham> danhSach = {
        {"SP0088", "Dieu hoa Daikin", 9, 2200},
    {"SP007", "Dieu hoa Daikin1", 9, 2200},
    {"SP002", "Dieu hoa Samsung", 10, 2000},
    {"SP005", "May giat Panasonic", 7, 1500},
    {"SP004", "Tu lanh Electrolux", 20, 3000},
    {"SP003", "Tivi LG", 6, 1200},
    {"SP001", "Tivi Sony", 5, 1000},
    {"SP006", "Tivi Samsung", 8, 1100},
    };
    // Thêm sản phẩm mới và tìm vị trí chèn
    SanPham spMoi = {"SP008", "Entag Toshiba", 6, 1300};
    chonViTriChen(danhSach, spMoi);

    // In danh sách sau khi chèn
    cout << "Danh sach san pham sau khi chen:\n";
    for (const auto& sp : danhSach) {
        cout << sp.maSP << " - " << sp.tenSP << " - " << sp.khoiLuong << " - " << sp.giaTri << endl;
    }

    // Tìm các sản phẩm giống SP0088
    findSimilarProducts(danhSach, "SP007");

    // Tìm sản phẩm có tên chứa từ "tivi"
    findTiviProducts(danhSach);
  return 0 ;
}