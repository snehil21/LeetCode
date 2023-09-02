class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size();
        unordered_map<char,int>mp;
        int ans=0;
        while(i<n){
            mp[s[i]]++;
            while(mp[s[i]]!=1){
                mp[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};