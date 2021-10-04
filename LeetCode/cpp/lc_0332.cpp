/**
 * @file     lc_0332.cpp
 * @brief    https://leetcode-cn.com/problems/reconstruct-itinerary/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    vector<string> result;
    for (auto &ticket : tickets) {
      targets[ticket[0]][ticket[1]]++;
    }
    result.push_back("JFK");
    backtracking(tickets.size(), result);
    return result;
  }

private:
  std::unordered_map<string, std::map<string, int>> targets;

  bool backtracking(int ticketNum, vector<string> &result) {
    if (result.size() == ticketNum + 1) {
      return true;
    }
    for (auto &target : targets[result.back()]) {
      if (target.second > 0) {
        result.push_back(target.first);
        target.second--;
        if (backtracking(ticketNum, result)) {
          return true;
        }
        result.pop_back();
        target.second++;
      }
    }
    return false;
  }
};
