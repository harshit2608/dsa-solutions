//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = arr[0];
        int secLargest = -1;
        
        for(const int &itr:arr) {
            if(itr > secLargest) {
                if(itr > largest){
                    secLargest = largest;
                    largest = itr;
                }else if(itr!=largest){
                    secLargest = itr;
                }
            }
        }
        return secLargest;
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
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends