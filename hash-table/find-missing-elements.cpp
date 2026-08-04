class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res;
        int start = nums[0], end = nums[n - 1];
        int j = 1;
        for (int i = start + 1; i < end; i++) {
            if (nums[j] == i) {
                j++;
            } else {
                res.push_back(i);
            }
        }
        return res;
    }
};