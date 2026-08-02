class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 1, currSum = 0;
        for (auto wt : people) {
            currSum += wt;
            if (currSum > limit) {
                currSum = wt;
                boats++;
            }
        }
        return boats;
    }
};