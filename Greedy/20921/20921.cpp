/*BOJ 20921*/
/*Greedy*/
/*이미 사용한 숫자 제외 가장 큰 수를 고려*/
/*N개의 숫자가 있다면 가장 큰 수를 제일 앞에 둘 때 나오는 경우의 수는 N-1개*/
/*현재 이루어야 하는 쌍이 N-1개보다 크다면 가장 큰 수를 가장 앞에*/
/*현재 이루어야 하는 쌍이 N-1개보다 작다면 가장 작은 수를 가장 앞에*/
/*현재 이루어야 하는 쌍이 N-1개라면 가장 큰 수 앞에 두고 뒤에는 남은 수 오름차순으로*/
#include<iostream>
#include<vector>
using namespace std;
int N, K;
vector<int> res;
int maximum, minimum;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	maximum = N;
	minimum = 1;
	if (K == 0) {
		for (int i = 1; i <= N; i++) {
			res.push_back(i);
		}
	}
	else {
		while (1) {
			if (K == 0) {
				break;
			}
			if (K > (N - 1)) {
				res.push_back(maximum);
				maximum -= 1;
				K -= (N - 1);
				N--;
			}
			else if (K == (N - 1)) {
				res.push_back(maximum);
				for (int i = minimum; i < maximum; i++) {
					res.push_back(i);
				}
				K = 0;
			}
			else if (K < (N - 1)) {
				res.push_back(minimum);
				minimum += 1;
				N--;
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}