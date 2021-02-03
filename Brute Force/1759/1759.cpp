#include<iostream>
#include<string>
using namespace std;
bool letter[26];
int L, C;
char input;
void make(int ja, int mo, int idx, string secret, int cnt) {
	if (cnt == L) {
		if (ja >= 2 && mo >= 1) {
			cout << secret << "\n";
		}
		return;
	}
	if (idx == 26) {
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (letter[i] == false) {
			continue;
		}
		char now = 'a' + i;
		string n = secret + now;
		if (now == 'a' || now == 'e' || now == 'i' || now == 'o' || now == 'u') {
			make(ja, mo+1, i + 1, n, cnt+1);
		}
		else {
			make(ja+1, mo, i + 1, n, cnt+1);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < 26; i++) {
		letter[i] = false;
	}
	for (int i = 0; i < C; i++) {
		cin >> input;
		letter[input - 'a'] = true;
	}
	for (int i = 0; i < 26; i++) {
		if (letter[i] == false) {
			continue;
		}
		char now = 'a' + i;
		string n = "";
		n = n + now;
		if (now == 'a' || now == 'e' || now == 'i' || now == 'o' || now == 'u') {
			make(0, 1, i + 1, n, 1);
		}
		else {
			make(1, 0, i + 1, n, 1);
		}
	}
	return 0;
}