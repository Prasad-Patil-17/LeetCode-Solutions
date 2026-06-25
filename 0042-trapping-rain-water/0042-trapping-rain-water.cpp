class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> prev_greatest(height.size());
        prev_greatest[0] = -1;

        int prev_max = height[0];

        for(int i=1;i<height.size();i++){
            prev_greatest[i] = prev_max;
            if(height[i] > prev_max){
                prev_max = height[i];
            }
        }
        
        prev_greatest[height.size()-1] = -1;
        prev_max = height[height.size()-1];

        for(int i=height.size()-2;i>=0;i--){

            if(prev_greatest[i] > prev_max){
                prev_greatest[i] = prev_max;
            }
            if(height[i] > prev_max){
                prev_max = height[i];
            }
        }
        int trapped_water = 0;

        for(int i=0;i<height.size();i++){
            if(height[i] < prev_greatest[i]){
                trapped_water += (prev_greatest[i]-height[i]);
            }
        }

        return trapped_water;
    }
};