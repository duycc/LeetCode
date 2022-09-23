/**
 * @file     lc_0187.cpp
 * @brief    https://leetcode-cn.com/problems/repeated-dna-sequences/
 * @author   YongDu
 * @date     2021-10-08
 */

class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::vector<std::string>             result;
        std::unordered_map<std::string, int> strMap;

        int size = s.size();
        for (int i = 0; i < size - 9; ++i) {
            std::string subStr = s.substr(i, 10);
            if (++strMap[subStr] == 2) {
                result.emplace_back(subStr);
            }
        }
        return result;
    }
};