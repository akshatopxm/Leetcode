class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> need;
        unordered_map<char , int> mp;
        for(auto it : t){
            need[it]++;
        }
        int l = 0 , count = 0 , maxlen = INT_MAX , start = 0;
        for(int r = 0 ; r < s.length() ; r++ ){
            mp[s[r]]++;
            if(need.count(s[r]) && mp[s[r]] <= need[s[r]] ){
                count++;
            }
            while(count == t.length()){
                if(maxlen > r-l+1){
                    maxlen = r-l+1;
                    start = l;
                }
                mp[s[l]]--;
                if(need.count(s[l]) && mp[s[l]] < need[s[l]] ){
                    count--;
                }
                l++;
            }
        }
        if(maxlen == INT_MAX)return"";

     return s.substr(start , maxlen);
    }
};