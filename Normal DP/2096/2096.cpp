#include<iostream>
#include<algorithm>
using namespace std;
int N;
int num[100000][3];
int mx[3];
int mn[3];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i][0] >> num[i][1] >> num[i][2];
	}
	mx[0] = mn[0] = num[0][0];
	mx[1] = mn[1] = num[0][1];
	mx[2] = mn[2] = num[0][2];
	int one, two, three;
	for (int i = 1; i < N; i++) {
		one = mx[0]; two = mx[1]; three = mx[2];
		mx[0] = num[i][0] + max(one, two);
		mx[1] = num[i][1] + max(one, max(two, three));
		mx[2] = num[i][2] + max(two, three);
		one = mn[0]; two = mn[1]; three = mn[2];
		mn[0] = num[i][0] + min(one, two);
		mn[1] = num[i][1] + min(one, min(two, three));
		mn[2] = num[i][2] + min(two, three);
	}
	cout << max(mx[0], max(mx[1], mx[2])) << " " << min(mn[0], min(mn[1], mn[2]));
	return 0;
}