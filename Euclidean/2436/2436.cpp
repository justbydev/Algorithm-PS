#include<iostream>
using namespace std;
int A, B;
int euclidean(int a, int b) {
	while (b!=0) {
		int r = a % b;
		a = b;
		b = r;
	}
	if (a == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> A >> B;
	int remain = B / A;
	int one, two;
	one = two = 1e9;
	for (int i = 1; i <= remain; i++) {
		if (remain%i != 0) {
			continue;
		}
		int a = i;
		int b = remain / a;
		if (a > b) {
			break;
		}
		if (euclidean(a, b)) {
			if (one + two > A*a + A * b) {
				one = A * a;
				two = A * b;
			}
		}
	}
	cout << one << " " << two;
	return 0;
}