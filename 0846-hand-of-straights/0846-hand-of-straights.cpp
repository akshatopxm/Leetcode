class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        //check
        if(n % groupSize != 0)return false;
        // declaring the map and min pq
        unordered_map<int,int>mpp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it : hand){
            mpp[it]++;
            pq.push(it);
        }
        while(!pq.empty()){
            int curr = pq.top();
               if(mpp[curr] == 0){
                    pq.pop();
                    continue;
                }  for(int i = 0 ; i < groupSize ; i++){
                  int next = curr+i;
                  if(mpp[next]==0){
                    return false;
                  }
                  mpp[next]--;
                }
              }
          return true;
    }
};