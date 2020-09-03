#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N;
vector<int> prime;
bool num[4000001];
void erasto(void) {
	for (int i = 0; i <= 4000000; i++) {
		num[i] = true;
	}
	for (int i = 2; i <= N; i++) {
		if (num[i] == true) {
			prime.push_back(i);
			for (int j = 2 * i; j <= N; j = j + i) {
				num[j] = false;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	if (N == 1) {
		cout << 0;
	}
	else if (N == 2) {
		cout << 1;
	}
	else {
		erasto();
		int l, r, end, sm, res;
		l = r = res = 0;
		end = prime.size() - 1;
		sm = prime[l];
		while (1) {
			if (sm == N) {
				res++;
				if (r == end) {
					break;
				}
				sm -= prime[l++];
				sm += prime[++r];
			}
			else if (sm < N) {
				if (r == end) {
					break;
				}
				sm += prime[++r];
			}
			else if (sm > N) {
				if (l == r) {
					break;
				}
				sm -= prime[l++];
			}
		}
		cout << res;
	}
	return 0;
}