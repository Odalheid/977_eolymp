#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> adj_matrix;
vector <int> used;

void dfs(const int &p, const int &vertex) {
	++used[vertex];
	if (used[vertex] > 1) return;
	for (int i = 0; i < used.size(); ++i) {
		if (adj_matrix[vertex][i] && i != p) {
			dfs(vertex, i);
		}
	}
}

int main()
{
	int vertices;
	cin >> vertices;
	adj_matrix.resize(vertices);
	used.resize(vertices, 0);
	for (int i = 0; i < vertices; ++i) {
		vector<int>v(vertices);
		for (int j = 0; j < vertices; ++j) {
			int a; cin >> a;
			v[j] = a;
		}
		adj_matrix[i] = v;
	}
	int counter = 0;
	dfs(-1, 0);
	for (int i = 0; i < vertices; ++i) {
		if (used[i] != 1) ++counter;
	}
	if (counter != 0) cout << "NO";
	else cout << "YES";
    return 0;
}

