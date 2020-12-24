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

	// dijkstra 시작, (아이디어) priority_queue사용하여 짧은 것부터 //
	/* 1. 출발 노드 선택
	   2. adj 노드의 최소 거리 갱신
	   3. queue에 있는 노드 중 거리가 가장 짧은 노드 선택
	   4. 해당 노드를 거쳐서 adj 노드 탐색 */
	
	// 1. 초기화
	fill(dist, dist + V + 1, INF);
	
	// 1.1 시작점 pq에 삽입
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, K));
	dist[K] = 0;

	// 2. queue가 빌 때까지
	while (!q.empty()) {
		int currnode = q.top().second;
		int distToCurrnode = -q.top().first;
		q.pop();

		// 2-1. skip 조건 (currnode까지 다른 경로의 최단거리가 있을 경우 skip)
		if (dist[currnode] < distToCurrnode) continue;

		// 2-2. adj 탐색
		for (int j = 0; j < adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j].first;
			int disFromCurrnodeToNextnode = adj[currnode][j].second;
			// 2.3 최소값 비교
			if (dist[nextnode] > dist[currnode] + disFromCurrnodeToNextnode) {
				dist[nextnode] = dist[currnode] + disFromCurrnodeToNextnode;
				q.push(make_pair(-dist[nextnode], nextnode));
			}
		}
	}

	// 3. 결과
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}
