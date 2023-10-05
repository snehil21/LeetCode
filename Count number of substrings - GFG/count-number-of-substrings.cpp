//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int calcCount(string s,int k){
        int i=0,j=0,n=s.size();
        int ans=0,dist_count=0;
        vector<int>freq(26,0);
        while(j<n){
            freq[s[j]-'a']++;
            if(freq[s[j]-'a']==1){
                dist_count++;
            }
            while(dist_count>k){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0){
                    dist_count--;
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    	return calcCount(s,k)-calcCount(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends