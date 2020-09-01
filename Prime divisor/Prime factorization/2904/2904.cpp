#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
map<int, int> prime;
map<int, int> each_prime[100];
int N, input;
vector<int> number;
void prime_divisor(int num, int idx) {//소인수분해 하는 함수
	for (int div = 2; div <= sqrt(num); div++) {
		if (num%div == 0) {
			if (prime.find(div) == prime.end()) {
				prime[div] = 1;
			}
			else {
				prime[div]++;
			}
			if (each_prime[idx].find(div) == each_prime[idx].end()) {
				each_prime[idx][div] = 1;
			}
			else {
				each_prime[idx][div]++;
			}
			num = num / div;
			div--;
		}
	}
	if (num != 1) {
		if (prime.find(num) == prime.end()) {
			prime[num] = 1;
		}
		else {
			prime[num]++;
		}
		if (each_prime[idx].find(num) == each_prime[idx].end()) {
			each_prime[idx][num] = 1;
		}
		else {
			each_prime[idx][num]++;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		number.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		prime_divisor(number[i], i);
	}
	int result = 1;
	int res_cnt = 0;
	for (auto it : prime) {
		int p = it.first;
		int cnt = it.second;
		int each_cnt = cnt / N;
		if (each_cnt <= 0) {
			continue;
		}
		for (int i = 1; i <= each_cnt; i++) {
			result *= p;
		}
		for (int i = 0; i < N; i++) {
			if (each_prime[i][p] < each_cnt) {
				res_cnt += (each_cnt - each_prime[i][p]);
			}
		}
	}
	cout << result << " " << res_cnt;
	return 0;
}