class Solution {
public:
    char kthCharacter(int k) {
        string start = "a";

        while (start.size() < k) {
            string helper;
            for (const char& itr : start) {
                helper += 'a' + (itr - 'a' + 27) % 26;
            }
            start += helper;
        }
        return start[k - 1];
    }
};