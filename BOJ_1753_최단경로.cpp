#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define MAX 20001
#define INF 1000000000
using namespace std;

int dist[MAX];
vector<pair<int, int>> adj[MAX];

int main(void) {
	freopen("input.txt", "r", stdin);
	int V, E, K;
	scanf("%d %d %d", &V, &E, &K);

	// 0. 입력
	for (int i = 1; i <= E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}

	// dijkstra 시작 //
	// 1-1. 시작점 초기화
	fill(dist, dist + V + 1, INF);
		
	// 1-2. 시작점 queue에 삽입
	priority_queue<pair<int, int>> pq;
	dist[K] = 0; 
	pq.push(make_pair(0, K));  // (w, n)

	// 2. pq가 빌 때까지 adj 노드 탐색
	while (!pq.empty()) {
		int currnode = pq.top().second;
		int distAtCurrnode = -pq.top().first;
		pq.pop();

		if (dist[currnode] < distAtCurrnode) continue;

		for (int j = 0; j < adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j].first;
			int distFromCurrnodeToNextnode = adj[currnode][j].second;
			if (dist[nextnode] > dist[currnode] + distFromCurrnodeToNextnode) {
				dist[nextnode] = dist[currnode] + distFromCurrnodeToNextnode;
				pq.push(make_pair(-dist[nextnode], nextnode));
			}
		}
	}

	// 3. 결과
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}
