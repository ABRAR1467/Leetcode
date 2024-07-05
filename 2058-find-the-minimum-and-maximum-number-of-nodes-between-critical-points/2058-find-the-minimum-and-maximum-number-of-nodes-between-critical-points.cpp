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
        vector<int>ans;
        int cnt = 2;
        while(head->next->next!=NULL)
        {
            int x=head->val;
            int y=head->next->val;
            int z=head->next->next->val;
            if(x>y&&y<z)ans.push_back(cnt);
            if(x<y&&y>z)ans.push_back(cnt);
            head=head->next;
            cnt++;
        }
        if(ans.size()<2)return {-1,-1};
        else
        {
            int n = ans.size(),a=INT_MAX;
            for(int i=1;i<n;i++)
            {
                a=min(a,ans[i]-ans[i-1]);
            }
            int b = ans[n-1]-ans[0];
            return {a,b};
        }
    }
};