//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int currx=-1,curry=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]==x){
                currx=i;
            }else if(a[i]==y){
                curry=i;
            }
            if(currx!=-1 && curry!=-1){
                ans=min(ans,abs(currx-curry));
            }
        }
        return (currx!=-1 && curry!=-1)?ans:-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends