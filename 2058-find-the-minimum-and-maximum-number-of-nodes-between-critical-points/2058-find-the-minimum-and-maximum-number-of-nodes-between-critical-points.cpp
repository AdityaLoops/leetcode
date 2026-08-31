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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head ->next == NULL || head->next->next ==NULL) return {-1,-1};
        ListNode* curr =head->next;
        ListNode* prev = head;
        int mini =INT_MAX, maxi=0;
        int l=0,r=0,f=0;
        int cnt =0;
        while(curr->next){
            cnt++;
            if((curr->val> prev->val && curr->val >curr->next->val) ||
             (curr->val < prev->val && curr->val < curr->next->val)) {
                if(f==0) f=cnt;
                l=r;
                r=cnt;
                }
            

            if(l!=0 && r!=0 && l!=r){
                mini = min(r-l, mini);
                maxi = max(r-f, maxi);
            } 
            prev =curr;
            curr =  curr->next;

        }
        if(mini ==INT_MAX || maxi == 0) return {-1,-1};
        return {mini, maxi};
    }
};