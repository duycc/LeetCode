/**
 * @file     reverseLeftWords.js
 * @brief    https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/submissions/
 * @author   Zhu
 * @date     2021-07-26
 */


/**
 * 字符串方法
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
 var reverseLeftWords = function (s, n) {
    return s.slice(n) + s.slice(0, n);
};

/**
 * 遍历
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function (s, n) {
    let left = '';
    let right = '';
    for (let i = 0; i < s.length; i++) {
        if (i < n) {
            left += s[i];
        } else {
            right += s[i];
        }
    }

    return right + left;
};

/**
 * 求余妙用
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function (s, n) {
    let str = '';
    for (let i = n; i < n + s.length; i++) {
        str += s[i % s.length];
    }

    return str;
};

/**
 * 双指针/滑动窗口
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function (s, n) {
    let arr = s.split('');
    let i = 0;
    while (i < n) {
        arr[i + s.length] = arr[i++];
    }

    return arr.slice(n, n + s.length).join('');
};

/**
 * 三次反转，效率不高，但是思路清奇
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function (s, n) {
    String.prototype.reverse = function (i, j) {
        return this.slice(i, j).split('').reverse().join('');
    };
    return (s.reverse(0, n) +
        s.reverse(n))
        .reverse();
};
