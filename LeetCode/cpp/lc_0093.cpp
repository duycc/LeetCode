/**
 * @file     lc_0093.cpp
 * @brief    https://leetcode-cn.com/problems/restore-ip-addresses/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    backtracking(s, 0);
    return result;
  }

private:
  vector<string> result;
  vector<string> path;

  void backtracking(const string &s, int beginIdx) {
    if (path.size() == 4) {
      if (beginIdx == s.size()) {
        result.emplace_back(buildIP(path));
      }
      return;
    }
    for (int i = beginIdx; i < s.size(); ++i) {
      if (isValid(s, beginIdx, i)) {
        string str = s.substr(beginIdx, i - beginIdx + 1);
        path.emplace_back(str);
        backtracking(s, i + 1);
        path.pop_back();
      } else {
        break; // 不合法，则后续怎么截取都不合法，所以可直接跳出循环
      }
    }
  }

  bool isValid(const string &s, int begin, int end) {
    int size = end - begin + 1;
    if (size > 3) {
      return false;
    }
    if (size > 1 && s[begin] == '0') {
      return false;
    }
    int num = std::stoi(s.substr(begin, end - begin + 1));
    return num >= 0 && num <= 255;
  }

  string buildIP(const vector<string> &path) {
    string IP;
    for (auto &str : path) {
      IP += str + '.';
    }
    IP.pop_back();
    return IP;
  }
};
