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
    int res;
    vector<int> prefix_sum_path;
    int targetSum_now;
    // 不妨使用树形前缀和

    int pathSum(TreeNode* root, int targetSum) {
        res = 0;
        targetSum_now = targetSum;

        // 做一个最基本的加法
        // if(targetSum_now == 0) res++;

        prefix_sum_path.push_back(0);
        // dfs函数最好补一个depth参数，用于提升速度
        dfs(root); // this is somehow complex
        prefix_sum_path.pop_back();
        
        return res;
    }
    // 处理的logic稍微有点小问题了

    void dfs(TreeNode* root) {

        if(root!=NULL) {

            int n = prefix_sum_path.size();
            int add_sum = prefix_sum_path[n-1] + root->val;
            prefix_sum_path.push_back(add_sum);
            n++;

            for(int i=n-2; i>=0; i--) {
                if(prefix_sum_path[n-1]-prefix_sum_path[i] == targetSum_now) {
                    res++;
                }
            }

            dfs(root->left);
            dfs(root->right);

            prefix_sum_path.pop_back();
        }

        return;
    }
};