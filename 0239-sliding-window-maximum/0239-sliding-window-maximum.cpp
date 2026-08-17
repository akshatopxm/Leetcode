class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
         deque<int>dq;
         vector<int> ans;
         for(int i = 0 ; i < n ; i++){
            // remove the outdated elements
            if(!dq.empty()&& dq.front() <= i-k)
            dq.pop_front();
            // remove smaller elements
            while(!dq.empty()&& nums[dq.back()] < nums[i] )
            dq.pop_back();
            //add element 
            dq.push_back(i);
            // if the window is ready 
            if(i>= k-1){
                ans.push_back(nums[dq.front()]);
            }
         }
         return ans;
    }
};