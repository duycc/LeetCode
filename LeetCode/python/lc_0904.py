"""
 * @file     lc_0904.py
 * @brief    https://leetcode-cn.com/problems/fruit-into-baskets/
 * @author   YongDu
 * @date     2021-11-01
"""


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        max_fruits = 0
        fruit_map = defaultdict(int)
        left = 0

        for right in range(len(fruits)):
            fruit_map[fruits[right]] += 1

            while len(fruit_map) > 2:
                cur_fruit = fruits[left]
                fruit_map[cur_fruit] -= 1
                if fruit_map[cur_fruit] == 0:
                    del fruit_map[cur_fruit]
                left += 1

            max_fruits = max(max_fruits, right - left + 1)

        return max_fruits
