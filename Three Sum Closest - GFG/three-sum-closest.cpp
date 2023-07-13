//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> a, int x) {
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=0,diff=INT_MAX;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=a[i]+a[j]+a[k];
                if(sum==x){
                    return sum;
                }
                int currAbsDiff=abs(sum-x);
                if(currAbsDiff<diff || (currAbsDiff==diff && sum>ans)) {
                    diff=currAbsDiff;
                    ans=sum;
                }
                if(sum<x) j++;
                else k--;
            }
        }
        return ans;   
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.

// } Driver Code Ends