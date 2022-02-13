class Solution {
public:
    vector<vector<int>> reconstructQueue_del(vector<vector<int>>& people) {
        // the bigger, the better
        int num = 0;
        int num_people = people.size();

        vector<vector<int>> res(num_people, vector<int>(2, 0)); // we need to implement the res

        vector<int> is_visited(num_people, 0);

        int bigger_num = 0;

        for(int j=0; j<num_people; j++) {

            // each circle thing

            for(int i=0; i<num_people; i++) {

                if(is_visited[i]) continue;

                num = res.size();
                bigger_num = 0;

                for(int k=0; k<num; k++) {
                    if(people[i][0]<=res[k][0]) bigger_num++;
                }
                if(bigger_num == people[i][1]) {
                    // this is temporaryly right?
                }
            }
        }
        
        return res;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b) {
            // 适当的降序排列
            if (a[0] != b[0]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        for(auto& i : nums){
            if(ans.size() <= i[1])
            ans.push_back(i);
            else{
               ans.insert(ans.begin()+i[1],i); 
            }
        }
        return ans;

    }

};