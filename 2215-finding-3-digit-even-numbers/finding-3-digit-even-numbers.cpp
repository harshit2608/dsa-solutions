const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        vector<int> answer;

        for (const int& dig : digits) {
            freq[dig]++;
        }

        for (int idx = 100; idx < 999; idx += 2) {
            unordered_map<int, int> currFreq;
            int num = idx;
            while (num) {
                currFreq[num % 10]++;
                num /= 10;
            }

            bool exists = true;
            for (const auto& itr : currFreq) {
                if (itr.second > freq[itr.first]) {
                    exists = false;
                    break;
                }
            }

            if (exists) {
                answer.push_back(idx);
            }
        }

        return answer;
    }
};
