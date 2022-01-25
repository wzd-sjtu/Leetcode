class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next bigger 序列？
        // 非常经典的思路

        // many outside problem
        int n = nums.size();
        if(n == 1) return;

        int j = n-1;
        for(j = n-1; j>0; j--) {
            if(nums[j] > nums[j-1]) {
                break;
            }
        }
        
        if(j!=0) {
            for(int end = n-1; end>=j; end--) {
                if(nums[end] > nums[j-1]) {
                    swap(nums[end], nums[j-1]);
                    break;
                }
            }
        }
        // reverse the location
        int left = j;
        int right = n-1;
        while(left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        return;
    }
};