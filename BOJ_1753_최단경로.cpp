#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define MAX 20001
#define INF 1000000000
using namespace std;

vector<pair<int, int>> adj[MAX];
int dist[MAX];

void dijkstra(int start) {
	// 2-1. pq 생성, start 노드 pq에 삽입
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	// dijkstra 탐색 시작
	while (!pq.empty()) {
		// 2-2. curr 노드부터 시작
		int currNode = pq.top().second;
		int distAtCurrNode = -pq.top().first;
		pq.pop();

		// 2-3. curr 간선의 dist가 지금까지 찾은 curr 의 dist보다 크면 skip
		if (dist[currNode] < distAtCurrNode) continue;

		// 2.4 curr의 adj 노드 탐색
		for (int j = 0; j < adj[currNode].size(); j++) {
			int nextNode = adj[currNode][j].first;
			int currToNextDist = adj[currNode][j].second;

			// 2-5. curr -> nextNode 경로가 더 짧은 경우
			if (dist[nextNode] > dist[currNode] + currToNextDist) {
				dist[nextNode] = dist[currNode] + currToNextDist;
				pq.push(make_pair(-dist[nextNode], nextNode));
			}
		}
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int V, E, K;
	scanf("%d %d %d", &V, &E, &K);
	//printf("%d %d %d\n", V, E, K);
	
	for (int i = 1; i <= E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		//printf("%d %d %d\n", u, v, w);
		adj[u].push_back(make_pair(v, w));
	}
	
	// dijkstra 시작 //
	// 1. 결과 저장 배열 초기화
	fill(dist, dist + V + 1, INF);

	// 2. dijkstra
	dijkstra(K);

	// 3. 결과
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}