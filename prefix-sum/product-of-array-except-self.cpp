class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int totalMul = 1, idx = -1, zero = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero++;
                idx = i;
            } else {
                totalMul *= nums[i];
            }
        }
        if (zero == 0) {
            for (int i = 0; i < n; i++) {
                res[i] = totalMul / nums[i];
            }
        }
        if (zero == 1) {
            res[idx] = totalMul;
        }
        return res;
    }
};