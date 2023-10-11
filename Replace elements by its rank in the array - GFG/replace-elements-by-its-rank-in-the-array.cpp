//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){
        vector<int>ans;
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>hmap;
        int cnt=1;
        hmap[temp[0]]=cnt;
        cnt++;
        for(int i=1;i<n;i++){
            if(temp[i]==temp[i-1])continue;
            hmap[temp[i]]=cnt;
            cnt++;
        }
        for(int i=0;i<n;i++){
            int rank=hmap[arr[i]];
            ans.push_back(rank);
        }
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends