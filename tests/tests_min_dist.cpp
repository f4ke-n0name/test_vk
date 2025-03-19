#include "gtest/gtest.h"
#include "../src/min_dist.h"

TEST(MinDistTest, LinearGraph) {
  int32_t n = 5;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1},
      {0, 2},
      {1, 3},
      {2, 4},
      {3}
  };
  std::vector<int32_t> expected = {0, 1, 2, 3, 4};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}

TEST(MinDistTest, CyclicGraph) {
  int32_t n = 6;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1, 5},
      {0, 2},
      {1, 3},
      {2, 4},
      {3, 5},
      {4, 0}
  };
  std::vector<int32_t> expected = {0, 1, 2, 3, 2, 1};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}

TEST(MinDistTest, StarGraph) {
  int32_t n = 7;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1, 2, 3, 4, 5, 6},
      {0},
      {0},
      {0},
      {0},
      {0},
      {0}
  };
  std::vector<int32_t> expected = {0, 1, 1, 1, 1, 1, 1};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}


TEST(MinDistTest, RingGraph) {
  int32_t n = 8;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1, 7},
      {0, 2},
      {1, 3},
      {2, 4},  
      {3, 5}, 
      {4, 6},
      {5, 7},
      {6, 0} 
  };
  std::vector<int32_t> expected = {0, 1, 2, 3, 4, 3, 2, 1};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}


TEST(MinDistTest, GridGraph) {
  int32_t n = 9;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1, 3},
      {0, 2, 4}, 
      {1, 5},
      {0, 4, 6},
      {1, 3, 5, 7},
      {2, 4, 8},
      {3, 7},
      {4, 6, 8},
      {5, 7}
  };
  std::vector<int32_t> expected = {0, 1, 2, 1, 2, 3, 2, 3, 4};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}

TEST(MinDistTest, TreeGraph) {
  int32_t n = 7;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1, 2},
      {0, 3, 4},
      {0, 5, 6},
      {1},
      {1},
      {2},
      {2}
  };
  std::vector<int32_t> expected = {0, 1, 1, 2, 2, 2, 2};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}


TEST(MinDistTest, ForkedGraph) {
  int32_t n = 6;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1},        // 0
      {0, 2, 3},  // 1
      {1, 4},     // 2
      {1, 5},     // 3
      {2},        // 4
      {3}         // 5
  };
  std::vector<int32_t> expected = {0, 1, 2, 2, 3, 3};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}


TEST(MinDistTest, CompleteGraph) {
  int32_t n = 4;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1, 2, 3},
      {0, 2, 3},
      {0, 1, 3},
      {0, 1, 2}
  };
  std::vector<int32_t> expected = {0, 1, 1, 1};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}


TEST(MinDistTest, MultiplePathsGraph) {
  int32_t n = 6;
  int32_t start = 0;
  std::vector<std::vector<int32_t>> graph = {
      {1, 2},
      {0, 3},
      {0, 3, 4},
      {1, 2, 5},
      {2, 5},
      {3, 4}
  };
  std::vector<int32_t> expected = {0, 1, 1, 2, 2, 3};
  std::vector<int32_t> result = bfs(n, start, graph);
  ASSERT_EQ(result, expected);
}