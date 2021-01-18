/*BOJ 2825*/
/*bit mask*/
/*모든 숫자를 0~9의 10자리로 이루어진 이진수로 표현 가능*/
/*이렇게 변환된 수는 최대 1023*/
/*입력받는 수의 범위가 10^18이기에 long long int 필요*/
/*정답 역시 N<=1000000이기 때문에 int 범위 넘어갈 가능성 농후*/
/*따라서 정답 역시 long long int*/
/*중간 중간 연산 long long int 캐스팅 안하면*/
/*중간값이 int 범위 넘어가는 순간 overflow 생겨서 이상한 값이 들어가기 때문에*/
/*오류 발생하므로 연산 전 각각의 중간 값들도 전부 long long int 캐스팅 필요*/
#include<iostream>
using namespace std;
int num[1024];
int N;
long long int input;
int change_to_tenbit(long long int now) {
	int ret = 0;
	while (1) {
		if (now <= 0) {
			break;
		}
		int now_digit = (1 << (now % 10));
		if (!(ret&now_digit)) {
			ret += now_digit;
		}
		now = now / 10;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 1023; i++) {
		num[i] = 0;
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		num[change_to_tenbit(input)]++;
	}
	long long int res = 0;
	for (int i = 1; i <= 1023; i++) {
		if (num[i]) {
			res += (long long int)num[i] * (long long int)(num[i] - 1) / 2;
			for (int j = i + 1; j <= 1023; j++) {
				if (num[j] && (i&j)) {
					res += (long long int)num[i] * (long long int)num[j];
				}
			}
		}
	}
	cout << res;
	return 0;
}