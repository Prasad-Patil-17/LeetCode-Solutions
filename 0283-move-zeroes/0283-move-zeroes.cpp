class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int left = 0;

        for(int trav=0;trav<nums.size();trav++){
            if(nums[trav] != 0){
                swap(nums[trav],nums[left]);
                left++;
            }
        }

        return;
    }
};