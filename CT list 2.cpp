#include<bits/stdc++.h>

using namespace std;
struct HangHoa {
  char maHang[15];
  char tenHang[15];
  char dvTinh[15];
  float donGia;
  int soLuong;
  float thanhTien;

  void tinhThanhTien() {
    thanhTien = donGia * soLuong;
  }
};

struct Node {
  HangHoa infor;
  Node *next;
};
typedef Node *TRO ;

void creat(TRO &L) {
  L = NULL;
}

int isEmpty(TRO L) {
  return L == NULL;
}

void nhapHH(HangHoa &x) {
  cout<<"Nhap ma hang hoa : ";fflush(stdin);gets(x.maHang);
  cout<<"Nhap ten hang : ";fflush(stdin);gets(x.tenHang);
  cout<<"Nhap don vi tinh : ";fflush(stdin);gets(x.dvTinh);
  cout<<"Nhap don gia : ";cin>>x.donGia;
  cout<<"Nhap so luong : ";cin>>x.soLuong;
  x.tinhThanhTien();

}

void nhapDS(TRO &L) {
  creat(L);
  HangHoa x;
  TRO Q , P;
  Q = NULL;
  int i = 1;
  do {
    char a = 'C';
    cout<<"Ban co muon nhap thong tin hang hoa tiep khong ? (C/K) : ";cin>>a;
    if(a != 'C') {
      return;
    }
    cout<<"Nhap sinh vien thu "<<i<<endl;
    nhapHH(x);
    P = new(Node);
    P->infor = x;
    P->next = NULL;
    if(L == NULL) L = P;
    else Q->next = P;
    Q = P;
    i++;
  }
  while (i);
}

void hienthiDS(TRO L ) {
  if (isEmpty(L)) {
    cout<<"Danh sach trong";
    return;
  }
  cout<<left<<setw(15)<<"STT"<<setw(15)<<"Ma Hang"<<setw(15)<<"Ten Hang"<<setw(15)<<"DV Tinh"<<setw(15)<<"Don Gia"<<setw(15)<<"So Luong"<<setw(15)<<"Thanh Tien"<<endl;
  TRO Q = L;
  int i = 0 ;
  do{
    HangHoa x = Q->infor;
    cout<<left<<setw(15)<<i+1<<setw(15)<<x.maHang<<setw(15)<<x.tenHang<<setw(15)<<x.dvTinh<<setw(15)<<x.donGia<<setw(15)<<x.soLuong<<setw(15)<<fixed<<setprecision(2)<<x.thanhTien<<endl;
    i++;
    Q = Q->next;

  }
  while (Q != NULL);
}

void themHH(TRO &L , HangHoa x) {
  x.tinhThanhTien();
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
  HangHoa ds[6] ={
    {"H2001", "Vo", "Quyen", 6500, 20},
    {"H2002", "But chi", "Cai", 12000, 50},
    {"H2003", "Hop but", "Chiec", 35000, 15},
    {"H2004", "Tay", "Cai", 10000, 50},
    {"H2005", "Thuoc ke", "Cai", 7000, 55},
    {"H2006", "Muc", "Lo", 15000, 28}
  };

  for(int i = 0 ; i < 6 ; i++) {
    themHH(L , ds[i]);
  }
}

void xoaptthu3(TRO &L, int k) {
  if(isEmpty(L) && k > 0 ) {
    cout<<"Danh sach rong !";
    return;
  }
  TRO Q = L;
  int count = 1;
  while (Q!= NULL && count < k-1) {
    Q = Q->next;
    count++;
  }

  if(Q==NULL || Q->next == NULL) {
    cout<<"Danh sach co it hon "<<k<<" phan tu khong the xoa !"<<endl;
    return;
  }
  TRO P = Q->next;
  Q->next = P->next;
  delete P;
}

void chenpt(TRO &L , int k ) {
  int d = 1;
  TRO P = NULL ,Q = L;
  while ( Q!= NULL && d < k) {
    P = Q;
    Q = Q->next;
    d++;
  }
  if(Q == NULL || k < 1) {
    cout<<"Vi tri khong thich hop !";
    return;
  }
  TRO A = new Node;
  strcpy(A->infor.maHang , "2007");
  strcpy(A->infor.tenHang , "Phan");
  strcpy(A->infor.dvTinh , "Hop");
  A->infor.donGia = 3000;
  A->infor.soLuong = 15;
  A->infor.thanhTien = 45000;
   if (k == 1) { // Insert at the beginning
        A->next = L;
        L = A;
    } else { // Insert at position k
        A->next = P;
        Q->next = A;
    }

}

void bubblesort(TRO &L) {
   if (L == NULL || L->next == NULL) return;
   bool swapped;
   TRO P , Q;

   do {
     swapped = false;
     P = L;
     while (P->next != NULL) {
       Q=P->next;
       if(P->infor.thanhTien > Q->infor.thanhTien) {
         HangHoa temp = P->infor;
         P->infor = Q->infor;
         Q->infor = temp;
         swapped = true;
       }
       P = P->next;
     }
   }
   while (swapped);
}
int main() {
  TRO Q , L ;
  creat(L);
  dataset4test(L);//nhapDS(L);
  hienthiDS(L);
  xoaptthu3(L , 3);
  cout<<"-----------------------------Sau khi xoa phan tu thu 3 ta co danh sach-----------------------------"<<endl;
  hienthiDS(L);
  chenpt(L , 1);
  cout<<"-----------------------------Sau khi chen phan tu thu nhat ta co danh sach-----------------------------"<<endl;
  hienthiDS(L);
  bubblesort(L);
  cout<<"-----------------------------Sau khi sap xep ta co danh sach-----------------------------"<<endl;
  hienthiDS(L);
}