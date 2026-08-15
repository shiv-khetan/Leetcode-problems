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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;

        if(root!=NULL)q.push({root,0});

        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int curr_h=q.front().second;
            q.pop();

            if(curr_h == ans.size()){
                ans.push_back({});
            }
            if(temp !=NULL){
                ans[curr_h].push_back(temp->val);
                if(temp->left!=NULL)q.push({temp->left,curr_h+1});
                if(temp->right!=NULL)q.push({temp->right,curr_h+1});
            }
        }

        return ans;
    }
};