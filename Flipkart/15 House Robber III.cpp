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
    pair<int, int> solve(TreeNode *root) {
        if(!root) return {0, 0};
        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);
        return {root->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second)};
    }
    int rob(TreeNode* root) {
        if(!root->left and !root->right) return root->val;
        pair<int, int> p = solve(root);
        return max(p.first, p.second);
    }
};

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/    
