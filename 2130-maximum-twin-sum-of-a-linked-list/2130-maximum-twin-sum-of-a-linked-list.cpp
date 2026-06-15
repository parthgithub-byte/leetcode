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
    ListNode *reverseList(ListNode *head, ListNode *prev=nullptr){
        if(!head){
            return prev;
        }
        ListNode *nextNode = head->next;
        head->next = prev;
        return reverseList(nextNode, head);
    }

    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        slow = reverseList(slow);

        int ans = 0;
        while(head){
            ans = max(ans, slow->val + head->val);
            slow = slow->next;
            head = head->next;
        }

        return ans;
    }
};