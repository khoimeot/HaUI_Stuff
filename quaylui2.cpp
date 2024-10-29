#include<bits/stdc++.h>
using namespace std;
const int N = 7; 
const int K = 6; 

void quaylui(char S[], char tohop[], int batdau, int sau) {
    if (sau == K) {
        for (int i = 0; i < K; i++) {
            cout << tohop[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = batdau; i < N; i++) {
        tohop[sau] = S[i];  
        quaylui(S, tohop, i + 1, sau + 1);  
    }
}
int main() {
    char S[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char tohop[K];
    quaylui(S, tohop, 0, 0);
}