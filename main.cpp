#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> bfsQueue;

    dist[1] = 0;
    bfsQueue.push(1);

    while (!bfsQueue.empty()) {
        int cur = bfsQueue.front();
        bfsQueue.pop();

        for (int next : adj[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                bfsQueue.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << dist[i];
    }
    cout << endl;

    return 0;
}
