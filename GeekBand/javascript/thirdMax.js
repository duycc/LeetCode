/**
 * @file     thirdMax.js
 * @brief    [414. 第三大的数](https://leetcode-cn.com/problems/third-maximum-number/)
 * @author   Zhu
 * @date     2021-08-19 19:33
 */


/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function (nums) {
    const sequence = [-Infinity, -Infinity, -Infinity]; // 3 2 1
    for (const num of nums) {
        if (num > sequence[0]) {
            if (num > sequence[1]) {
                if (num > sequence[2]) {
                    sequence[0] = sequence[1];
                    sequence[1] = sequence[2];
                    sequence[2] = num;
                } else if (num < sequence[2]) {
                    sequence[0] = sequence[1];
                    sequence[1] = num;
                }
            } else if (num < sequence[1]) {
                sequence[0] = num;
            }
        }
    }
    return sequence[0] == -Infinity ? sequence[2] : sequence[0];
};