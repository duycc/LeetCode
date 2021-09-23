/**
 * 利用API
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ').map(w => Array.from(w).reverse().join('')).join(' ');
};

/**
 * 朴素的遍历
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
    let sentence = '';
    let word = '';
    for (const c of s) {
        if (c == ' ') {
            sentence += word + ' ';
            word = '';
        } else {
            word = c + word;
        }
    }
    sentence += word;

    return sentence;
};

/**
 * 一个奇怪的思路，看上去很酷
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
    return s
        .split('')
        .reverse()
        .join('')
        .split(' ')
        .reverse()
        .join(' ');
};