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
    // ListNode *reverseList(ListNode *head, ListNode *prev=nullptr){
    //     if(!head){
    //         return prev;
    //     }
    //     ListNode *nextNode = head->next;
    //     head->next = prev;
    //     return reverseList(nextNode, head);
    // }

    int pairSum(ListNode* head) {
        ListNode *curr = head;
        vector<int>arr;
        while(curr){
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int left = 0, right = arr.size()-1;
        int maxi = 0;
        while(left<right){
            maxi = max(maxi, (arr[left] + arr[right]));
            left++; right--;
        }

        return maxi;
    }
};