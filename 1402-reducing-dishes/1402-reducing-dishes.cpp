class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int len = satisfaction.size();

        sort(satisfaction.begin(),satisfaction.end()); 

        vector<int> suffix_sum_arr(len);
        suffix_sum_arr[len-1] = satisfaction[len-1];

        for(int i=len-2;i>=0;i--){
            suffix_sum_arr[i] = suffix_sum_arr[i+1] + satisfaction[i];
        }

        int pivot_idx = -1;
        for(int i=0;i<len;i++){
            if(suffix_sum_arr[i] >=0 ){
                pivot_idx = i;
                break;
            }
        }

        if(pivot_idx == -1) return 0;

        int time_coeff = 1;
        int max_sum = 0;
        for(int i=pivot_idx;i<len;i++){
            max_sum += (satisfaction[i]*(time_coeff++));
        }

        return max_sum;

    }
};