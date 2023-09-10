//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int idx,vector<int>&c,vector<vector<int>>&res,vector<int>ds,int target){
        if(target==0){
            res.push_back(ds);
            return;
        }
        for(int i=idx;i<c.size();i++){
            if(i>idx && c[i]==c[i-1]){
                continue;
            }
            if(c[idx]>target){
                break;
            }
            ds.push_back(c[i]);
            solve(i+1,c,res,ds,target-c[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &c, int target) {
        int n=c.size();
        vector<vector<int>>res;
        sort(c.begin(),c.end());
        vector<int>ds;
        solve(0,c,res,ds,target);
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends