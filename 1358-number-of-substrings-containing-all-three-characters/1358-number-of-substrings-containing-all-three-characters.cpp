class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0 ;
        int cnt = 0;
        unordered_map<char,int>mpp;
        for(int r = 0 ; r < n ; r++ ){
         mpp[s[r]]++;
         while(mpp['a'] >0 && mpp['b'] > 0 && mpp['c'] > 0 ){
            cnt += n-r;
            mpp[s[l]]--;
            l++;
         }
        }
        return cnt;
    }
};