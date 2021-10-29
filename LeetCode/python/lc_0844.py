"""
 * @file     lc_0844.py
 * @brief    
 * @author   YongDu
 * @date     2021-10-29
"""


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def get_text(string):
            text = []
            for ch in string:
                if ch != '#':
                    text.append(ch)
                elif len(text) > 0:  # 保证栈非空
                    text.pop()
            return str(text)
        return get_text(s) == get_text(t)
