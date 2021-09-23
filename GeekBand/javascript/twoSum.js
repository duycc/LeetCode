/**
 * @file     twoSum.js
 * @brief    https://leetcode-cn.com/problems/two-sum/
 * @author   Zhu
 * @date     2021-07-24
 */

/**
 * 两层for循环，暴力解法
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    for (let i = 0; i < nums.length; i++) {
        const cur = nums[i];
        for (let j = i + 1; j < nums.length; j++) {
            if (cur + nums[j] == target) {
                return [i, j];
            }
        }
    }
    return [];
};

/**
 * 用hash记录另一半，每次开始判断当前在不在hash中
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const hash = {};
    for (let i = 0; i < nums.length; i++) {
        const cur = nums[i];
        if (hash[cur] != undefined) { return [hash[cur], i]; }
        hash[target - cur] = i;
    }
    return [];
};

/**
 * 用 Map 代替 {}
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const map = new Map();
    for (let i = 0; i < nums.length; i++) {
        const cur = nums[i];
        if (map.has(cur)) return [map.get(cur), i];
        map.set(target - cur, i);
    }
    return [];
};