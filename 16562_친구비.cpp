#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int parent[10001];
int cost[10001];

int getParent(int a) {
	if (parent[a] == a)return a;
	else return parent[a] = getParent(parent[a]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	// parent�� ������ cost�� ���� ���� parent�� ��
	if (cost[a] < cost[b]) parent[b] = a;
	else parent[a] = b;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	//cost �Է�
	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
	}

	//parent �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	
	//union
	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		unionParent(a, b);
	}
		
	int sumOfCost = 0;
	for (int i = 1; i <= N; i++) {
		if (parent[i] == i) sumOfCost += cost[i];
	}
	if (sumOfCost <= K) {
		printf("%d", sumOfCost);
	}else {
		printf("Oh no");
	}
}