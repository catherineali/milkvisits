#include <iostream>
#include <vector>
using namespace std;

int n, m, path[100000], cnt = 1;
char farm[100000], type[100000];
vector <int> adj[100000];

void dfs(int v, int mark) {
	path[v] = mark;
	for (int i : adj[v]) {
		if (!path[i] && farm[i] == farm[v]) {
			dfs(i, mark);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> farm[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!path[i]) {
			dfs(i, cnt);
			type[cnt] = farm[i];
			cnt++;
		}
	}
	for (int i = 0; i < m; i++) {
		int start, end;
		char cow;
		cin >> start >> end >> cow;
		start--, end--;
		if (path[start] != path[end]) {
			cout << 1;
		}
		else {
			if (type[path[start]] == cow) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
	}
	cout << endl;
}