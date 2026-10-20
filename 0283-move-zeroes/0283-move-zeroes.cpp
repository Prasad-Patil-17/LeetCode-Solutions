class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int trav = 0;
        int left = 0;

        while(trav < nums.size()){
            if(nums[trav] != 0) {
                swap(nums[trav],nums[left]);
                left++;
            }
            trav++;
            
        }

        return;
    }
};