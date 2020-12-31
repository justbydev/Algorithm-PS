/*BOJ 9019 DSLR*/
/*using BFS*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n, T;
int A, B;
queue<string> res;
queue<int> number;
int visit[10000];//to solve time/space exceed
int D(int num) {
	return (num * 2) % 10000;
}
int S(int num) {
	num -= 1;
	if (num == -1) {
		num = 9999;
	}
	return num;
}
int L(int num) {
	return (num % 1000) * 10 + (num / 1000);
}
int R(int num) {
	return (num % 10) * 1000 + (num / 10);
}
string bfs(int A, int B) {
	while (!res.empty()) {
		res.pop();
	}
	while (!number.empty()) {
		number.pop();
	}
	for (int i = 0; i < 10000; i++) {
		visit[i] = 0;
	}
	number.push(A);
	res.push("");
	visit[A] = 1;
	while (1) {
		string now = res.front();
		res.pop();
		int now_num = number.front();
		number.pop();
		int d, s, l, r;
		d = D(now_num);
		s = S(now_num);
		l = L(now_num);
		r = R(now_num);
		if (d == B) {
			return now + "D";
		}
		else {
			if (visit[d] == 0) {
				res.push(now + "D");
				number.push(d);
				visit[d] = 1;
			}
		}
		if (s == B) {
			return now + "S";
		}
		else {
			if (visit[s] == 0) {
				res.push(now + "S");
				number.push(s);
				visit[s] = 1;
			}
		}
		if (l == B) {
			return now + "L";
		}
		else {
			if (visit[l] == 0) {
				res.push(now + "L");
				number.push(l);
				visit[l] = 1;
			}
		}
		if (r == B) {
			return now + "R";
		}
		else {
			if (visit[r] == 0) {
				res.push(now + "R");
				number.push(r);
				visit[r] = 1;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << bfs(A, B) << "\n";
	}
	return 0;
}