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
    int count=0;
    pair<int,int> dfs(TreeNode*root){
        if(!root) return {0,0};
        int nodes = 0;
        int sum = root->val;
        pair<int,int> pl = dfs(root->left);
        pair<int,int> pr = dfs(root->right);
        sum += pl.first+pr.first;
        nodes = 1+pl.second+pr.second;
        if(sum/nodes==root->val) count++;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};


/* 
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
