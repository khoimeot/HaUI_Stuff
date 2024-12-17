#include<bits/stdc++.h> 
using namespace std;
int dx[] = {0 , 0 , -1 , +1};
int dy[] = {-1 , 1 , 0 , 0};
int ROWS = 5 , COLUMNS = 5;

void floodfill(vector<vector<int>> &arr , int x , int y , int newcolor) {
	if (x < 0 || y < 0 || y >= COLUMNS || x>= ROWS ||arr[x][y] != 1) return;
	arr[x][y] = newcolor;
	for(int i = 0 ; i <=4 ; i++) {
		floodfill(arr , x+ dy[i] , y+dy[i] , newcolor);
	}
}
int main() {
	 vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1}
    };
	floodfill(grid , 0 , 0 , 2);
	
	for (auto&row : grid ) {
		for(int cell : row ) {
			cout<<cell<<" ";
		}
		cout<<endl;
	}
	return 0;
}