class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0;
        int j = 0;

        int sum = 0;
        int current_length = 0;
        int minimum_length = INT_MAX;

        while(j < nums.size()){
            sum += nums[j];

            while(sum >= target){
                current_length = (j - i + 1);
                minimum_length = min(minimum_length,current_length);
                sum -= nums[i];

                i++;
            }

            j++;
        }

        if(minimum_length == INT_MAX) return 0;

        return minimum_length;
    }
};