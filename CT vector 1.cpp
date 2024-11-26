#include<bits/stdc++.h>

using namespace std;

#define MAX 8

struct SV {
  char maSV[15];
  char hoDem[25];
  char ten[10];
  char gioiTinh[10];
  int namSinh;
  float diemTK;
};

struct listKT {
  int count;
  SV e[MAX];
};

typedef struct listKT V;

void creat(V *l) {
  l->count = -1;
}

int empty(V l) {
  return l.count == -1;
}

int full(V l) {
  return l.count >= MAX - 1;
}


void nhapTTSV(V &l) {
  cout<<"-------------------------Nhap thong tin sinh vien--------------------------"<<endl;
  char a;
  cout<<"Ban can nhap thong tin sinh vien tiep khong ? ( C/K ) : ";cin>>a;
  if(a == 'C') {
    char luaChon = 'C';
    while (luaChon == 'C') {
      l.count++;
      cout<<"Nhap thong tin sinh vien thu "<<l.count +1<<endl;
      cout<<"Nhap MSV : ";fflush(stdin);gets(l.e[l.count].maSV);
      cout<<"Nhap ho dem : ";fflush(stdin) ; gets(l.e[l.count].hoDem);
      cout<<"Nhap ten : ";fflush(stdin);gets(l.e[l.count].ten);
      cout<<"Nhap gioitinh : ";fflush(stdin) ; gets(l.e[l.count].gioiTinh);
      cout<<"Nhap nam sinh : ";cin>>l.e[l.count].namSinh;
      cout<<"Nhap diem tong ket : ";cin>>l.e[l.count].diemTK;
      cout<<"Ban co muon nhap tiep khong ? ( C/K ) : ";cin>>luaChon;
    }
  }
}
void addData4test(V &l) {
    // Sinh viên 1
    l.count++;
    strcpy(l.e[l.count].maSV, "sv1001");
    strcpy(l.e[l.count].hoDem, "tran van");
    strcpy(l.e[l.count].ten, "thanh");
    strcpy(l.e[l.count].gioiTinh, "nam");
    l.e[l.count].namSinh = 1999;
    l.e[l.count].diemTK = 7.5;

    // Sinh viên 2
    l.count++;
    strcpy(l.e[l.count].maSV, "sv1002");
    strcpy(l.e[l.count].hoDem, "nguyen thi");
    strcpy(l.e[l.count].ten, "huong");
    strcpy(l.e[l.count].gioiTinh, "nu");
    l.e[l.count].namSinh = 2000;
    l.e[l.count].diemTK = 7.3;

    // Sinh viên 3
    l.count++;
    strcpy(l.e[l.count].maSV, "sv1003");
    strcpy(l.e[l.count].hoDem, "nguyen van");
    strcpy(l.e[l.count].ten, "binh");
    strcpy(l.e[l.count].gioiTinh, "nam");
    l.e[l.count].namSinh = 1998;
    l.e[l.count].diemTK = 6.4;

    // Sinh viên 4
    l.count++;
    strcpy(l.e[l.count].maSV, "sv1004");
    strcpy(l.e[l.count].hoDem, "bui thi");
    strcpy(l.e[l.count].ten, "hong");
    strcpy(l.e[l.count].gioiTinh, "nu");
    l.e[l.count].namSinh = 2000;
    l.e[l.count].diemTK = 5.8;

    // Sinh viên 5
    l.count++;
    strcpy(l.e[l.count].maSV, "sv1005");
    strcpy(l.e[l.count].hoDem, "duong van");
    strcpy(l.e[l.count].ten, "giang");
    strcpy(l.e[l.count].gioiTinh, "nam");
    l.e[l.count].namSinh = 1998;
    l.e[l.count].diemTK = 8.3;
}

void hienthiTT(V l) {
  cout<<left<<setw(15)<<"STT"<<setw(15)<<"Ma Sinh Vien"<<setw(15)<<"Ho dem"<<setw(15)<<"Ten"<<setw(15)<<"Gioi Tinh"<<setw(15)<<"Nam Sinh"<<setw(15)<<"Diem tong ket"<<endl;
  for(int i = 0 ; i <= l.count ; i++) {
    cout<<left<<setw(15)<<i+1<<setw(15)<<l.e[i].maSV<<setw(15)<<l.e[i].hoDem<<setw(15)<<l.e[i].ten<<setw(15)<<l.e[i].gioiTinh<<setw(15)<<l.e[i].namSinh<<setw(15)<<l.e[i].diemTK<<endl;
  }
}

void xoaptdautien(V &l) {
  if (empty(l)) {
    cout<<"\n  Danh sach rong ! ";
    return;
  }
  for(int i = 1 ; i <= l.count ; i++) {
    l.e[i-1] = l.e[i];
  }
  l.count--;
}

void chepphantu(V &l , int k , SV x) {
  if(k <= l.count+2 && k > 0 && !full(l)) {
    for(int i = l.count ; i >= k - 1 ; i--) {
      l.e[i+1] = l.e[i];

    }
    l.e[k-1] = x;
    l.count++;
  }
  else {
    cout<<"Vi tri chen khong hop le ! "<<endl<<endl<<endl<<endl<<endl<<"i think i have enough attention now !";
  }
}
void chenpt( SV &x) {
    strcpy(x.maSV, "sv1006");
    strcpy(x.hoDem, "Le Thi");
    strcpy(x.ten, "Doan");
    strcpy(x.gioiTinh, "Nu");
    x.namSinh = 1998;
    x.diemTK = 7.6;
}
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
void insertionSortKT(V *l) {
  for(int i = 1 ; i <= l->count ; i++) {
    SV tam = l->e[i];
    toLowerCase(tam.ten);
    int j = i-1 ;
    while( j > -1) {
      toLowerCase(l->e[j].ten);
      if(strcmp(l->e[j].ten , tam.ten) > 0) {

        l->e[j+1] = l->e[j];
        j--;
      }
      else {
        break;
      }
    }
    l->e[j+1] = tam;
  }
}
int main() {
  V L;
  creat(&L);
  addData4test(L);  //nhapTTSV(L);
  hienthiTT(L);
  xoaptdautien(L);
  cout<<"-------------------Sau khi xoa phan tu dau tien ta duoc danh sach sau-------------------"<<endl;
  hienthiTT(L);
  SV x;
  chenpt(x);
  chepphantu(L , 3 , x);
  cout<<"-------------------Sau khi chen phan tu ta duoc danh sach sau-------------------"<<endl;
  hienthiTT(L);
  insertionSortKT(&L);
  cout<<"-------------------Sau khi sap xep theo ten ta duoc danh sach sau-------------------"<<endl;
  hienthiTT(L);

}