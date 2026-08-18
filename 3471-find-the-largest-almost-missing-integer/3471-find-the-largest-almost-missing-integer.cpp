class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int windows = n - k + 1;

        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);

        int ans = -1;

        for (auto &it : pos) {
            auto &v = it.second;

            int covered = 0;
            int curL = -1, curR = -1;

            for (int idx : v) {
                int L = max(0, idx - k + 1);
                int R = min(idx, windows - 1);

                if (L > R) continue;  // occurrence is in no window

                if (curL == -1) {
                    curL = L;
                    curR = R;
                } else if (L > curR + 1) {
                    covered += curR - curL + 1;
                    curL = L;
                    curR = R;
                } else {
                    curR = max(curR, R);
                }
            }

            if (curL != -1)
                covered += curR - curL + 1;

            if (covered == 1)
                ans = max(ans, it.first);
        }

        return ans;
    }
};