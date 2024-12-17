#include<bits/stdc++.h>

using namespace std;

vector<float> thamlam(float a[], int n , int &D , int &M , int C ) {
  M = 0 ; D = 0;
  vector<float> num;
  for(int i = n ; i >0 ; i--) {
    if (M > C) {
      break;
    }
    M += a[i];
    D++;
    num.push_back(a[i]);
  }
  return num;
}
int char_in_string(char ch , const char * s) {
  int x = 0 ;
  while(s[x] != '\0') {
    if (s[x] == ch) {
      return x;
    }
    x++;
  }
  return -1;
}

int BMH(const char *T , const char *P) {
  int v = strlen(P) , i = v-1 , count = 0;
  while ( i<strlen(T)) {
    int k = v -1 ;
    int j = i;
    while ( k > -1 && T[j] == P[k]) {
      j-- ; k--;
    }
    if (k < 0){
      count++;
      i++;
    }
    else {
      int x = char_in_string(T[i] , P);
      if (x < 0) {
        i = i+v;
      }
      else {
        i = i+v-x-1;
      }
    }
  }
  return count;
}
bool BMH1(const char *T , const char *P) {
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
int main() {
  int n = 14;
  float a[n] = {1.4,3.4,4.4,8.4,9.4,12.4,15.4,17.4,23.4,27.4,34.4,56.4,74.4,79.4,95.4};
  float C = 99.4;
  const char* P = "Vietnam deptrai qua deptrai sieu cap deptrai";
  const char *Q = "deptrai";
  int D ; int M ;
  vector<float>num = thamlam(a , n ,D , M , C );
  cout<<"Cac so duoc chon la :";
  for (float g : num) {
    cout<<g<<" ";
  }
  cout<<endl<<"Tong M :"<<M<<endl;
  cout<<"So phan tu : "<<D<<endl;
  int az = BMH(P , Q);
  cout<<az;
  return 0;
}