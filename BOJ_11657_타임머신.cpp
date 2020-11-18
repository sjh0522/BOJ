#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#define INF 1e18
#define MAX 501
using namespace std;

long long dist[MAX];
vector<pair<int, int>> adj[MAX];

int main(void) {
	//freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);

	// 0. 입력
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
	}

	// 벨만-포드, (아이디어) 최소거리는 최대 (N-1) 개의 간선을 지남 //
	/* 1.   출발 노드 선택
	   2-1. n번째 loop에서 n개의 간선을 거쳐 도달하는 최소 거리 갱신
	   2-2. N번째 loop에 값이 갱신되면 minus-cycle 존재
	   3.   2중 for문으로 모든 i->j 탐색 */
	   
	// 1. 시작점 초기화
	fill(dist, dist + N + 1, INF);
	bool minusCycle = false;
	dist[1] = 0;

	// 2-1. (N-1) loop + minusCycle 확인
	for (int n = 1; n <= N; n++) {
		// 2-2. currnode 탐색
		for (int currnode = 1; currnode <= N; currnode++) {
			// 2-3. adj 탐색
			for (int j = 0; j < adj[currnode].size(); j++) {
				int nextnode = adj[currnode][j].first;
				int distFromCurrnodeToNextnode = adj[currnode][j].second;
				// 2-4. 최소값 갱신, currnode가 INF이면 의미 없음
				if (dist[currnode] != INF && dist[nextnode] > dist[currnode] + distFromCurrnodeToNextnode) {
					dist[nextnode] = dist[currnode] + distFromCurrnodeToNextnode;
					//2-5. minusCycle 여부 확인, N번째 루프에 값이 갱신되면 minusCycle 존재
					if (n == N) minusCycle = true;
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
