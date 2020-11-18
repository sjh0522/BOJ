#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX 21
using namespace std;

int val[MAX];
int N, S;
int cnt, sumAtPrev;
void dfs(int curr) {
	// 0. ������
	if (curr == N) return;

	// 1. ������� ���� S �� cnt++
	if (sumAtPrev + val[curr] == S) cnt++;

	// 2-1. curr�� ���� X
	dfs(curr + 1);

	// 2-2. curr�� ���� O
	sumAtPrev += val[curr];
	dfs(curr + 1);

	// 3. ����
	sumAtPrev -= val[curr];
}
int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &S);
	
	// 0. �Է�
	for (int i = 1; i <= N; i++) {
		scanf("%d", &val[i]);
	}

	// dfs //
	dfs(1);
	printf("%d", cnt);
}
