#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minOperationsToDeleteVertex1(int N, const vector<pair<int, int> >& edges) {
    vector<int> degree(N + 1, 0);
    vector<std::vector<int> > graph(N + 1);
    queue<int> q;
    
    // Construct the graph and degree of each vertex
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
        degree[edge.first]++;
        degree[edge.second]++;
    }

    // Initialize the queue with all leaf vertices except vertex 1
    for (int i = 2; i <= N; ++i) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    // BFS to remove leaf vertices
    while (!q.empty()) {
        int leaf = q.front();
        q.pop();
        degree[leaf]--;

        for (int adj : graph[leaf]) {
            if (--degree[adj] == 1 && adj != 1) {
                q.push(adj);
            }
        }
    }

    // The remaining degree of vertex 1 is the number of operations needed
    return degree[1];
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int> > edges;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    cout << minOperationsToDeleteVertex1(N, edges) << endl;

    return 0;
}
