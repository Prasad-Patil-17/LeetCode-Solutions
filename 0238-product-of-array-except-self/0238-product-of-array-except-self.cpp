class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        //find prefix_prod one less
        vector<int> prefix(nums.size());
        prefix[0] = 1;
        for(int i=1;i<nums.size();i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        //store the result in the prefix_itsef
        int next_prod = 1;
        for(int i=nums.size()-1;i>=0;i--){
            prefix[i] = prefix[i] * next_prod;
            next_prod = next_prod * nums[i];
        }

        return prefix;
    }
};