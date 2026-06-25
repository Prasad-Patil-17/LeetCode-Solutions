class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //find the pivot index//
        int pivot_idx = -1;

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                pivot_idx = i;
                break;
            }
        }


        //find next greater element then the element at pivot_idx and swap it//

        if(pivot_idx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        int next_bigger_idx = -1;
        for(int i=nums.size()-1;i>pivot_idx;i--){
            if(nums[i] > nums[pivot_idx]){
                next_bigger_idx = i;
                break;
            }
        }

        swap(nums[pivot_idx],nums[next_bigger_idx]);


        //reverse the the decreasing suffix after the elements from the pivot_idx//

        int start = pivot_idx + 1;
        int end = nums.size() - 1;

        while(start < end){

            swap(nums[start],nums[end]);

            start++;
            end--;
        }

        return;
    }
};