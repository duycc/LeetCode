/**
 * 利用Set去重，同时将判断元素存在从O(n)降到O(1)
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    const nums_set = new Set(nums);

    let longestStreak = 0;
    for (const num of nums_set) {
        if (!nums_set.has(num - 1)) {
            let currentStreak = 1;
            let cur = num + 1;
            while (nums_set.has(cur)) {
                currentStreak++;
                cur++;
            }
            currentStreak > longestStreak && (longestStreak = currentStreak);
        }
    }

    return longestStreak;
};


/**
 * 只关心子序列的左右端点，让端点的value完全描述整个子序列
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    const keyMap = new Map();
    let max = 0;
    for (const num of nums) {
        if (!keyMap.has(num)) { // 防重
            const left = keyMap.get(num - 1) || 0;
            const right = keyMap.get(num + 1) || 0;

            const cur_length = left + 1 + right;
            keyMap.set(num, cur_length); // 这里只有key有用，防重，value的值并不重要
            keyMap.set(num - left, cur_length);
            keyMap.set(num + right, cur_length);

            if (cur_length > max) {
                max = cur_length;
            }
        }
    }

    return max;
};
