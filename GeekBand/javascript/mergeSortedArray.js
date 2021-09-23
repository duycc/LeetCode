/**
 * @file     mergeSortedArray.js
 * @brief    https://leetcode-cn.com/problems/merge-sorted-array/submissions/
 * @author   Zhu
 * @date     2021-07-26 19:37
 */


/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
    let i = m - 1, j = n - 1;
    while (i >= 0 || j >= 0) {
        if (i == -1) {
            nums1[i + j + 1] = nums2[j];
            j--;
        } else if (j == -1) {
            nums1[i + j + 1] = nums1[i];
            i--;
        } else if (nums1[i] > nums2[j]) {
            nums1[i + j + 1] = nums1[i];
            i--;
        } else {
            nums1[i + j + 1] = nums2[j];
            j--;
        }
    }
};

/**
 * 挑战极限，无形装逼，最为致命
 */
var merge = function (nums1, m, nums2, n) {
    let i = m-- + --n;
    while (n >= 0) {
        nums1[i--] = (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
    }
};