#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef struct _point {
	int x1, y1, x2, y2;
	int time;
	int type;
}point;
vector<point> edge;
int W, H;
int G, X, Y;
int E, X1, Y1, X2, Y2, T;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
point arr[30][30];
int dist[30][30];
int bellman_ford(void) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			dist[i][j] = 1e9;
		}
	}
	dist[0][0] = 0;
	for (int i = 1; i <= W * H; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int stx = edge[j].x1;
			int sty = edge[j].y1;
			int edx = edge[j].x2;
			int edy = edge[j].y2;
			int time = edge[j].time;
			if (dist[stx][sty] == 1e9) {
				continue;
			}
			if (dist[edx][edy] > dist[stx][sty] + time) {
				if (i == W * H) {
					return -1;
				}
				dist[edx][edy] = dist[stx][sty] + time;
			}
		}
	}
	return 1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0) {
			break;
		}
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				arr[i][j] = { 0, 0, 0, 0, 0, 0 };
			}
		}
		cin >> G;
		for (int i = 0; i < G; i++) {
			cin >> X >> Y;
			arr[Y][X].type = -1;
		}
		cin >> E;
		for (int i = 0; i < E; i++) {
			cin >> X1 >> Y1 >> X2 >> Y2 >> T;
			arr[Y1][X1] = { Y1, X1, Y2, X2, T, 1 };
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == H - 1 && j == W - 1) {
					continue;
				}
				if (arr[i][j].type == -1) {
					continue;
				}
				if (arr[i][j].type == 1) {
					edge.push_back({ i, j, arr[i][j].x2, arr[i][j].y2, arr[i][j].time, 1 });
					continue;
				}
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
						continue;
					}
					if (arr[nx][ny].type == -1) {
						continue;
					}
					edge.push_back({ i, j, nx, ny, 1, 0 });
				}
			}
		}
		int flag = bellman_ford();
		if (flag == -1) {
			cout << "Never" << "\n";
		}
		else {
			if (dist[H - 1][W - 1] == 1e9) {
				cout << "Impossible" << "\n";
			}
			else {
				cout << dist[H - 1][W - 1] << "\n";
			}
		}
		edge.clear();
	}
	return 0;
}