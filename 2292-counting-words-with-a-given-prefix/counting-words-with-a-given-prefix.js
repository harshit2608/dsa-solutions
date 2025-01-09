/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function (words, pref) {
    let answer = 0;
    for (const word of words) {
        if (word.length < pref.length) continue;
        let shouldBreak = false;
        for (let idx = 0; idx < pref.length; idx++) {
            if (pref[idx] !== word[idx]) {
                shouldBreak = true;
                break;
            }
        }
        if (!shouldBreak) {
            answer += 1;
        }
    }
    return answer;
};