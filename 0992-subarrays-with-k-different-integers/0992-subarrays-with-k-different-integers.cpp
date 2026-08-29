class Solution {
public:
  int atmost (vector<int>&nums, int k){
    int ans= 0 , l = 0 , n = nums.size();
    unordered_map <int,int>mp;
    for(int r = 0 ; r < n ; r++){
        mp[nums[r]]++;
        while(mp.size() > k ){
            mp[nums[l]]--;
            if(mp[nums[l]] == 0  ){
                mp.erase(nums[l]);
            }
            l++;
           
        } ans += r-l+1;
    }
    return ans;
  }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums , k) - atmost (nums , k-1);
    }
};