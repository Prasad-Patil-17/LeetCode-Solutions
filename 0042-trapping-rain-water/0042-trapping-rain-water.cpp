class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;

        int left_max = 0;
        int right_max = 0;

        int trapped_water = 0;

        while(left <= right){

            if(left_max <= right_max){

                left_max = max(left_max,height[left]);
                trapped_water += left_max - height[left];

                left++;
            }
            else{
                right_max = max(right_max,height[right]);
                trapped_water += right_max - height[right];

                right--;
            }
        }

        return trapped_water;
    }
};