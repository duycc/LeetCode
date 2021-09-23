/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function (astr) {
    const map = {};
    for (const c of astr) {
        const v = map[c];
        if (v) { return false; }
        map[c] = 1;
    }
    return true;
};