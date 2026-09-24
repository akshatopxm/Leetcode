class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
       int min1 = INT_MAX, min2 = INT_MAX; 
       for(auto it : prices){
        if(it < min1){
            min2 = min1;
            min1 = it;
        }
        else if (min2 > it){
            min2 =it;
        }
       }
       int sum = min1 + min2;
    if(money >= sum ) return money - sum;
    return money;
    }
};