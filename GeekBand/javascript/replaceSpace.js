/**
 * @file     replaceSpace.js
 * @brief    https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 * @author   Zhu
 * @date     2021-07-26 15:53
 */

/**
 * 利用API
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    return s.replace(/\s/g, '%20');
};

/**
 * 遍历
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function (s) {
    let str = '';
    for (const c of s) {
        if (c === ' ') {
            str += '%20';
        } else {
            str += c;
        }
    }

    return str;
};