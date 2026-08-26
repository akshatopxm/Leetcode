class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26] = {0};
        int l = 0 ;
        int maxfreq = 0;
        int ans = 0;
        for(int r= 0 ; r < s.length() ; r++ ){
            mp[s[r]-'A']++;
            maxfreq = max(maxfreq , mp[s[r]-'A']);
             while((r-l+1) - maxfreq >k ){
                mp[s[l]-'A']--;
                l++;
             }ans = max(ans , r-l+1);
        } 
        return ans;

    }
};