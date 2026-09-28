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
    pair<int,int> solve(TreeNode* node){
        if(node == NULL) return {0,0};

        pair<int,int> left = solve(node->left);
        pair<int,int> right = solve(node->right);
        int take = node->val + left.second + right.second;
        int skip = max(left.first, left.second) + max(right.first, right.second);

        
        return {take, skip};

    }
public:
    int rob(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};