/**
 * @file     combine.cpp
 * @brief
 * @author   YongDu
 * @date     2021-08-09
 */

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    backTracking(n, k, 1);
    return result;
  }

private:
  vector<int> path;
  vector<vector<int>> result;

  void backTracking(int n, int k, int startIndex) {
    // 递归终止条件
    if (k == path.size()) {
      result.emplace_back(path);
      return;
    }
    // 单层递归逻辑
    for (int i = startIndex; i <= n; ++i) {
      path.emplace_back(i);
      backTracking(n, k, i + 1);
      path.pop_back(); // 记得回溯
    }
    return;
  }
};

// 剪枝优化
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    backTracking(n, k, 1);
    return result;
  }

private:
  vector<int> path;
  vector<vector<int>> result;

  void backTracking(int n, int k, int startIndex) {
    // 递归终止条件
    if (k == path.size()) {
      result.emplace_back(path);
      return;
    }
    // 单层递归逻辑
    for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) { // 剪枝
      path.emplace_back(i);
      backTracking(n, k, i + 1);
      path.pop_back(); // 记得回溯
    }
    return;
  }
};
