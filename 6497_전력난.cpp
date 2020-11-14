#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int parent[200001];

int getParent(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	freopen("input.txt", "r", stdin);
	for (int test_case = 1; ; test_case++) {
		int m, n;
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) break;

		// !!! 중 요 !!! vector 초기화 
		vector<pair<int, pair<int, int>>> edges;
		               
		int res = 0;   // 문제 정답 : (전체 비용 - MST)
		for (int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			edges.push_back(make_pair(z, make_pair(x, y)));
			res += z;
		}
		
		// kruskal 시작
		// 1. parent 초기화
		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		// 2. edges 오름차순 정렬
		sort(edges.begin(), edges.end());

		// 3. 간선 하나씩 확인
		for (int i = 0; i < edges.size(); i++) {
			int cost = edges[i].first;
			int a = edges[i].second.first;
			int b = edges[i].second.second;

			// cycle 없을 때만
			if (getParent(a) != getParent(b)) {
				unionParent(a, b);
				res -= cost;
			}
		}
		// 4. 결과
		printf("%d\n", res);
	}
}