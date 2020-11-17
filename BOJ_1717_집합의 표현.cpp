#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX 1000001
using namespace std;

int parent[MAX];
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

int main(void) {
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);

	// 0-1. parent �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	// 0-2. �Է�
	for (int i = 1; i <= m; i++) {
		int x, a, b;
		scanf("%d %d %d", &x, &a, &b);

		// 1. ������
		if (x == 0) unionParent(a, b);
		// 2. �θ� ������ Ȯ��
		else if (x == 1) {
			if (getParent(a) == getParent(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}