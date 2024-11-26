#include<bits/stdc++.h>

using namespace std;

struct SinhVien {
  char maSV[15];
  char hoDem[15];
  char ten[15];
  char gioiTinh[5];
  int namSinh;
  float diemTK;
};
struct Node {
  SinhVien infor;
  Node *next;
};

typedef Node *TRO;
void creat(TRO &l) {
  l = NULL;
}
int empty(TRO L) {
  return L == NULL;
}
//void travel(TRO L) {
//  TRO Q;
//  if(!empty(L)) {
//    Q=L;
//    while(Q != NULL) {
//      Q = Q->next;
//    }
//  }
//  else {
//    cout<<"Danh sach rong !";
//  }
//}
void nhapSV(SinhVien &sv) {
  cout<<"Nhap ma sinh vien : ";fflush(stdin); gets(sv.maSV);
  cout<<"Nhap ho dem : ";fflush(stdin); gets(sv.hoDem);
  cout<<"Nhap ten : ";fflush(stdin); gets(sv.ten);
  cout<<"Nhap gioi tinh : ";fflush(stdin); gets(sv.gioiTinh);
  cout<<"Nhap nam sinh : ";cin>>sv.namSinh;
  cout<<"Nhap diem tong ket : ";cin>>sv.diemTK;

}

void nhapDS(TRO &l) {
  SinhVien sv;
  TRO Q , P;
  Q = NULL;
  int i = 1;
  char a = 'C';
  do {

    cout<<"Ban muon nhap thong tin sinh vien tiep khong ?(C/K) : ";cin>>a;
    if(a != 'C') {
      return;
    }
    cout<<"Nhap sinh vien thu "<<i<<" : "<<endl;
    nhapSV(sv);

    P = new(Node);
    P->infor = sv;
    P->next = NULL;
    if(l == NULL) l = P;
    else Q->next = P;
    Q = P ;
    i++;
  }
  while(i);
}
void hienthiDS(TRO L) {
  if (L == NULL ) {
    cout<<"Danh sach trong !" ;
    return;

  }

	cout <<setw(5)<<"STT"<<setw(15)<<"Ma SV"<<setw(20)<<"Ho dem"<<setw(15)<<"Ten"<<setw(15)<<"Gioi tinh"<<setw(10)<<"Nam sinh"<<setw(10)<<"Diem TK"<<endl;
  TRO Q = L;
  int i = 0;
  do {
    SinhVien sv = Q->infor;
		cout <<setw(5)<<i+1<<setw(15)<<sv.maSV<<setw(20)<<sv.hoDem<<setw(15)<<sv.ten<<setw(15)<<sv.gioiTinh<<setw(10)<<sv.namSinh<<setw(10)<<sv.diemTK<<endl;
    i++;
    Q = Q->next;
  }
  while(Q !=NULL);
}
void themSV(TRO &l , SinhVien sv) {
  TRO P = new Node;
  P->infor  = sv;
  P->next = NULL;

  if(l == NULL ){
    l = P;
  }
  else {
    TRO Q = l;
    while(Q->next != NULL) {
      Q = Q->next;
    }
    Q->next = P;
  }
}
void dataset4test(TRO& L) {
    // Dữ liệu mẫu
    SinhVien ds[5] = {
        {"SV1001", "Tran Van", "Thanh", "Nam", 1999, 7.5},
        {"SV1002", "Nguyen Thi", "Huong", "Nu", 2000, 7.3},
        {"SV1003", "Nguyen Van", "Binh", "Nam", 1998, 6.4},
        {"SV1004", "Bui Thi", "Hong", "Nu", 2000, 5.8},
        {"SV1005", "Duong Van", "Giang", "Nam", 1998, 8.3},
    };

    // Thêm từng sinh viên vào danh sách
    for (int i = 0; i < 5; i++) {
        themSV(L, ds[i]);
    }
}

void xoaptdautien(TRO &l) {
  if( l == NULL) {
    cout<<"Danh sach rong !";
    return;
  }
  TRO Q = l;
  l = l->next;
  delete Q;
}

void chenVTT3(TRO &l) {
  int d = 1 ;
  TRO M,Q = l;
  while (Q!= NULL && d< 3) {
    M = Q;
    Q = Q->next;
    d++;
  }
  if(Q == NULL) {
    cout<<"\t Vi tri khong thich hop !";
    return;
  }
  TRO P = new Node;
 strcpy(P->infor.maSV, "1006");
 strcpy(P->infor.hoDem, "Le Thi");
 strcpy(P->infor.ten, "Doan");
 strcpy(P->infor.gioiTinh, "Nu");
 P->infor.namSinh = 1998;
 P->infor.diemTK = 7.6;
 P->next = M->next;
 M->next = P;
//1	-2	-3	-4	-5-	6-	7-null
//MQ								            d = 1
//M	 Q							              d = 2
//	 M   Q						            d = 3 => dừng tt

}

void sapxep(TRO &l) {
  SinhVien tg;
  TRO M , Q , R;
  R = l;
  while (R->next != NULL) {
    M = R;
    Q = R->next;
    while(Q != NULL ) {
      if(strcmp(Q->infor.ten , M->infor.ten) < 0) {
        M = Q;
      }
      Q= Q->next;
    }
    tg = R->infor;
    R->infor = M->infor;
    M->infor = tg;
    R= R->next;
  }
}
int main() {
  TRO L,P;
  creat(L);
  dataset4test(L);//nhapDS(L);
  hienthiDS(L);
  xoaptdautien(L);
  cout<<"----------------------------Sau khi xoa phan tu dau tien thi ta duoc danh sach----------------------------"<<endl;
  hienthiDS(L);
  chenVTT3(L);
  cout<<"----------------------------Sau khi chen phan tu thi ta duoc danh sach----------------------------"<<endl;
  hienthiDS(L);
  sapxep(L);
  cout<<"----------------------------Sau khi sap xep thi ta duoc danh sach----------------------------"<<endl;
  hienthiDS(L);
}