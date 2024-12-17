#include <iostream>
#include <vector>
#include <string>
using namespace std;

void z_algo(const char *s , int *z) {
	int n = strlen(s) , left = 0 , right = 0;
	for(int i = 1 ; i <n ; i ++) {
		if ( i>right) {
			left = right= i;
			while (right < n && s[right - left] == s[right]) {
				right++;
			}
			z[i] = right - left;
			right --;
		}
		else {
			if (z[i-left] < right - i +1) {
				z[i] = z[i-left];
			}
			else {
				left = i;
				while(right < n && s[right - left] == s[right]) {
					right++;
				}
				z[i] = right - left;
				right--;
			}
		}
	}
}
int z_app(const char*t , const char*p) {
	int p_size = strlen(p);
	int t_size = strlen(t);
	char s[p_size + t_size + 2];
	strcpy(s,p);
	strcat(s,"$");
	strcat(s,t);
	int n = strlen(s);
	int z[n] = {0};
	z_algo(s,z);
	int count = 0;
	for(int i = 0 ; i < n ; i ++) {
		if (z[i] == p_size) {
			count++;
		}
	}
	return count;
}

int main() {
     char* T = "GHP011H00HP00HP";
    char* P = "HP0";

    int count = z_app(T , P);
    
    if ( count > 0) {
    	cout<<count;
	}
	else {
		cout<<"Nah";
	}

    return 0;
}
