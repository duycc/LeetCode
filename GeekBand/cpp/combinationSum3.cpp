/**
 * @file     combinationSum3.cpp
 * @brief
 * @author   YongDu
 * @date     2021-08-09
 */
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    backTracking(n, k, 0, 1);
    return result;
  }

private:
  vector<int> path;           // 符合条件的结果
  vector<vector<int>> result; // 结果集

  void backTracking(int targetSum, int k, int sum, int startIndex) {
    if (sum > targetSum)
      return;
    if (k == path.size()) {
      if (sum == targetSum)
        result.emplace_back(path);
      return;
    }
    for (int i = startIndex; i <= 9; ++i) {
      sum += i;
      path.emplace_back(i);
      backTracking(targetSum, k, sum, i + 1);
      sum -= i;
      path.pop_back();
    }
    return;
  }
};
