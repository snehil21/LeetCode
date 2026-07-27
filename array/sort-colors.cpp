class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0;
        for (auto ele : nums) {
            if (ele == 0) {
                zeros++;
            } else if (ele == 1) {
                ones++;
            }
        }
        int i = 0;
        while (i < zeros) {
            nums[i++] = 0;
        }
        while (i < zeros + ones) {
            nums[i++] = 1;
        }
        while (i < nums.size()) {
            nums[i++] = 2;
        }
    }
};