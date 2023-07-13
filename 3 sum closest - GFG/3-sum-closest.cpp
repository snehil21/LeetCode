//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int x)
    {
        sort(a,a+n);
        int ans=0,diff=INT_MAX;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=a[i]+a[j]+a[k];
                if(sum>=x){
                    k--;
                    if(abs(sum-x)<diff){
                        diff=abs(sum-x);
                        ans=sum;
                    }
                }else{
                    j++;
                    if(abs(sum-x)<diff){
                        diff=abs(sum-x);
                        ans=sum;
                    }
                }
            }
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends