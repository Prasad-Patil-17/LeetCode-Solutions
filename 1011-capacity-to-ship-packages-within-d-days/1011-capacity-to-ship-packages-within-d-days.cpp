class Solution {
public:
    bool is_minimum_capacity(vector<int>& weights,int days,int mid){

        int days_count = 1;
        int ship_capacity = mid;

        for(int i=0;i<weights.size();i++){
            if(ship_capacity >= weights[i]){
                ship_capacity -= weights[i];
            }
            else{
                days_count++;
                ship_capacity = mid;
                ship_capacity -= weights[i];
            }
        }

        if(days_count > days) return false;
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        //find the maximum element and the sum of the array//
        int max_element = INT_MIN;
        int arr_sum = 0;
        for(int i=0;i<weights.size();i++){
            max_element = max(weights[i],max_element);
            arr_sum += weights[i];
        }

        //set the lowest and highest capacity//
        int low_capacity = max_element;
        int high_capacity = arr_sum;
        int mid;
        int minimum_capacity = arr_sum;

        //calculate the minimum capacity within the defined range//
        while(low_capacity <= high_capacity){
            mid = low_capacity + (high_capacity - low_capacity)/2;

            if(is_minimum_capacity(weights,days,mid)){
                minimum_capacity = mid;
                high_capacity = mid - 1;
            }
            else low_capacity = mid + 1;
        }

        return minimum_capacity;
    }
};