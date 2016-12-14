// [ti.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> >adj;
vector<bool> used;

void dfs(int v) 
{
	if (used[v])
		return;
	used[v] = true;
	cout << v << " ";
	for (int i = 0; i < adj[v].size(); i++) 
	{
		int u = adj[v][i];
		dfs(u);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	used.resize(n);
	for (int j = 0; j < m; j++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	system("pause");
    return 0;
}

/*11 13
0 1
0 2
1 3
1 4
2 5
2 6
3 7
3 8
4 8
5 9
5 10
6 9
6 10*/
