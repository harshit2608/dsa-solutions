/**
 * @param {string[]} words
 * @return {string[]}
 */
var stringMatching = function (words) {
    const answer = [];
    for (let idx = 0; idx < words.length; idx++) {
        const currentWord = words[idx];
        for (let j = 0; j < words.length; j++) {
            if (idx == j) { continue; }
            if (words[j].length >= currentWord.length) {
                if (words[j].includes(currentWord)) {
                    answer.push(currentWord);
                    break;
                }
            }
        }
    }
    return answer;
};