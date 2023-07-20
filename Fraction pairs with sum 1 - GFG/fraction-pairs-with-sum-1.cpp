//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int nu[], int d[])
    {
        int ans=0;
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){
            int x=nu[i],y=d[i];
            int gcd=__gcd(x,y);
            x/=gcd;
            y/=gcd;
            int nx=y-x;
            int ny=y;
            if(mp.find({nx,ny})!=mp.end()){
                ans+=mp[{nx,ny}];
            }
            mp[{x,y}]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends