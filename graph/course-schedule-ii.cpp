class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> inbound(n, 0);
        vector<int> edges[n];
        for (auto it : prerequisites) {
            int u = it[0], v = it[1];
            inbound[u]++;
            edges[v].push_back(u);
        }
        vector<int> ans, v;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inbound[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto i : edges[v]) {
                inbound[i]--;
                if (inbound[i] == 0) {
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        return (ans.size() == n) ? ans : v;
    }
};