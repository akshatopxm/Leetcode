class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,int>>pq;
        unordered_map<char,int> mpp;
        for(auto it : s){
            mpp[it]++;
        }
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        string ans ="";
        pair<int,char>prev = {0,'#'};
        while(!pq.empty()){
            auto [cnt,ch] = pq.top();
            ans +=ch;
            pq.pop();
            cnt--;
            if(prev.first > 0 ){
                pq.push(prev);
            }
            prev = {cnt,ch};
        }
        if(ans.length() != s.length() )return "";
        return ans;
    }
};