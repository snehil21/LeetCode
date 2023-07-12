class Solution {
public:
    bool isValid(vector<int>&arr,int days,int m,int k){
        int count=0;
        int curr = 0;
        for(auto x: arr){
            if(x <= days){
                curr++;
                if(curr == k){
                    count++;
                    curr = 0;
                }
            }
            else{
                curr = 0;
            }
        }
        return count>=m;
    }
    int minDays(vector<int>& bloomDay, int M, int K) {
      int high=*max_element(bloomDay.begin(), bloomDay.end());;
      int low=*min_element(bloomDay.begin(), bloomDay.end());;
      int ans=-1;
      int n=bloomDay.size();
      long long int total=(long long int)M*K;
      if(total>n){
          return -1;
      }
      while(low<=high){
          int mid=low+(high-low)/2;
          if(isValid(bloomDay,mid,M,K)){
              ans=mid;
              high=mid-1;
          }else{
              low=mid+1;
          }
      }
      return ans;
    }
};