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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* nxt = head;
        if(nxt == nullptr || nxt ->next == nullptr) return head;
        ListNode dummy(0);
        ListNode* temp =&dummy;
        while(nxt!= nullptr){
            int prev = nxt->val , nt = nxt->next==nullptr?-1:nxt->next->val ;
            if(nxt ->next != nullptr && prev == nt ){
                while(nxt!= nullptr && nxt->val == nt){
                    nxt = nxt ->next;
                }
            }else{
                temp->next = nxt;
                temp = temp ->next;
                nxt = nxt->next;
            }
        }
        temp->next = nullptr;
        return dummy.next;
    }
};