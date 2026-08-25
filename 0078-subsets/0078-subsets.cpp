class Solution {
public:
    void push_subsets(vector<int>& nums,vector<vector<int>>& emp_vec,int idx,vector<int>& temp){

        if(idx > nums.size()-1){
            emp_vec.push_back(temp);
            return;
        }

        //include//
        temp.push_back(nums[idx]);
        push_subsets(nums,emp_vec,idx+1,temp);
        temp.pop_back();

        //exclude//
        push_subsets(nums,emp_vec,idx+1,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> emp_vec;
        vector<int> temp;
        push_subsets(nums,emp_vec,0,temp);

        return emp_vec;
    }
};