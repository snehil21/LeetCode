class Solution {
public:
    void reverseString(vector<char>& s) {
        int right=s.size()-1,left=0;
        while(right>left){
            swap(s[left++],s[right--]);
        }
    }
};