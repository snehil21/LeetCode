class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, len1 = word1.size(), len2 = word2.size();
        string str;
        while (i < len1 && j < len2) {
            str += word1[i++];
            str += word2[j++];
        }
        while (i < len1) {
            str += word1[i++];
        }
        while (j < len2) {
            str += word2[j++];
        }
        return str;
    }
};