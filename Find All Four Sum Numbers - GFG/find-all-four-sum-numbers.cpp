//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int currSum=arr[i]+arr[j];
                int target=k-currSum;
                int front=j+1,back=n-1;
                while(front<back){
                    int sum=arr[front]+arr[back];
                    if(sum<target){
                        front++;
                    }else if(sum>target){
                        back--;
                    }else{
                        vector<int>v={arr[i],arr[j],arr[front],arr[back]};
                        ans.push_back(v);
                        while(front<back && arr[front]==v[2]) front++;
                        while(front<back && arr[back]==v[3]) back--;
                    }
                }
                while(j<n && arr[j]==arr[j+1])j++;
            }
            while(i<n && arr[i]==arr[i+1])i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends