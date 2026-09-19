class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        if (nums.size() % k != 0)
            return false;

        map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        while (!mp.empty()) {
            
            int start = mp.begin()->first;

            for (int i = 0; i < k; i++) {
                
                int num = start + i;

                if (mp[num] == 0)
                    return false;

                mp[num]--;

                if (mp[num] == 0)
                    mp.erase(num);
            }
        }

        return true;
    }
};