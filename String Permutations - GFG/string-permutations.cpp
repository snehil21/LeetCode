//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int idx,int n,string str,vector<string>&ans){
        if(idx==n){
            ans.push_back(str);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(str[i],str[idx]);
            solve(idx+1,n,str,ans);
            swap(str[i],str[idx]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string>ans;
        int n=S.size();
        solve(0,n,S,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends