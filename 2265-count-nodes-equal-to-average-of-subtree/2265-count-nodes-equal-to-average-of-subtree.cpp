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
    pair<int,int> solve(TreeNode* node, int &ans, int sum, int total ){
    if(node == NULL) return {0,0};

    pair<int, int> left = solve(node->left, ans, sum, total);
    pair<int, int> right = solve(node->right, ans, sum, total);
   

    sum = node->val + left.first + right.first;
    total = left.second + right.second +1;
    int avg;
    if(total == 0) avg = node->val;
    else avg = sum/total;

    if( node->val == avg) ans++;
    // cout<< node->val << ' ' << ans << "\n";
    return {sum, total};
 }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans =0;
        pair<int,int> x = solve(root,ans, 0,0);
        return ans;
    }
};