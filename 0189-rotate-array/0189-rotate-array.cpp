class Solution {
public:

    void reverse_parts(int start,int end,vector<int>& nums){

        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }

        return;
    }

    void rotate(vector<int>& nums, int k) {

        if(k > nums.size()) k = k % nums.size();

        reverse_parts(nums.size()-k,nums.size()-1,nums);
        reverse_parts(0,nums.size()-k-1,nums);
        reverse_parts(0,nums.size()-1,nums);

        return;
    }
};