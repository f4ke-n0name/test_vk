#include <fstream>
#include <iostream>
#include "min_dist.h"

int main() {
  std::ifstream infile("graph.txt");
  std::ofstream outfile("output.txt");

  if (!infile) {
    std::cerr << "Cannot open 'graph.txt'";
    return 1;
  }

  int32_t n, m, start;  // n - number of vertices, m - number of edges, start -
                        // start vertex
  infile >> n >> m;

  if (n <= 0 || m < 0) {
    std::cerr << "Invalid number of vertices or edges"
              << '\n';  // check for valid number of vertices and edges
    return 1;
  }

  std::vector<std::vector<int32_t>> graph(n);
  // we store the graph as an adjacency list

  int32_t x, y;
  for (size_t i = 0; i < m; ++i) {
    infile >> x >> y;
    graph[x].push_back(y);  // initilizing the graph
    graph[y].push_back(x);  // graph is undirected
  }

  infile >> start;

  std::vector<int32_t> result = bfs(n, start, graph);
  // call 'bfs()' to find distance from start

  for (int32_t distance : result) {
    outfile << distance << '\n';
  }
  return 0;
}