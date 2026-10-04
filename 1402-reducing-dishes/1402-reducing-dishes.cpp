class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        //Sort the satisfaction array
        sort(satisfaction.begin(),satisfaction.end());

        //Create the suffix sum of the satifaction sorted array//
        vector<int> suffix_sum(satisfaction.size());
        suffix_sum[suffix_sum.size()-1] = satisfaction[satisfaction.size()-1];
        for(int i=suffix_sum.size()-2;i>=0;i--){
            suffix_sum[i] = satisfaction[i] + suffix_sum[i+1];
        }

        //find the pivot index//
        int pivot_idx = 0;
        for(int i=suffix_sum.size()-1;i>=0;i--){
            if(suffix_sum[i] < 0){
                pivot_idx = i+1;
                break;
            }
        }

        //return the maximum sum from the suffix array from that pivot index
        int max_sum = 0;
        for(int i=pivot_idx;i<suffix_sum.size();i++){
            max_sum += suffix_sum[i];
        }

        return max_sum;
    }
};