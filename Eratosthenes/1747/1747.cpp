#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
int N;
vector<int> prime;
void Eratos(void) {
	bool check[2000001];
	memset(check, false, sizeof(check));
	for (int i = 2; i <= 2000000; i++) {
		if (check[i] == false) {
			check[i] = true;
			prime.push_back(i);
			for (int j = i * 2; j <= 2000000; j = j + i) {
				check[j] = true;
			}
		}
	}
}
int check_palindrom(int num) {
	string str = to_string(num);
	int l = 0, r = str.length() - 1;
	while (l<=r) {
		if (str[l] != str[r]) {
			return 0;
		}
		l++; r--;
	}
	return 1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	Eratos();
	for (int i = 0; i < prime.size(); i++) {
		if (prime[i] >= N) {
			if (check_palindrom(prime[i])) {
				cout << prime[i];
				break;
			}
		}
	}
	return 0;
}