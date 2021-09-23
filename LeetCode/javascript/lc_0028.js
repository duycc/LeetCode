/**
 * 暴力 Brute Force
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    for (let i = 0; i < haystack.length; i++) {
        if (match(i)) return i;
    }

    function match(i) {
        for (let j = 0; j < needle.length; j++) {
            if (haystack[i++] !== needle[j]) {
                return false;
            }
        }
        return true;
    }

    if (haystack == '' && needle == '') return 0;
    return -1;
};

// Sunday
var strStr = function (haystack, needle) {
    const n = haystack.length,
        m = needle.length;
    for (let i = 0; i <= n - m; i++) {
        if (match(i)) return i;
        else {
            const index = lastIndexOf(haystack[i + m]);
            if (index === -1) {
                i += m;
            } else {
                i += m - index - 1;
            }
        }
    }

    function match(i) {
        for (let j = 0; j < m; j++) {
            if (haystack[i++] !== needle[j]) {
                return false;
            }
        }
        return true;
    }

    function lastIndexOf(char) {
        for (let j = m - 1; j > 0; j--) {
            if (char == needle[j]) return j;
        }
        return -1;
    }

    if (m + n == 0) return 0;
    return -1;
};

// sunday 提前生成hash表
var strStr = function (haystack, needle) {
    const n = haystack.length,
        m = needle.length;

    function makeNeedleDict() {
        const hash = {};
        for (let i = 0; i < m; i++) {
            hash[needle[i]] = i;
        }
        return hash;
    }
    const needleDict = makeNeedleDict();

    for (let i = 0; i <= n - m; i++) {
        if (match(i)) return i;
        else {
            const index = needleDict(haystack[i + m]);
            if (index === -1) {
                i += m;
            } else {
                i += m - index - 1;
            }
        }
    }

    function match(i) {
        for (let j = 0; j < m; j++) {
            if (haystack[i++] !== needle[j]) {
                return false;
            }
        }
        return true;
    }

    if (m + n == 0) return 0;
    return -1;
};


// KMP
var strStr = function (haystack, needle) {
    if (needle.length == 0) { return 0; }
    // 求next数组
    function getNext(x) {
        for (let i = x; i > 0; i--) {
            if (needle.slice(0, i) == needle.slice(x + 1 - i, x + 1)) return i;
        }
        return 0;
    }
    const next = [];
    for (let j = 0; j < needle.length; j++) {
        next[j] = getNext(j);
    }
    // 搜索
    function search() {
        let k = 0, h = 0;
        while (k < haystack.length) {
            if (haystack[k] == needle[h]) {
                k++;
                h++;
            } else if (h > 0) { // 已经匹配了h个长度了，不能浪费这h次匹配
                h = next[h - 1]; // 查询next数组，找到最长公共前后缀，续上
            } else {
                k++;
            }
            if (h == needle.length) { // 愣着干啥，匹配完了！
                return k - h;
            }
        }
        return -1;
    }

    return search();
};


// KMP - 改进构建Next数组的方式
var strStr = function (haystack, needle) {
    if (needle.length == 0) { return 0; }
    // 求next数组
    function buildNext() {
        const next = [0]; // 不和自己比
        let prefix = 0, suffix = 1;
        while (suffix < needle.length) {
            if (needle[prefix] == needle[suffix]) {
                prefix++;
                suffix++;
                next.push(prefix);
            } else if (prefix > 0) {
                prefix = next[prefix - 1];
            } else {
                suffix++;
                next.push(0);
            }
        }
        return next;
    }
    const next = buildNext();
    // 搜索
    function search() {
        let k = 0, h = 0;
        while (k < haystack.length) {
            if (haystack[k] == needle[h]) {
                k++;
                h++;
            } else if (h > 0) { // 已经匹配了h个长度了，不能浪费这h次匹配
                h = next[h - 1]; // 查询next数组，找到最长公共前后缀，续上
            } else {
                k++;
            }
            if (h == needle.length) { // 愣着干啥，匹配完了！
                return k - h;
            }
        }
        return -1;
    }

    return search();
};

