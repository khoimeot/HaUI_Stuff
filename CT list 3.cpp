#include<bits/stdc++.h>

using namespace std;

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

struct Node {
  CanBo infor;
  Node *next;
};

typedef Node *TRO;

void creat(TRO &L) {
  L = NULL;
}
int isEmpty(TRO L) {
  return L == NULL;
}

void nhapCB(CanBo &x) {
  cout<<"Nhap ma can bo : ";fflush(stdin);gets(x.maCB);
  cout<<"Nhap ho dem : ";fflush(stdin);gets(x.hoDem);
  cout<<"Nhap ten : ";fflush(stdin);gets(x.ten);
  cout<<"Nhap gioi tinh : ";fflush(stdin);gets(x.gioiTinh);
  cout<<"Nhap tuoi  : ";cin>>x.tuoi;
  cout<<"Nhap he so luong: ";cin>>x.heSoLuong;
  x.tinhLuong();
}


void NhapDS(TRO &L) {
  creat(L);
  TRO Q , P;
  Q = NULL;
  int i = 0 ;
  CanBo x;
  do {
    char a = 'C';
    cout<<"Ban co muon nhap thong tin can bo tiep khong ? (C/K) : ";cin>>a;
    if (a != 'C') {
      return;
    }
    cout<<"Nhap thong tin can bo thu "<<i+1<<endl;
    nhapCB(x);

    P = new(Node) ;
    P->infor = x;
    P->next = NULL;
    if (L == NULL) L = P;
    else Q->next = P;
    Q = P;
    i++;

  }
  while(i);
}

void hienthiDS(TRO L) {
  if (isEmpty(L)) {
    cout<<"Danh sach rong!";
    return;
  }

  cout<<left<<setw(10)<<"STT"<<setw(10)<<"Ma can bo"<<setw(15)<<"Ho Dem"<<setw(15)<<"Ten"<<setw(15)<<"Gioi Tinh"<<setw(15)<<"Tuoi"<<setw(15)<<"He So Luong"<<setw(15)<<"Luong co ban"<<endl;
  TRO Q = L;
  int i = 0;
  do {
    CanBo x = Q->infor;
    cout<<left<<setw(10)<<i+1<<setw(10)<<x.maCB<<setw(15)<<x.hoDem<<setw(15)<<x.ten<<setw(15)<<x.gioiTinh<<setw(15)<<x.tuoi<<setw(15)<<x.heSoLuong<<setw(15)<<fixed<<setprecision(2)<<x.luongCB<<endl;
    i++;
    Q = Q->next;
  }
  while (Q!=NULL);
}
void themHH(TRO &L , CanBo x) {

  x.tinhLuong();
  TRO P = new Node;
  P->infor = x;
  P->next = NULL;
  if(L == NULL) {
    L = P;
  }
  else {
    TRO Q = L;
    while(Q->next != NULL) {
      Q = Q->next;
    }
    Q->next = P;
  }

}

void dataset4test(TRO &L) {
  CanBo ds[6] ={
    {"C2001", "Nguyen", "An","Nam", 12, 6.4},
    {"C2002", "Le", "Binh","Nu", 23, 4.3},
    {"C2003", "Pham", "Cuong","Nam", 34, 2.5},
    {"C2004", "Tran", "Tung","Nu", 43, 1.7},
    {"C2005", "Hoang", "Hoai","Nam", 26, 3.3},
    {"C2006", "Pham", "Tung","Nu", 63, 2.1}
  };

  for(int i = 0 ; i < 6 ; i++) {
    themHH(L , ds[i]);
  }
}
void timtheoten(TRO &L , const char *a) {
  TRO Q = L;
  if (isEmpty(L)) {
    cout<<"Danh sach rong !";
    return;
  }
  int i = 1;
  while (Q != NULL ) {
    if (strcmp(Q->infor.ten , a) == 0) {
      CanBo x = Q->infor;
      cout<<left<<setw(10)<<i<<setw(10)<<x.maCB<<setw(15)<<x.hoDem<<setw(15)<<x.ten<<setw(15)<<x.gioiTinh<<setw(15)<<x.tuoi<<setw(15)<<x.heSoLuong<<setw(15)<<fixed<<setprecision(2)<<x.luongCB<<endl;
      i++;
    }
    Q = Q->next;
  }
}
void nuduoi50(TRO &L) {
  TRO Q = L;
  if (isEmpty(L)) {
    cout<<"Danh sach rong !" ;
    return;
  }
  int i = 1 ;
  while (Q != NULL) {
    if (strcmp(Q->infor.gioiTinh , "Nu") == 0 && Q->infor.tuoi < 50) {
      CanBo x = Q->infor;
      cout<<left<<setw(10)<<i<<setw(10)<<x.maCB<<setw(15)<<x.hoDem<<setw(15)<<x.ten<<setw(15)<<x.gioiTinh<<setw(15)<<x.tuoi<<setw(15)<<x.heSoLuong<<setw(15)<<fixed<<setprecision(2)<<x.luongCB<<endl;
      i++;
    }
    Q = Q->next;
  }
}

void themptt3(TRO &L , int k ) {
  TRO P = NULL,Q = L;
  int d = 1;
  while (Q!= NULL && d < k) {
    P = Q;
    Q = Q->next;
    d++;
  }
  if(isEmpty(Q) || k < 1) {
    cout<<"Danh sach rong hoac vi tri chen khong hop le "<<endl;
    return;
  }

  TRO A = new Node;
  strcpy(A->infor.maCB , "H2006");
  strcpy(A->infor.hoDem , "Muc");
  strcpy(A->infor.ten , "Cai");
  strcpy(A->infor.gioiTinh , "Nam");
  A->infor.tuoi = 56;
  A->infor.heSoLuong = 1.4;
  A->infor.tinhLuong();

  if (k == 1) {
    A->next = L;
    L = A;
  }
  else {
    A->next = Q;
    P->next = A;
  }
}
int main() {
  TRO L , Q ;
  creat(L);
  dataset4test(L);//NhapDS(L);
  hienthiDS(L);
  cout<<"--------------------------Danh sach nhung nguoi co ten trung voi ten tim kiem--------------------------"<<endl;
  timtheoten(L , "Tung");
  cout<<"--------------------------Danh sach nhung ban nu co tuoi duoi 50 --------------------------"<<endl;
  nuduoi50(L);
  themptt3(L , 3);
  cout<<"--------------------------Danh sach sau khi chen phan tu thu 3 --------------------------"<<endl;
  hienthiDS(L);
}