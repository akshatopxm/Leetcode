class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      unordered_map<int,int> mp;
      mp[0]= 1;
      int ans = 0; 
      int currodd = 0 ;
      for(int it : nums){
        if(it % 2 ==1){
            currodd++;
        }
        if(mp.count(currodd - k)){
            ans += mp[currodd - k];
        }
        mp[currodd]++;
      }
      return ans;
    }
};