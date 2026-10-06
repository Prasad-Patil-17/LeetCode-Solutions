class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int i = 0;
        int j = 0;

        int len = 0;
        int max_len = INT_MIN;

        int flips = 0;

        while(j < nums.size()){
            if(nums[j] == 1) j++;
            else if(nums[j] == 0 && flips < 1){
                flips++;
                j++;
            }
            else{
                len = j - i;
                max_len = max(len,max_len);

                while(nums[i] == 1) i++;
                
                i++;
                j++;
            }
        }

        len = j - i;
        max_len = max(len,max_len);

        return max_len - 1;
    }
};