class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> result(nums.size());

        int positive = 0;
        int negetive = 1;

        for(int i=0;i<nums.size();i++){

            if(nums[i] > 0) {
                result[positive] = nums[i];
                positive += 2;
            }
            else {
                result[negetive] = nums[i];
                negetive += 2;
            }
        }

        return result;
    }
};
