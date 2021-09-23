/**
 * @file     removeElement.js
 * @brief    https://leetcode-cn.com/problems/remove-element/submissions/
 * @author   Zhu
 * @date     2021-07-26
 */

/**
 * 普通解法
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    for (let i = nums.length - 1; i >= 0; i--) {
        if (nums[i] === val) {
            nums.splice(i, 1);
        }
    }
    return nums.length;
};

/**
 * 同向双指针
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    let k = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[k++] = nums[i];
        }
    }
    return k;
};

/**
 * 相向双指针
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    let k = 0;
    let j = nums.length - 1;
    while (k <= j) {
        if (nums[k] === val) {
            nums[k] = nums[j];
            j--;
        } else {
            k++;
        }
    }
    return k;
};
