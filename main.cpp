#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int to : graph[x]) {
            if (dist[to] == -1) {
                dist[to] = dist[x] + 1;
                q.push(to);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << dist[i];
        if (i < n) std::cout << ' ';
    }
    std::cout << '\n';
}
