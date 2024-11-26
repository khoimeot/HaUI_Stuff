#include<bits/stdc++.h>

using namespace std;
#define MAX 8
struct CanBo {
  char maCB[15];
  char hoDem[15];
  char ten[15];
  char gioiTinh[15];
  int tuoi;
  float heSoLuong;
  float luongCB;

  void tinhLuong() {
    luongCB = heSoLuong * 1490000;
  }
};

struct List {
  int count;
  CanBo e[MAX];
};

typedef struct List V;

void creat(V *l) {
  l->count = -1;
}

int isEmpty(V l) {
  return l.count == -1;

}

int isFull(V l) {
  return l.count == MAX - 1;

}

void NhapTT(V &l) {
  cout<<"-------------------------------------Nhap thong tin can bo-------------------------------------"<<endl;
  char a;
  cout<<"Ban co muon nhap thong tin can bo khong ? (C/K) : ";cin>>a;
  if(a == 'C') {
    char luaChon = 'C';
    while (luaChon == 'C') {
      l.count++;
      cout<<"Nhap thong tin can bo thu "<<l.count + 1<<endl;
      cout<<"Nhap ma can bo : ";fflush(stdin);gets(l.e[l.count].maCB);
      cout<<"Nhap ho dem : ";fflush(stdin);gets(l.e[l.count].hoDem);
      cout<<"Nhap ten : ";fflush(stdin);gets(l.e[l.count].ten);
      cout<<"Nhap gioi tinh : ";fflush(stdin);gets(l.e[l.count].gioiTinh);
      cout<<"Nhap tuoi : ";cin>>l.e[l.count].tuoi;
      cout<<"Nhap he so luong : ";cin>>l.e[l.count].heSoLuong;
      l.e[l.count].tinhLuong();
      cout<<"Ban co muon nhap tiep thong tin khong (C/K) ? :";cin>>luaChon;
    }
  }
}void addData4Test(V &l) {
    // Dữ liệu mẫu cho các cán bộ
    l.count++;
    strcpy(l.e[l.count].maCB, "CB001");
    strcpy(l.e[l.count].hoDem, "Nguyen Thi");
    strcpy(l.e[l.count].ten, "Lan");
    strcpy(l.e[l.count].gioiTinh, "F");
    l.e[l.count].tuoi = 80;
    l.e[l.count].heSoLuong = 2.5;
    l.e[l.count].tinhLuong(); // Tính lương cơ bản

    l.count++;
    strcpy(l.e[l.count].maCB, "CB002");
    strcpy(l.e[l.count].hoDem, "Tran Minh");
    strcpy(l.e[l.count].ten, "Hoa");
    strcpy(l.e[l.count].gioiTinh,"F");
    l.e[l.count].tuoi = 28;
    l.e[l.count].heSoLuong = 3.0;
    l.e[l.count].tinhLuong();

    l.count++;
    strcpy(l.e[l.count].maCB, "CB003");
    strcpy(l.e[l.count].hoDem, "Le Quang");
    strcpy(l.e[l.count].ten, "Anh");
    strcpy(l.e[l.count].gioiTinh,"M");
    l.e[l.count].tuoi = 65;
    l.e[l.count].heSoLuong = 4.2;
    l.e[l.count].tinhLuong();

    l.count++;
    strcpy(l.e[l.count].maCB, "CB004");
    strcpy(l.e[l.count].hoDem, "Pham Minh");
    strcpy(l.e[l.count].ten, "Tuan");
    strcpy(l.e[l.count].gioiTinh, "M");
    l.e[l.count].tuoi = 40;
    l.e[l.count].heSoLuong = 5.0;
    l.e[l.count].tinhLuong();

    l.count++;
    strcpy(l.e[l.count].maCB, "CB005");
    strcpy(l.e[l.count].hoDem, "Hoang Thi");
    strcpy(l.e[l.count].ten, "Tung");
    strcpy(l.e[l.count].gioiTinh, "F");
    l.e[l.count].tuoi = 25;
    l.e[l.count].heSoLuong = 2.8;
    l.e[l.count].tinhLuong();

    l.count++;
    strcpy(l.e[l.count].maCB, "CB006");
    strcpy(l.e[l.count].hoDem, "Nguyen Thi");
    strcpy(l.e[l.count].ten, "Tung");
    strcpy(l.e[l.count].gioiTinh, "M");
    l.e[l.count].tuoi = 29;
    l.e[l.count].heSoLuong = 3.5;
    l.e[l.count].tinhLuong();
}

