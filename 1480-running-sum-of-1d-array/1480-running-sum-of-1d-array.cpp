class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        // vector<int> run_sum(nums.size());
        // run_sum[0] = nums[0];

        // for(int i=1;i<nums.size();i++){
        //     run_sum[i] = nums[i] + run_sum[i-1];
        // }

        // return run_sum;

        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }

        return nums;
    }
};