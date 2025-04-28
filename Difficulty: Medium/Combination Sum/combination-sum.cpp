//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  private:
    vector<vector<int>> answer;
    void solve(vector<int> &path,const vector<int>& arr, int target,int idx){
        if(target == 0) {
            answer.push_back(path);
            return;
        }
        
        if(idx >= arr.size()){
            return;
        }
        
        //take()
        if(target >= arr[idx]){
            path.push_back(arr[idx]);
            solve(path,arr,target-arr[idx],idx);
            path.pop_back();
        }
        
        solve(path,arr,target,idx+1);
        
    }
  public:
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> path;
        solve(path,arr,target,0);
        return answer;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        vector<vector<int>> ans = ob.combinationSum(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends