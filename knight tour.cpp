#include<bits/stdc++.h>

using namespace std;
const int N = 8; // Kích thước bàn cờ
const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x , int y , vector<vector<int>> &arr) {
	return x >= 0 && y >= 0 && x < N && y < N && arr[x][y] == -1;
}

bool knightTour(int x , int y , int move , vector<vector<int>> &arr) {
	if (move == N*N) return true;
	for(int i = 0 ; i < 8 ; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if (isValid(nx , ny , arr)) {
			arr[nx][ny] = move ;
			if(knightTour(nx , ny , move +1 , arr)) return true;
			arr[nx][ny]=-1;
		}
	}
	return false;
}

int main() {
	vector<vector<int>> arr(N , vector<int>(N , -1));
	arr[1][2] = 0;
	
	if(knightTour(0 , 0 , 1 , arr)) {
		for (auto &row : arr) {
			for ( int cell : row) {
				cout<<cell<<" ";
			}
			cout<<endl;
		}
	}
	else {
		cout<<"dcu lam gi co cai j";
	}
}