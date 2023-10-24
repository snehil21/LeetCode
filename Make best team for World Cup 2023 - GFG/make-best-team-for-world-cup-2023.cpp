//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  long long maximumSum(int N, vector<int> &A) {
    long long res=0;
    int i,j;
    if(N%2){
        res+=A[N/2];
        j=N/2+1;
    }else{
        j=N/2;
    }
    i=N/2-1;
    priority_queue<int>q;
    for(;i>=0;i--,j++){
        q.push(A[i]);
        q.push(A[j]);
        res+=q.top();
        q.pop();
    }
    return res;
  }
};


//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    Solution obj;
    cout << obj.maximumSum(N, A) << endl;
  }
  return 0;
}
// } Driver Code Ends