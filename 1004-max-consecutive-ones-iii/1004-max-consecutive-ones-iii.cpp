class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;

        int length = 0;
        int max_length = INT_MIN;

        int flips = 0;

        while(j < nums.size()){
            if(nums[j] == 1) j++;
            else if(nums[j] == 0 && flips < k){
                flips++;
                j++;
            }
            else{
                length = j - i;
                max_length = max(max_length,length);

                while(nums[i] == 1) i++;

                i++;
                j++;
            }
        }

        length = j - i;
        max_length = max(max_length,length);

        return max_length;
    }
};