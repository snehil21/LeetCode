class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice = 0, bob = 0, start = 0, end = piles.size() - 1;
        int turn = 0;
        while (start < end) {
            if (turn % 2) {
                if (piles[start] > piles[end]) {
                    bob += piles[start++];
                } else {
                    bob += piles[end--];
                }
            } else {
                if (piles[start] > piles[end]) {
                    alice += piles[start++];
                } else {
                    alice += piles[end--];
                }
            }
            turn++;
        }
        return alice > bob;
    }
};