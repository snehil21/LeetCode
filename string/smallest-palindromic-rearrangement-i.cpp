class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> frequency;

        for (char ch : s) {
            frequency[ch]++;
        }

        string left;
        char middle = '\0';

        for (auto& [ch, count] : frequency) {
            if (count % 2 == 1) {
                middle = ch;
            }

            left.append(count / 2, ch);
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (middle != '\0') {
            return left + middle + right;
        }

        return left + right;
    }
};