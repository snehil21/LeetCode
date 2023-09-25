class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>freq(26,0);
        for(char ch:t){
            freq[ch-'a']++;
        }
        for(char ch:s){
            freq[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]==1){
                return char('a'+i);
            }
        }
        return 'a';
    }
};