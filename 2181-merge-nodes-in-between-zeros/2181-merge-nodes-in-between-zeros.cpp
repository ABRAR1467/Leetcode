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
    ListNode* rev(ListNode* head)
    {
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while(current!=NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        head=head->next;
        if(!head)return NULL;
        ListNode* temp = head;
        while(temp->val!=0)
        {
            sum+=temp->val;
            temp=temp->next;
        }
        head->val = sum;
        head->next = mergeNodes(temp);
        return head;
    }
};