class Solution {
public:
    bool is_minimum_speed(vector<int>& piles,int h,int current_speed){

        long long hour_count = 0;

        for(int i=0;i<piles.size();i++){
            if(current_speed > piles[i]) hour_count++;
            else if(piles[i] % current_speed == 0){
                hour_count += (piles[i]/current_speed);
            }
            else hour_count += (piles[i]/current_speed) + 1;
        }

        if(hour_count > h) return false;
        else return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        //find the maximum element
        int max_element = INT_MIN;
        for(int i=0;i<piles.size();i++){
            max_element = max(max_element,piles[i]);
        }

        int low_speed = 1;
        int high_speed = max_element;
        int minimum_speed = -1;

        while(low_speed <= high_speed){
            int current_speed = low_speed + (high_speed - low_speed)/2;

            if(is_minimum_speed(piles,h,current_speed)){
                minimum_speed = current_speed;
                high_speed = current_speed - 1;
            }
            else low_speed = current_speed + 1;
        }

        return minimum_speed;
    }
};