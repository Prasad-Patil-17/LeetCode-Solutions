class Solution {
public:
    int bestClosingTime(string customers) {
        
        int size = customers.size();

        //make the suffix_penalty_array
        vector<int> suffix_penalty(size + 1);
        suffix_penalty[suffix_penalty.size()-1] = 0;
        
        for(int i=suffix_penalty.size()-2;i>=0;i--){
            int Y_count = 0;

            if(customers[i] == 'Y') Y_count++;
            suffix_penalty[i] = suffix_penalty[i+1] + Y_count;
        }

        //make the prefix penalty array
        vector<int> prefix_penalty(size+1);
        prefix_penalty[0] = 0;
        for(int i=0;i<size;i++){
            int N_count = 0;

            if(customers[i] == 'N') N_count++;
            prefix_penalty[i+1] = prefix_penalty[i] + N_count;
        }

        //Add the total penalties//
        for(int i=0;i<prefix_penalty.size();i++){
            prefix_penalty[i] += suffix_penalty[i];
        }

        //Find the minimum penalty and its hour
        int earliest_hr = 0;
        int min_penalty = prefix_penalty[0];
        for(int i=0;i<prefix_penalty.size();i++){
            if(prefix_penalty[i] < min_penalty){
                min_penalty = prefix_penalty[i];
                earliest_hr = i;
            }
        }
        
        int req_ele = prefix_penalty[earliest_hr];

        for(int i=0;i<prefix_penalty.size();i++){
            if(prefix_penalty[i] == req_ele) return i;
        }

        return -1;
    }
};