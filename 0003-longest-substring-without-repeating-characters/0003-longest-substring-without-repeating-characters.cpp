class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans= 0;
        unordered_map<char,int>mpp;
        for(int r= 0 ; r <s.length() ;r++){
            mpp[s[r]]++;
            while(mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans , r-l+1);
        }
        return ans;
    }
};