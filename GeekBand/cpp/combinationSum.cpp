/**
 * @file     combinationSum.cpp
 * @brief    https://leetcode-cn.com/problems/combination-sum/
 * @author   YongDu
 * @date     2021-08-10
 */
// 回溯算法
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    std::function<void(int, int)> backTracking = [&](int sum, int startIndex) {
      if (sum > target)
        return;
      if (sum == target) {
        result.emplace_back(path);
        return;
      }
      for (int i = startIndex; i < candidates.size(); ++i) {
        path.emplace_back(candidates[i]);
        sum += candidates[i];
        backTracking(sum, i);
        sum -= candidates[i];
        path.pop_back();
      }
      return;
    };

    backTracking(0, 0);
    return result;
  }

private:
  vector<int> path;
  vector<vector<int>> result;
};

// 剪枝优化
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end()); // 需要排序

    std::function<void(int, int)> backTracking = [&](int sum, int startIndex) {
      if (sum > target)
        return;
      if (sum == target) {
        result.emplace_back(path);
        return;
      }
      for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; ++i) { // 剪枝
        path.emplace_back(candidates[i]);
        sum += candidates[i];
        backTracking(sum, i);
        sum -= candidates[i];
        path.pop_back();
      }
      return;
    };

    backTracking(0, 0);
    return result;
  }

private:
  vector<int> path;
  vector<vector<int>> result;
};
