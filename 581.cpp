class Solution {
public:
    int findUnsortedSubarray_del(vector<int>& nums) {
        // 一看就是典型的滑动窗口双指针类型
        int max_num = INT_MIN, min_num = INT_MAX;

        int res_len = 0;
        int N = nums.size();
        if(N == 0 || N == 1) return res_len;

        // 一种法子是无脑排序，找到前后两个不同的点即可得之

        vector<int> sorted_nums(N, 0);
        for(int i=0; i<N; i++) sorted_nums[i] = nums[i];

        sort(sorted_nums.begin(), sorted_nums.end());

        int left_loc = -1, right_loc = -1;
        for(int i=0; i<N; i++) {
            if(sorted_nums[i] != nums[i]) {
                left_loc = i;
                break;
            }
        }
        for(int i=N-1; i>=0; i--) {
            if(sorted_nums[i] != nums[i]) {
                right_loc = i;
                break;
            }
        }
        // 非常丑陋的暴力解法
        if(left_loc == -1) return 0;

        return right_loc-left_loc+1;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        int low = -1, high = -1;
        int N = nums.size();

        int max_num = nums[0], min_num = nums[N-1];

        if(N==0 || N==1) return 0;
        for(int i=0; i<N; i++) {
            if(nums[i] < max_num) {
                high = i; 
            }
            else {
                max_num = nums[i];
            }
        }

        for(int i=N-1; i>=0; i--) {
            if(nums[i] > min_num) {
                low = i;
            }
            else {
                min_num = nums[i];
            }
        }
        if(high == -1) return 0;

        return high - low + 1;
    }
};