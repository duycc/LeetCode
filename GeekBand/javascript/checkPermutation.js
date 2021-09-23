/**
 * 先排序再对比
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkPermutation = function (s1, s2) {
    if (s1.length !== s2.length) {
        return false;
    }

    return Array.from(s1).sort().join('') === Array.from(s2).sort().join('');
};

/**
 * 两个hash表记录各个字符出现次数，进行对比
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkPermutation = function (s1, s2) {
    if (s1.length !== s2.length) {
        return false;
    }

    const map1 = {};
    const map2 = {};
    for (let i = 0; i < s1.length; i++) {
        map1[s1[i]] = map1[s1[i]] ? map1[s1[i]] + 1 : 1;
        map2[s2[i]] = map2[s2[i]] ? map2[s2[i]] + 1 : 1;
    }

    if (Object.keys(map1).length !== Object.keys(map2).length) {
        return false;
    }

    for (const key in map1) {
        if (map1[key] !== map2[key]) {
            return false;
        }
    }

    return true;
};

/**
 * 一个hash表，一个+1，一个-1
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkPermutation = function (s1, s2) {
    if (s1.length !== s2.length) {
        return false;
    }

    const map = {};
    for (let i = 0; i < s1.length; i++) {
        map[s1[i]] = map[s1[i]] || 0;
        map[s2[i]] = map[s2[i]] || 0;
        map[s1[i]]++;
        map[s2[i]]--;
    }

    for (const key in map) {
        if (map[key] !== 0) return false;
    }

    return true;
};

/**
 * 改用Map
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkPermutation = function (s1, s2) {
    if (s1.length !== s2.length) {
        return false;
    }

    const map = new Map();
    for (let i = 0; i < s1.length; i++) {
        map.set(s1[i], map.has(s1[i]) ? (map.get(s1[i]) + 1) : 1);
        map.set(s2[i], map.has(s2[i]) ? (map.get(s2[i]) - 1) : -1);
    }

    // 可以换成总和是否=0，思路
    for (const v of map.values()) {
        if (v !== 0) return false;
    }

    return true;
};