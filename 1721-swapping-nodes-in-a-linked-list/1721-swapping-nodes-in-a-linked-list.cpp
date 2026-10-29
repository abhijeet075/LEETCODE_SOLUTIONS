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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left,*right=head;
        ListNode *ptr=head;
        int i=1;
        ListNode *temp = head;
        int l =0 ;
        while(temp != NULL)
        {
            temp = temp ->next;
            l++;
        }
        while(ptr!=NULL)
        {
            if(i==k)
            {
                left=ptr;
                break;
            }
            ptr=ptr->next;
            i++;
        }
        int j=1;
        for(int i= 0;i<l-k;i++)
        {
            right =right ->next;
        }
        int val = left->val;
        left->val = right->val;
        right->val = val;


        return head;

    }
};