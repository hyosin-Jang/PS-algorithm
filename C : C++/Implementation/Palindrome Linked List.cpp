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
    bool isPalindrome(ListNode* head) {
        ListNode* head_ptr = head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next){
            fast = fast->next->next;
            slow = slow -> next;
        }
        if(fast){
            slow = slow->next;
        }
        if(!slow){
            return true;
        }
        ListNode* second_half_head = slow;
        while(second_half_head->next){
            second_half_head = second_half_head->next;
        }
        ListNode* prev = nullptr;
        while(slow){
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        while(second_half_head){
            if(second_half_head->val!=head_ptr ->val){
                return false;
            }
            second_half_head= second_half_head->next;
            head_ptr = head_ptr->next;
        }
        return true;
    }
};
