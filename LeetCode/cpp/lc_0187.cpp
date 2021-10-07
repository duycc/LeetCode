/**
 * @file     lc_0187.cpp
 * @brief    https://leetcode-cn.com/problems/repeated-dna-sequences/
 * @author   YongDu
 * @date     2021-10-08
 */
class Solution {
  const int targetLen = 10;

public:
  vector<string> findRepeatedDnaSequences(string s) {
    std::unordered_map<string, int> hashMap;
    vector<string> result;
    int len = s.size();
    for (int i = 0; i <= len - targetLen; ++i) {
      string str = s.substr(i, targetLen);
      if (++hashMap[str] == 2) { // 不要使用 > 1 去收集，否则会收集重复元素
        result.emplace_back(str);
      }
    }
    return result;
  }
};
