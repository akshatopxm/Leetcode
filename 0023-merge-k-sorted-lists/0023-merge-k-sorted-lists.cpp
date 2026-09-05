/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
struct comparator{
    bool operator()(ListNode*a , ListNode*b){
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,comparator>pq;
       for(ListNode* it : lists){
            if(it != nullptr){
                pq.push(it);
            }  
             }
             ListNode* temp = new ListNode(0);
        ListNode* tail = temp;
        while (!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            
            tail -> next = node;
            tail = node;
            if(node->next != nullptr){
                pq.push(node -> next);
            }
        }
        return temp -> next;
    }
};