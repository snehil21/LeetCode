class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                if (nums[i] + nums[low] + nums[high] < 0) {
                    low++;
                } else if (nums[i] + nums[low] + nums[high] > 0) {
                    high--;
                } else {
                    res.push_back({nums[i], nums[low], nums[high]});
                    int tempIndex1 = low, tempIndex2 = high;
                    while (low < high && nums[low] == nums[tempIndex1])
                        low++;
                    while (low < high && nums[high] == nums[tempIndex2])
                        high--;
                }
                while (i + 1 < n && nums[i + 1] == nums[i]) {
                    i++;
                }
            }
        }
        return res;
    }
};