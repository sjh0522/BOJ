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

		// !!! �� �� !!! vector �ʱ�ȭ 
		vector<pair<int, pair<int, int>>> edges;
		               
		int res = 0;   // ���� ���� : (��ü ��� - MST)
		for (int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			edges.push_back(make_pair(z, make_pair(x, y)));
			res += z;
		}
		
		// kruskal ����
		// 1. parent �ʱ�ȭ
		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		// 2. edges �������� ����
		sort(edges.begin(), edges.end());

		// 3. ���� �ϳ��� Ȯ��
		for (int i = 0; i < edges.size(); i++) {
			int cost = edges[i].first;
			int a = edges[i].second.first;
			int b = edges[i].second.second;

			// cycle ���� ����
			if (getParent(a) != getParent(b)) {
				unionParent(a, b);
				res -= cost;
			}
		}
		// 4. ���
		printf("%d\n", res);
	}
}