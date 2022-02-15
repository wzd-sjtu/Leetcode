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
    int left;
    int right;
    int max_len;
    int diameterOfBinaryTree_del(TreeNode* root) {
        // 左子树深度+右子树深度
        left = 0;
        right = 0;

        if(root == NULL) return 0;

        dfs_del(root->left, 0, 0);
        dfs_del(root->right, 0, 1);

        // cout << left << "   " << right << endl;
        return left + right + 1;
    }

    void dfs_del(TreeNode* root, int pre_depth, int left_or_right) {
        if(root == NULL) {
            if(left_or_right == 0) {
                left = max(left, pre_depth);
            }
            else {
                right = max(right, pre_depth);
            }
            // here少加了一句重要的话
            return;
        }
        else {
            dfs_del(root->left, pre_depth+1, left_or_right);
            dfs_del(root->right, pre_depth+1, left_or_right);
        }
        return;
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // 可能穿过也可能不穿过根节点，这一点是处理的核心逻辑？
        max_len = 0;
        if(root == NULL) return max_len;
        dfs(root);

        return max_len;
    }

    int dfs(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return 0;
        }
        int left_len = 0, right_len = 0;

        if(root->left == NULL) {
            left_len = 0;
        }
        else {
            // dfs计算的是树的深度， 不包括根节点
            left_len = dfs(root->left) + 1;
        }

        if(root->right == NULL) {
            right_len = 0;
        }
        else {
            right_len = dfs(root->right) + 1;
        }

        max_len = max(max_len, left_len + right_len);

        return max(left_len, right_len);

    }

};