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

void quyhoachdong(vector<LopHocPhan> danhSach , int k  , int &tongSoNu , vector<string> &lopDuocChon) {
  int size = danhSach.size();
  vector<vector<int>> dp(size + 1, vector<int>(k+1 , 0));
  vector<vector<bool>> select(size + 1, vector<bool>(k+1 , false));

  for(int i = 1 ; i <= size ; i++) {
    for(int j = 1 ; j <= k ; j++) {
      if(danhSach[i-1].soHocSinh <= j) {
        int include = danhSach[i-1].soHocSinhNu + dp[i-1][j- danhSach[i-1].soHocSinh];
        int exclude = dp[i-1][j];
        if ( include > exclude) {
          dp[i][j] = include;
          select[i][j] = true;
        }
        else {
          dp[i][j] = exclude;
        }
      }
      else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  tongSoNu = dp[size][k];
  lopDuocChon.clear();
  int w = k ;
  for(int i = size ; i > 0 ; i--) {
    if(select[i][w]) {
      lopDuocChon.push_back(danhSach[i-1].maLop);
      w-=danhSach[i-1].soHocSinh;
    }
  }
}
int char_in_string(char ch , const char*s) {
  int x = 0;
  while(s[x] != '\0') {
    if(s[x] == ch) {
      return x;
    }
    x++;
  }
  return -1;
}

bool BMH(const char* T , const char * P) {
  int v = strlen(P) , i = v-1;
  while ( i< strlen(T)) {
    int k = v -1 ;
    while(k > -1 && T[i] == P[k]) {
      i--;k--;
    }
    if(k<0) return true;
    else {
      int x = char_in_string(T[i] , P);
      if (x < 0) i+=v;
      else i+=v-x-1;
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
void findITClasses(vector<LopHocPhan> &danhSach , const string &tim) {
  string tim1 = tim;
  transform(tim1.begin() , tim1.end() , tim1.begin() , ::tolower);

  for(const auto& lop : danhSach) {
    string ml1 = lop.maLop;
    transform(ml1.begin() , ml1.end() , ml1.begin() , ::tolower);
    if(BMH(ml1.c_str() , tim1.c_str())) {
      cout<<"Lop hoc phan : "<<lop.maLop<<" , So hoc sinh : "<<lop.soHocSinh<<"  , So hoc sinh nu :"<<lop.soHocSinhNu<<endl;
    }
  }
}
int main() {
  vector<LopHocPhan> danhSach = {
        {"it005", 80, 40}, {"it002", 70, 30}, {"it003", 60, 25},
        {"it004", 55, 20}, {"it001", 50, 20}, {"chem101", 45, 15},
        {"math101", 40, 10}, {"bio101", 35, 10}, {"phy101", 30, 5}
    };
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
    bool ans = BMH(T, P);
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
  findITClasses(danhSach, "iT");
}