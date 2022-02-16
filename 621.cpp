class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 可以不断遍历26个字母来进行
        vector<int> need_wait_time(26, 0);
        vector<int> task_num(26, 0);
        int N = tasks.size();

        int total_task_num = 0;
        for(int i=0; i<N; i++) {
            task_num[tasks[i] - 'A']++;
            total_task_num++;
        }

        // 每次需要对task_num进行排序？
        // 每次都重建队列？
        int time = 0;
        int loc = -1;
        int loc_task_num = 0;
        while(total_task_num>0) {
            time++;

            loc = -1;
            loc_task_num = 0;

            for(int i=0; i<26; i++) {
                if(need_wait_time[i] == 0 && task_num[i] > loc_task_num) {

                    // 信息更新是重要的
                    loc = i;
                    loc_task_num = task_num[i];
                }
            }

            for(int i=0; i<26; i++) {
                if(need_wait_time[i] > 0) need_wait_time[i]--;
            }


            if(loc != -1) {
                // 代码位置有误
                total_task_num--;
                task_num[loc]--;
                need_wait_time[loc] = n; // 增加一个重要的冷却时间
            }

            //cout << "时间为：" << time << endl;
            //cout << "本次运行位置" << loc << endl;
        }

        return time;
    }
};