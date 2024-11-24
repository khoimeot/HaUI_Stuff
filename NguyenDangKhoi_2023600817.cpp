#include<bits/stdc++.h>
using namespace std;


struct SinhVien{
 	char maSV[10];
	char hoDem[20];
	char ten[10];
	char gioiTinh[3];
	int namSinh;
	float diemTK;
};
struct Node{
 	SinhVien infor;
 	Node *next;
};
typedef Node *TRO;
void creat(TRO &L) {
	L = NULL;
}
void nhapSV(SinhVien &sv) {
	cout <<"\nNhap thong tin sinh vien " <<endl;
	cout <<"Nhap ma sinh vien: ";
	fflush(stdin);
	gets(sv.maSV);
	cout <<"Nhap ho dem sinh vien: ";
	fflush(stdin);
	gets(sv.hoDem);
	cout <<"Nhap ten: ";
	fflush(stdin);
	gets(sv.ten);
	cout <<"Nhap Gioi tinh: ";
	fflush(stdin);
	gets(sv.gioiTinh);
	cout <<"Nhap nam sinh: ";
	cin >> sv.namSinh;
	cout <<"Nhap diem TK: ";
	cin >> sv.diemTK;
}

void nhapDS(TRO &L){
	creat(L);
	SinhVien sv;
	TRO Q,P;
	int i = 1;
	do{
		cout <<"\nNhap sinh vien thu: " << i;
		nhapSV(sv);
		if(strcmp(sv.maSV,"000") == 0)
			return;
		P = new(Node);
		P->infor = sv;
		P->next = NULL;
		if(L == NULL)
			L = P;
		else
			Q->next = P;
		Q = P;
		i++;
	} 
	while(i);
}

void hienThiDS(TRO L){
	if(L == NULL){
		cout <<"Danh sach trong "<<endl;
		return;
	}
	
	cout <<setw(5)<<"STT"<<setw(10)<<"Ma SV"<<setw(10)<<"Ho dem"<<setw(10)<<"Ten"<<setw(15)<<"Gioi tinh"<<setw(10)<<"Nam sinh"<<setw(10)<<"Diem TK"<<endl;
	TRO Q = L;
	int i = 0;
	while(Q != NULL)
	{
		SinhVien sv = Q->infor;
		cout <<setw(5)<<i+1<<setw(10)<<sv.maSV<<setw(10)<<sv.hoDem<<setw(10)<<sv.ten<<setw(15)<<sv.gioiTinh<<setw(10)<<sv.namSinh<<setw(10)<<sv.diemTK<<endl;
		i++;
		Q = Q->next;
	}
}

int empty(TRO L) {
	return L == NULL;
}
void travel(TRO L) {
	TRO Q;
	if(!empty(L)) {
		Q = L;
		while(Q != NULL) {
			Q = Q->next;
		}
	}
}

TRO search(TRO L) {
	TRO Q = L;
	while (Q != NULL  ) {
		Q = Q -> next;
		
	}
	return Q;
}

void firstAdd(TRO &L , SinhVien elem) {
	TRO P;
	P = new Node;
	P->infor = elem;
	P->next = L;
	L=P;
}

void add(TRO &L , SinhVien elem) {
	TRO P , Q;
	P = new Node; P->infor = elem;
	P->next = NULL;
	if(!empty(L)) L = P;
	else {
		Q = L;
		while (Q->next != NULL) {
			Q = Q->next;
		}
		Q->next = P;
	}
}
void insert(TRO &L , TRO Q , SinhVien elem) {
	TRO P;
	P = new Node;
	P->infor = elem;
	P->next = Q->next;
	Q->next = P;
}

void firstDelete(TRO &L) {
	TRO Q;
	Q = L;
	L = L ->next;
	delete Q;
}

void after_delete(TRO &L , TRO M) {
	TRO Q;
	Q = M->next;
	M->next = Q->next;
	delete Q;
}

void input_list(TRO &L ) {
	TRO P , Q ;
	SinhVien elem;
	char tieptuc;
	creat(L);
	do{
//		input(elem);
		P = new Node;
		P->infor = elem ;
		P->next = NULL;
		if(L== NULL) L=P;
		else Q->next=P;
		Q=P;
		cout<<"Nhap tiep khong ? ( C/K ) :";
		cin>>tieptuc;
	}
	while(toupper(tieptuc)=='C');
}

void selectionsort(TRO &L) {
	for(TRO i = L ; i!=NULL ; i=i->next) {
		TRO minNode = i;
		for(TRO j = i->next ; j != NULL ; j = j->next) {
			if(strcmp(j->infor.ten , minNode->infor.ten) <0) {
				minNode = j;
			}
		}
		if(minNode != i) {
			SinhVien temp = i->infor;
			i->infor = minNode->infor;
			minNode->infor = temp;
		}
	}
}
int main() {
	TRO L,P;
	nhapDS(L);
	cout<<endl<<endl<<endl<<endl;
	hienThiDS(L);
	cout<<"--------------------XOA PHAN TU DAU TIEN---------------------------"<<endl;
	firstDelete(L);
	hienThiDS(L);
	cout<<"--------------------CHEN PHAN TU VAO DANH SACH---------------------------"<<endl;
	SinhVien elem ;
	strcpy(elem.maSV,"1006");
	strcpy(elem.hoDem , " Le Thi");
	strcpy(elem.ten , "Doan");
	strcpy(elem.gioiTinh , "Nu");
	elem.namSinh = 1999;
	elem.diemTK = 7.6;
	TRO Q = L;
	int count = 1;
	while (Q!= NULL && count < 2) {
		Q = Q->next;
		count++;
	}
	if (Q == NULL) {
		cout<<"Khong tim tay vi tri ";
		return 0;
	}
	insert(L , Q , elem);
	hienThiDS(L);
	cout<<"--------------------SAP XEP THEO CHIEU TANG DAN CUA TEN SINH VIEN---------------------------"<<endl;
	selectionsort(L);
	hienThiDS(L);
	
	
}