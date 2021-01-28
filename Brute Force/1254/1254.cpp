/*BOJ 1254*/
/*Brute Force*/
#include<iostream>
#include<string>
using namespace std;
string S;
int check_palindrome(int st_idx, int ed_idx) {
	while (1) {
		if (st_idx >= ed_idx) {
			return 1;
		}
		if (S[st_idx] != S[ed_idx]) {
			return -1;
		}
		st_idx++;
		ed_idx--;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> S;
	int res = S.length();
	int end = S.length() - 1;
	int flag = 0;
	for (int i = 0; i < S.length(); i++) {
		flag = check_palindrome(i, end);
		if (flag == 1) {
			break;
		}
		res++;
	}
	cout << res;
	return 0;
}