class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            if (mp.count(prefixSum - goal)) {
                ans += mp[prefixSum - goal];
            }

            mp[prefixSum]++;
        }

        return ans;
    }
};