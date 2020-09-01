#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
int U, V, P;
int S, D;
int graph[500][500];
int dist[500];
vector<int> before_vertex[500];//������ vertex�� ���� �� ��ģ �ٷ� �� vertex�� �����ϴ� vector
void dijk(void) {
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({ 0, S });
	while (!heap.empty()) {
		pair<int, int> now = heap.top();
		heap.pop();
		int nw_w = now.first;
		int nw = now.second;
		for (int i = 0; i < N; i++) {
			if (nw == i || graph[nw][i] == 0) {
				continue;
			}
			if (dist[i] == -1) {//���� �ѹ��� �湮���� ���� vertex�� ���� �湮�� ��ΰ� �ּҰ�
				dist[i] = nw_w + graph[nw][i];
				heap.push({ dist[i], i });
				before_vertex[i].push_back(nw);
			}
			else if (dist[i] == nw_w + graph[nw][i]) {//���� ���� ��ο� ���� cost�� ���� �ٸ� ��ΰ� �ִ� ��� �̰ŵ� �Ǵٸ� �ִܰ���̹Ƿ� ����
				before_vertex[i].push_back(nw);
			}
			else if (dist[i] > nw_w + graph[nw][i]) {//������ �ִ� ��κ��� �� ª�� ��ΰ� ������ ���� ��δ� �� �̻� �ִ� ��ΰ� �ƴϹǷ� before_vertex�� clear�ϰ� ���Ӱ� push
				dist[i] = nw_w + graph[nw][i];
				heap.push({ dist[i], i });
				before_vertex[i].clear();
				before_vertex[i].push_back(nw);
			}
		}
	}
}
void trace_back(int now) {//������������ ������ ����������� ��� Ž��
	if (now == S) {
		return;
	}
	for (int before : before_vertex[now]) {
		graph[before][now] = 0;
		trace_back(before);
	}
}
void almost_dijk(void) {
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({ 0, S });
	while (!heap.empty()) {
		pair<int, int> now = heap.top();
		heap.pop();
		int nw_w = now.first;
		int nw = now.second;
		for (int i = 0; i < N; i++) {
			if (i == nw || graph[nw][i] == 0) {
				continue;
			}
			if (dist[i] == -1 || dist[i] > nw_w + graph[nw][i]) {
				dist[i] = nw_w + graph[nw][i];
				heap.push({ dist[i], i });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}
		cin >> S >> D;
		for (int i = 1; i <= M; i++) {
			cin >> U >> V >> P;
			graph[U][V] = P;
		}
		memset(dist, -1, sizeof(dist));
		dijk();
		trace_back(D);
		memset(dist, -1, sizeof(dist));
		almost_dijk();
		cout << dist[D] << "\n";
		for (int i = 0; i < 500; i++) {
			memset(graph[i], 0, sizeof(int) * 500);
		}
		for (int i = 0; i < 500; i++) {
			before_vertex[i].clear();
		}
	}
	return 0;
}