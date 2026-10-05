class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        //Find the window that has most loss of satisfaction//

        int prev_loss = 0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i] == 1){
                prev_loss += (grumpy[i] * customers[i]);
            }
        }

        int max_loss = prev_loss;

        int i = 1;
        int j = minutes;

        int start_idx = 0;
        int end_idx = minutes-1;

        while(j < customers.size()){
            int curr_loss = prev_loss + (grumpy[j]*customers[j]) - (grumpy[i-1]* customers[i-1]);

            if(curr_loss >= max_loss){
                max_loss = curr_loss;
                start_idx = i;
                end_idx = j;
            }

            prev_loss = curr_loss;
            i++;
            j++;
        }

        //make the 1bit = 0bit from start_idx to end_idx//
        for(int i=start_idx;i<=end_idx;i++){
            if(grumpy[i] == 1) grumpy[i] = 0;
        }

        //return the comparison sum//
        int max_satisfaction_sum = 0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i] == 0) max_satisfaction_sum += (customers[i]);
        }

        return max_satisfaction_sum;
    }
};