class Solution {
public:
    void push_subsets(vector<int>& nums,int idx,vector<int>& temp,vector<vector<int>>& all_subsets){

        if(idx > nums.size()-1){
            all_subsets.push_back(temp);
            return;
        }

        //include
        int curr_ele = nums[idx];

        temp.push_back(curr_ele);
        push_subsets(nums,idx+1,temp,all_subsets);
        temp.pop_back();

        //check_duplicates
        int ptr = idx+1;
        while(ptr < nums.size() && nums[ptr] == nums[ptr-1]) ptr++;

        //exclude
        push_subsets(nums,ptr,temp,all_subsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> all_subsets;
        vector<int> temp;

        push_subsets(nums,0,temp,all_subsets);

        return all_subsets;
    }
};