#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Ускоряем ввод/вывод, чтобы не получить TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n — количество маяков, m — количество каналов (рёбер)
    int n, m;
    cin >> n >> m;

    // Список смежности: adj[i] содержит все маяки, с которыми связан маяк i
    // Индексируем с 1, поэтому размер n+1
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Канал двусторонний — добавляем ребро в обе стороны
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dist[i] — минимальное число шагов от маяка 1 до маяка i
    // Изначально -1 означает "ещё не посещён"
    vector<int> dist(n + 1, -1);

    // Очередь для BFS (обход в ширину)
    queue<int> bfsQueue;

    // Стартуем с маяка 1: расстояние до него 0
    dist[1] = 0;
    bfsQueue.push(1);

    // BFS: обходим маяки уровень за уровнем
    // Каждый уровень — это +1 шаг от старта
    while (!bfsQueue.empty()) {
        int cur = bfsQueue.front(); // берём текущий маяк из начала очереди
        bfsQueue.pop();

        // Смотрим всех соседей текущего маяка
        for (int next : adj[cur]) {
            // Если сосед ещё не посещён — записываем расстояние и добавляем в очередь
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                bfsQueue.push(next);
            }
        }
    }

    // Выводим ответ: для каждого маяка его расстояние от маяка 1
    // Если dist[i] == -1, значит маяк недостижим (так и выведем -1)
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << dist[i];
    }
    cout << endl;

    return 0;
}
