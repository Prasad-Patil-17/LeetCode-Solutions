class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        //Sort the nums array
        sort(nums.begin(),nums.end());

        //Create the prefix sum of the nums array//
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }

        vector<int> answer(queries.size());

        //Apply double loop for now//
        for(int i=0;i<queries.size();i++){
            
            int current_length = 0;

            int low = 0;
            int high = nums.size()-1;

            while(low <= high){
                int mid = low + (high-low)/2;

                if(nums[mid] > queries[i]) high = mid - 1;
                else{
                    current_length = mid + 1;
                    low = mid + 1;
                }
            }

            answer[i] = current_length;
        }

        return answer;
    }
};