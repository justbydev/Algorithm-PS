/*BOJ 3019*/
/*Brute force*/
#include<iostream>
using namespace std;
int C, P;
int height[100];
int res;
int st, ed;
void te1(void) {
	res += C;
	if (C >= 4) {
		st = 0; ed = 3;
		while (1) {
			if (ed == C) {
				break;
			}
			if ((height[st] == height[st + 1])&&(height[st+1] == height[ed - 1])&&
				(height[ed-1]== height[ed])) {
				res++;
			}
			st++; ed++;
		}
	}
}
void te2(void) {
	if (C >= 2) {
		st = 0; ed = 1;
		while (1) {
			if (ed == C) {
				break;
			}
			if (height[st] == height[ed]) {
				res++;
			}
			st++; ed++;
		}
	}
}
void te3(void) {
	if (C >= 3) {
		st = 0; ed = 2;
		while (1) {
			if (ed == C) {
				break;
			}
			if ((height[st] == height[st + 1]) && (height[st + 1] + 1 == height[ed])) {
				res++;
			}
			st++; ed++;
		}
	}
	if (C >= 2) {
		st = 0; ed = 1;
		while (1) {
			if (ed == C) {
				break;
			}
			if (height[st] - 1 == height[ed]) {
				res++;
			}
			st++; ed++;
		}
	}
}
void te4(void) {
	if (C >= 3) {
		st = 0; ed = 2;
		while (1) {
			if (ed == C) {
				break;
			}
			if ((height[st] - 1 == height[st + 1]) && (height[st + 1] == height[ed])) {
				res++;
			}
			st++; ed++;
		}
	}
	if (C >= 2) {
		st = 0; ed = 1;
		while (1) {
			if (ed == C) {
				break;
			}
			if (height[st] + 1 == height[ed]) {
				res++;
			}
			st++; ed++;
		}
	}
}
void te5(void) {
	if (C >= 3) {
		st = 0; ed = 2;
		while (1) {
			if (ed == C) {
				break;
			}
			if ((height[st] == height[st + 1])&&(height[st+1] == height[ed])) {
				res++;
			}
			if ((height[st] == height[ed]) && (height[st + 1] + 1 == height[ed])) {
				res++;
			}
			st++; ed++;
		}
	}
	if (C >= 2) {
		st = 0; ed = 1;
		while (1) {
			if (ed == C) {
				break;
			}
			if (height[st] + 1 == height[ed]) {
				res++;
			}
			if (height[st] - 1 == height[ed]) {
				res++;
			}
			st++; ed++;
		}
	}
}
void te6(void) {
	if (C >= 3) {
		st = 0; ed = 2;
		while (1) {
			if (ed == C) {
				break;
			}
			if ((height[st] == height[st + 1])&&(height[st+1] == height[ed])) {
				res++;
			}
			if ((height[st] + 1 == height[st + 1]) && (height[st + 1] == height[ed])) {
				res++;
			}
			st++; ed++;
		}
	}
	if (C >= 2) {
		st = 0; ed = 1;
		while (1) {
			if (ed == C) {
				break;
			}
			if (height[st] == height[ed]) {
				res++;
			}
			if (height[st] - 2 == height[ed]) {
				res++;
			}
			st++; ed++;
		}
	}
}
void te7(void) {
	if (C >= 3) {
		st = 0; ed = 2;
		while (1) {
			if (ed == C) {
				break;
			}
			if ((height[st] == height[st + 1])&&(height[st+1] == height[ed])) {
				res++;
			}
			if ((height[st] == height[st + 1]) && (height[st + 1] - 1 == height[ed])) {
				res++;
			}
			st++; ed++;
		}
	}
	if (C >= 2) {
		st = 0; ed = 1;
		while (1) {
			if (ed == C) {
				break;
			}
			if (height[st] == height[ed]) {
				res++;
			}
			if (height[st] + 2 == height[ed]) {
				res++;
			}
			st++; ed++;
		}
	}
}
int  main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> C >> P;
	for (int i = 0; i < C; i++) {
		cin >> height[i];
	}
	res = 0;
	if (P == 1)te1();
	else if (P == 2)te2();
	else if (P == 3)te3();
	else if (P == 4)te4();
	else if (P == 5)te5();
	else if (P == 6)te6();
	else if (P == 7)te7();
	cout << res;
	return 0;
}