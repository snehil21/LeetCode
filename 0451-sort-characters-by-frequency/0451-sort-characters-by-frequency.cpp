class Solution {
public:
    static bool mycomp(pair<char,int> a, pair<char,int> b)
    {   
        if(a.second == b.second) 
            return a.first < b.first;
        return a.second > b.second;
    }
    string frequencySort(string arr) {
        string str;
        int n=arr.size();
        unordered_map<char, int> mp;
        vector<pair<char, int> > ans;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back({arr[i], mp[arr[i]]});
        }
        sort(ans.begin(), ans.end(), mycomp);
        for(int i=0;i<ans.size();i++)
        {
            str+=ans[i].first;
        }
        return str;
    }
};