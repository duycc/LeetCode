"""
 * @file     lc_0076.py
 * @brief    https://leetcode-cn.com/problems/minimum-window-substring/
 * @author   YongDu
 * @date     2021-11-01
"""


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        dst_map = defaultdict(int)
        dst_len = len(t)

        for ch in t:
            dst_map[ch] += 1

        min_left, min_right = 0, len(s)
        left = 0

        for right, ch in enumerate(s):
            if dst_map[ch] > 0:
                dst_len -= 1
            dst_map[ch] -= 1

            if dst_len == 0:
                # 收缩窗口
                while dst_map[s[left]] < 0:
                    dst_map[s[left]] += 1
                    left += 1

                # 记录最小窗口
                if right - left < min_right - min_left:
                    min_left, min_right = left, right

                # 扩大窗口
                dst_map[s[left]] += 1
                dst_len += 1
                left += 1

        return "" if min_right == len(s) else s[min_left:min_right + 1]
