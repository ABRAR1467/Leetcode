/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int>ans;
    unordered_map<int,int>mp;
    int sum = 0;
    void solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    void solve2(TreeNode* root)
    {
        if(root==NULL)return;
        root->val=root->val+sum-mp[root->val];
        solve2(root->left);
        solve2(root->right);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        sort(ans.begin(),ans.end());
        sum = accumulate(ans.begin(),ans.end(),0);
        vector<int>pre(ans.size());
        pre[0]=ans[0];
        mp[ans[0]]=ans[0];
        for(int i=1;i<ans.size();i++)
        {
            pre[i]=pre[i-1]+ans[i];
            mp[ans[i]]=pre[i];
        }
        solve2(root);
        return root;
    }
};