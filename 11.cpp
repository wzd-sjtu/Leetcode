class Solution {
public:
    int maxArea_loop(vector<int>& height) {
        // 这又是什么诡异的题目？
        // 先试一试暴力解
        int N = height.size();
        int res = 0;
        // 无脑暴力循环解
        for(int i=0; i<N-1; i++) {
            for(int j=i+1; j<N; j++) {
                int h = min(height[i], height[j]);
                res = max(res, h*(j-i));
            }
        }
        return res;
    }
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int h = min(height[left], height[right]);
        int res = 0;
        res = max(res, (right-left)*h);

        while(left<right) {
            h = min(height[left], height[right]);
            res = max(res, (right-left)*h);
            if(height[left]>=height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return res;
    }

};