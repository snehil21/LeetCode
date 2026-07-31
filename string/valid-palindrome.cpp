class Solution {
public:
    bool isPalindrome(string S) {
        string s = "";
        for (char ch : S) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                s += tolower(ch);
            } else if (ch >= '0' && ch <= '9')
                s += ch;
        }

        int n = s.size();
        if (n <= 1) {
            return true;
        }
        for (int i = 0; i <= n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};