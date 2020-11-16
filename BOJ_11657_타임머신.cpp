#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#define INF 1e18
#define MAX 501
using namespace std;

long long dist[MAX];
vector<pair<int, int>> adj[MAX];

int main(void) {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
	}

	// 벨만-포드 시작 //
	// k번째 루프에서는 시작점으로부터 각 정점으로 k개의 간선을 거쳐서 도달할 수 있는 최단경로를 다 갱신 //
	// 1. 자료 구조 초기화
	bool minusCycle = false;
	fill(dist, dist + N + 1, INF);
	dist[1] = 0;

	// 2. 가능한 최단 경로는 최대 (N-1)개 간선 지남
	//    (N-1) 루프 + minusCycle 존재 여부 확인
	for (int k = 1; k <= N; k++) {
		// 2-1. (N-1) 루프에 걸쳐 각 정점이 k개 간선을 거쳐오는 최단경로 갱신
		for (int currNode = 1; currNode <= N; currNode++) {
			for (int j = 0; j < adj[currNode].size(); j++) {
				int nextNode = adj[currNode][j].first;
				int currToNextNodeDist = adj[currNode][j].second;
				// 2-2. currNode 가 INF 이면 의미가 없음
				if (dist[currNode] != INF && dist[nextNode] > dist[currNode] + currToNextNodeDist) {
					dist[nextNode] = dist[currNode] + currToNextNodeDist;
					// 2-2. N번째 루프에 값이 갱신되면 minusCycle 존재
					if (k == N) minusCycle = true;
				}
			}
		}
	}
	if (minusCycle) puts("-1");
	else {
		for (int i = 2; i <= N; i++)
			printf("%lld\n", dist[i] != INF ? dist[i] : -1);
	}
}