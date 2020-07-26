/*
    2.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head=new ListNode(0);
        ListNode* node;
        node=head;
        int carry=0;
        while(temp1!=NULL||temp2!=NULL)
        {
            int x=0;
            int y=0;
            if(temp1!=NULL)
            {
                x=temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL)
            {
                y=temp2->val;
                temp2=temp2->next;
            }
            int sum=carry+x+y;
            node->next=new ListNode(sum%10);
            carry=(sum)/10;
            node=node->next;

        }
        if(carry>0)
        {
            node->next=new ListNode(carry);
        }
        return head->next;
    }
};
