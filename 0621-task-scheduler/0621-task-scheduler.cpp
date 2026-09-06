class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // making map
        unordered_map<char,int>mp;
        for(auto it : tasks){
            mp[it]++;
        }
        //maxheap
        priority_queue<int>pq;
        for(auto it : mp){
            pq.push(it.second);
        }
        // 
        int time  =0 ;
      while(!pq.empty()){
        vector<int>temp;
        for(int i = 0 ; i <= n ; i++){      
             if(!pq.empty()){
               int freq = pq.top();
                pq.pop();
               freq--;
               if(freq >0 ){
                temp.push_back(freq);
               }
               time++;
             } else{
                if(temp.empty()){
                  break;
                }time++;
             }
        }
        //putting those elements back
        for(auto it : temp){
            pq.push(it);
        }
        }
        return time;
    }
};