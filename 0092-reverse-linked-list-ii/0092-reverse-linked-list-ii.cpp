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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || left == right) return head;
        ListNode temp(0,head);
        ListNode* start = &temp;
        for(int i=1;i<left;i++){
            start= start ->next;
        }
        ListNode* middle = start->next;
        for(int i=left;i<right;i++){
            ListNode* nxt = middle->next;
            middle->next = nxt->next;
            nxt->next = start->next;
            start->next = nxt;
        }
        return temp.next;
    }
};