#include "min_dist.h"
#include <queue>

std::vector<int32_t> bfs(int32_t n, int32_t start, const std::vector<std::vector<int32_t>>& graph) {
    std::queue<int32_t> q;
    std::vector<int32_t> dist(n, -1);  // -1 - unreachable vertex
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int32_t current_vertex = q.front();
        q.pop();
        for (size_t i = 0; i < graph[current_vertex].size(); ++i) {
            int32_t child = graph[current_vertex][i];
            if (dist[child] == -1) {
                dist[child] = dist[current_vertex] + 1;  // update distance
                q.push(child);
            }
        }
    }
    return dist;
}