void HienTT(V l) {
  cout<<left<<setw(5)<<"STT"<<setw(15)<<"Ma Can Bo"<<setw(15)<<"Ho Dem"<<setw(15)<<"Ten"<<setw(15)<<"Gioi Tinh"<<setw(10)<<"Tuoi"<<setw(15)<<"He So Luong"<<setw(15)<<"Luong CB"<<endl;
  for (int i = 0 ; i <= l.count ; i++) {
    cout<<left<<setw(5)<<i+1<<setw(15)<<l.e[i].maCB<<setw(15)<<l.e[i].hoDem<<setw(15)<<l.e[i].ten<<setw(15)<<l.e[i].gioiTinh<<setw(10)<<l.e[i].tuoi<<setw(15)<<fixed<<setprecision(2)<<l.e[i].heSoLuong<<setw(15)<<fixed<<setprecision(0)<<l.e[i].luongCB<<endl;
  }
}

void HienTTtuoi50(V l) {
  if (isEmpty(l)) {
    cout<<"Danh sach rong";
    return;
  }
  cout<<left<<setw(5)<<"STT"<<setw(15)<<"Ma Can Bo"<<setw(15)<<"Ho Dem"<<setw(15)<<"Ten"<<setw(15)<<"Gioi Tinh"<<setw(10)<<"Tuoi"<<setw(15)<<"He So Luong"<<setw(15)<<"Luong CB"<<endl;
  int count = 0;
  for(int i = 0 ; i <= l.count ; i++) {
    if(l.e[i].tuoi < 50) {
      count++;
      cout<<left<<setw(5)<<count<<setw(15)<<l.e[i].maCB<<setw(15)<<l.e[i].hoDem<<setw(15)<<l.e[i].ten<<setw(15)<<l.e[i].gioiTinh<<setw(10)<<l.e[i].tuoi<<setw(15)<<l.e[i].heSoLuong<<setw(15)<<fixed<<setprecision(0)<<l.e[i].luongCB<<endl;
    }
  }
}

void isTung(V l ,const char *a) {
  if(isEmpty(l) ) {
    cout<<"Danh sach rong !! ";
    return;
  }
  for(int i = 0 ; i <= l.count ; i ++) {
    if (strcmp(l.e[i].ten , a) == 0) {
      cout<<"---------------------------Tim thay can bo ten "<<a<<"---------------------------"<<endl;
      cout<<left<<setw(5)<<"STT"<<setw(15)<<"Ma Can Bo"<<setw(15)<<"Ho Dem"<<setw(15)<<"Ten"<<setw(15)<<"Gioi Tinh"<<setw(10)<<"Tuoi"<<setw(15)<<"He So Luong"<<setw(15)<<"Luong CB"<<endl;
      cout<<left<<setw(5)<<"1"<<setw(15)<<l.e[i].maCB<<setw(15)<<l.e[i].hoDem<<setw(15)<<l.e[i].ten<<setw(15)<<l.e[i].gioiTinh<<setw(10)<<l.e[i].tuoi<<setw(15)<<l.e[i].heSoLuong<<setw(15)<<fixed<<setprecision(0)<<l.e[i].luongCB<<endl;
      return;
    }
  }
  cout<<"Khong tim thay can bo co ten !";
}
void them1pt(CanBo &x) {
    strcpy(x.maCB, "CB007");
    strcpy(x.hoDem, "Le Quang");
    strcpy(x.ten, "Hoang");
    strcpy(x.gioiTinh,  "M");
    x.tuoi = 33;
    x.heSoLuong = 4.5;
    x.tinhLuong();
}

void chenpt(V &l , CanBo x , int k ) {
  if (isEmpty(l) && k< 0 && k > l.count+1 && isFull(l)) {
    cout<<"Danh sach rong hoac day hoac vi tri chen khong hop le !";
    return;
  }
  for(int i = l.count ; i >=  k -1 ; i--) {
    l.e[i+1] = l.e[i];
  }
  l.e[k-1]= x;
  l.count++;

}
int main() {
  V L;
  creat(&L);
  addData4Test(L);//NhapTT(L);
  HienTT(L);
  cout<<"-------------------------------------Cac can bo co tuoi duoi 50 -------------------------------------"<<endl;
  HienTTtuoi50(L);
  isTung(L , "Tung");
  CanBo x;
  them1pt(x);
  chenpt(L , x , 3);
  cout<<"-------------------------------------Danh sach sau khi chen phan tu  -------------------------------------"<<endl;
  HienTT(L);
}