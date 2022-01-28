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
    TreeNode* invertTree(TreeNode* root) {
        // the easiest reverse treenode
        if(root == NULL) return NULL;
        TreeNode* tmp = root->left;
        invertTree(root->left);
        invertTree(root->right);
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};