//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    string ans;
		    unordered_map<char,int>mp;
		    queue<char>q;
		    for(int i=0;i<str.size();i++){
		        mp[str[i]]++;
		        q.push(str[i]);
		        while(q.size()>0 && mp[q.front()]>1){
		            q.pop();
		        }
		        if(q.size()>0){
		            ans+=q.front();
		        }
		        else{
		            ans+="#";
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends