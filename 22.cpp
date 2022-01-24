class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        // 生成括号的组合
        // 最好是使用dfs或者bfs？
        dfs(n, n, "");

        return res;
    }
    // again a bracket
    void dfs(int left, int right, string tmp) {
        if(left==0 && right==0) {
            res.push_back(tmp);
        }

        if(left>0) {
            dfs(left-1, right, tmp+'(');
        }
        if(right>left) {
            dfs(left, right-1, tmp+')');
        }
    }
};