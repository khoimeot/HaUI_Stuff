#include<bits/stdc++.h>

using namespace std;

#define MAX 8

struct HangHoa {
  char maHang[15];
  char tenHang[15];
  char dvTinh[15];
  float donGia;
  int soLuong;
  float thanhTien ;

  void tinhThanhTien() {
    thanhTien = donGia * soLuong;
  }
};

struct List {
  int count;
  HangHoa e[MAX];
};

typedef struct List V ;

void creat(V *l) {
  l->count = -1;
}
int isEmpty(V l) {
  return l.count == -1;
}
int isFull(V l) {
  return l.count == MAX -1;
}
void nhaptt(V &l) {
  cout<<"-------------------------Nhap thong tin hang hoa------------------------- "<<endl;
  char a;
  cout<<"Ban muon nhap thong tin hang hoa khong ? (C/K) : ";cin>>a;
  if (a == 'C') {
    char luaChon = 'C';
    while(luaChon == 'C') {
      l.count++;
      cout<<"Nhap thong tin cua hang hoa thu "<<l.count+1<<endl;
      cout<<"Nhap ma hang  : ";fflush(stdin) ; gets(l.e[l.count].maHang);
      cout<<"Nhap ten hang : ";fflush(stdin) ; gets(l.e[l.count].tenHang);
      cout<<"Nhap DV tinh  : ";fflush(stdin) ; gets(l.e[l.count].dvTinh);
      cout<<"Nhap don gia : ";cin>>l.e[l.count].donGia;
      cout<<"Nhap so luong  : ";cin>>l.e[l.count].soLuong;
      l.e[l.count].tinhThanhTien();
      cout<<"Ban co muon nhap hang hoa tiep theo nua khong (C/K) ? : ";cin>>luaChon;
    }
  }
}
void addData4Test(V &l) {
    // Hang hoa 1
    l.count++;
    strcpy(l.e[l.count].maHang, "H2001");
    strcpy(l.e[l.count].tenHang, "Vo");
    strcpy(l.e[l.count].dvTinh, "Quyen");
    l.e[l.count].donGia = 6500;
    l.e[l.count].soLuong = 20;
    l.e[l.count].tinhThanhTien(); // Tinh thanh tien

    // Hang hoa 2
    l.count++;
    strcpy(l.e[l.count].maHang, "H2002");
    strcpy(l.e[l.count].tenHang, "But chi");
    strcpy(l.e[l.count].dvTinh, "Cai");
    l.e[l.count].donGia = 12000;
    l.e[l.count].soLuong = 50;
    l.e[l.count].tinhThanhTien(); // Tinh thanh tien

    // Hang hoa 3
    l.count++;
    strcpy(l.e[l.count].maHang, "H2003");
    strcpy(l.e[l.count].tenHang, "Hop but");
    strcpy(l.e[l.count].dvTinh, "Chiec");
    l.e[l.count].donGia = 35000;
    l.e[l.count].soLuong = 15;
    l.e[l.count].tinhThanhTien(); // Tinh thanh tien

    // Hang hoa 4
    l.count++;
    strcpy(l.e[l.count].maHang, "H2004");
    strcpy(l.e[l.count].tenHang, "Tay");
    strcpy(l.e[l.count].dvTinh, "Cai");
    l.e[l.count].donGia = 10000;
    l.e[l.count].soLuong = 50;
    l.e[l.count].tinhThanhTien(); // Tinh thanh tien

    // Hang hoa 5
    l.count++;
    strcpy(l.e[l.count].maHang, "H2005");
    strcpy(l.e[l.count].tenHang, "Thuoc ke");
    strcpy(l.e[l.count].dvTinh, "Cai");
    l.e[l.count].donGia = 7000;
    l.e[l.count].soLuong = 55;
    l.e[l.count].tinhThanhTien(); // Tinh thanh tien

    // Hang hoa 6
    l.count++;
    strcpy(l.e[l.count].maHang, "H2006");
    strcpy(l.e[l.count].tenHang, "Muc");
    strcpy(l.e[l.count].dvTinh, "Lo");
    l.e[l.count].donGia = 15000;
    l.e[l.count].soLuong = 28;
    l.e[l.count].tinhThanhTien(); // Tinh thanh tien
}

void hienTT(V l) {
  cout<<left<<setw(15)<<"STT"<<setw(15)<<"Ma Hang"<<setw(15)<<"Ten Hang"<<setw(15)<<"DV tinh"<<setw(15)<<"Don gia"<<setw(15)<<"So Luong"<<setw(15)<<"Thanh Tien"<<endl;
  for(int i = 0 ; i <= l.count ; i++) {
    cout<<left<<setw(15)<<i+1<<setw(15)<<l.e[i].maHang<<setw(15)<<l.e[i].tenHang<<setw(15)<<l.e[i].dvTinh<<setw(15)<<l.e[i].donGia<<setw(15)<<l.e[i].soLuong<<setw(15)<<l.e[i].thanhTien<<endl;
  }
}

void xoaptt3(V &l , int k) {
  if(isEmpty(l) ) {
    cout<<"Danh sach rong !";
    return;
  }
  if (k > 0 && k <= l.count + 1) {
    for(int i = 0 ; i <= l.count ; i++) {
      if (i>=k-1) {
        l.e[i] = l.e[i+1];
      }
    }
    l.count--;
  }

  else {
    cout<<"Vi tri xoa khong hop le ! ";
    return;
  }

}

void chenpt(HangHoa &x) {
    strcpy(x.maHang, "H2007");
    strcpy(x.tenHang, "Phan");
    strcpy(x.dvTinh, "Hop");
    x.donGia = 3000;
    x.soLuong = 15;
    x.thanhTien = 45000; // Tinh thanh tien
}

void chenptvaovitri(V &l , HangHoa x , int k) {
  if (k >0 && k < l.count+2 && !isFull(l)) {
    for(int i = l.count ; i >=k - 1 ; i-- ) {
      l.e[i+1] = l.e[i];
    }
    l.e[k-1] = x;
    l.count++;
  }
  else {
    cout<<"??? M dien cai cho gi vao ma deo ca chay code the "<<endl<<endl<<endl<<endl<<endl<<"cay khong em "<<endl;
  }
}

void bubblesort(V &l) {
  for(int i = 0 ; i <=l.count ; i++) {
    for(int j = l.count  ; j > i ; j--) {
      if(l.e[j].thanhTien < l.e[j-1].thanhTien) {
        HangHoa temp = l.e[j];
        l.e[j] = l.e[j-1];
        l.e[j-1] = temp;
      }
    }
  }
}
int main() {
  V L;
  creat(&L);
  addData4Test(L);//nhaptt(L);
  hienTT(L);
  xoaptt3(L , 3);
  cout<<"---------------------------Sau khi xoa phan tu thu 3 ta duoc danh sach---------------------------"<<endl;
  hienTT(L);
  HangHoa x;
  chenpt(x);
  chenptvaovitri(L , x , 1);
  cout<<"---------------------------Sau khi chen vao phan tu thu nhat ta duoc danh sach---------------------------"<<endl;
  hienTT(L);
  bubblesort(L);
  cout<<"---------------------------Sau khi sap xep phan tu theo thanh tien ta duoc danh sach---------------------------"<<endl;
  hienTT(L);
}