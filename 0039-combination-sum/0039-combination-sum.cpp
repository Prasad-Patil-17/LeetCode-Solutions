class Solution {
public:
    void push_combinations(vector<int> nums,vector<vector<int>>& all_combns,vector<int>& helper,int idx,int target){
    
        if(target == 0){
            all_combns.push_back(helper);
            return;
        }
    
        if(target < 0) return;
        
        for(int i=idx;i<nums.size();i++){
            helper.push_back(nums[i]);
            push_combinations(nums,all_combns,helper,i,target - nums[i]);
            helper.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> all_combns;
        vector<int> helper;

        push_combinations(candidates,all_combns,helper,0,target);

        return all_combns;
    }
};