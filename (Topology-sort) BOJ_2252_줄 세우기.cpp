#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

vector<int> adj[MAX];
int inDegree[MAX];

int main(void) {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);

	// 0. 입력
	for (int i = 1; i <= M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		// 0-1. 진입 차수 증가
		inDegree[e]++;
	}

	// topology sort, (아이디어) 진입차수 0 인 노드부터 탐색 //
	/* 1.   진입 차수 0 인 노드 queue에 삽입
	   2.   N 노드가 모두 queue -> result 로 가야 정상 종료, 따라서 N loop 탐색
	   2-1. queue 가 비면 cycle 발생하여 종료
	   2-2. queue에서 꺼내 간선 제거 후 result에 넣음
	   2-3. adj 노드 탐색하여 진입 차수 0인 노드 queue에 삽입 */
	
	
	// 1. 초기화 : 진입 차수 0 인 노드 queue에 삽입
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	// 2. N 노드 탐색
	for (int i = 1; i <= N; i++) {
		// 2-1. 종료조건 : queue가 비면 cycle발생
		if (q.empty()) break;

		// 2-2. currnode queue -> result
		int currnode = q.front(); q.pop();
		result.push_back(currnode);

		// 2-3. adj 탐색
		for (int j = 0; j < adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j];
			// 2-4. nextnode inDegree 간선 제거 후 queue에 삽입
			if (--inDegree[nextnode] == 0) q.push(nextnode);
		}
	}

	// 3. 결과
	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}

}
