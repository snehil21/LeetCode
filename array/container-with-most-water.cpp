class Solution {
public:
    int maxArea(vector<int>& h) {
        int left = 0, right = h.size() - 1;
        int res = 0;
        while (left < right) {
            int w = right - left;
            res = max(res, w * (min(h[left], h[right])));
            if (h[left] < h[right]) {
                left++;
            } else if (h[left] > h[right]) {
                right--;
            } else {
                left++;
                right--;
            }
        }
        return res;
    }
};