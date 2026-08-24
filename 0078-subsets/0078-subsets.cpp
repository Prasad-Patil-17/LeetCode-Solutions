class Solution {
public:
    void push_subsets(vector<int>& nums,vector<vector<int>>& emp_vec,int idx,vector<int> temp){

        if(idx > nums.size()-1){
            emp_vec.push_back(temp);
            return;
        }

        int current_element = nums[idx];

        push_subsets(nums,emp_vec,idx+1,temp);
        temp.push_back(current_element);
        push_subsets(nums,emp_vec,idx+1,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> emp_vec;
        vector<int> temp;
        push_subsets(nums,emp_vec,0,temp);

        return emp_vec;
    }
};