class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1, i = 1;
        while (right < nums.size()) {
            if (nums[left] != nums[right]) {
                nums[i++] = nums[right];
                left++;
            }
            right++;
        }

        return i;
    }
};