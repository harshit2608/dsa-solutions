//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int answer = 0, sum = 0;
        
        unordered_map <int,int> mp;
        for(int idx = 0;idx < arr.size();idx++) {
            sum += arr[idx];
            
            if(sum == k){
                answer = max(answer,idx+1);
            }
            
            if (mp.find(sum - k) != mp.end()) {
                answer = max(answer, idx - mp[sum - k]);
            }
            
            if (mp.find(sum) == mp.end()) {
                mp[sum] = idx;
            }
        }
        
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends