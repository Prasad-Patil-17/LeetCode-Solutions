class Solution {
public:
    
    int laga_binary_search(int low,int high,vector<int> nums,int target){

        while(low <= high){

            int mid = low + (high-low)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 2){
            if(target == nums[0]) return 0;
            else if(target == nums[1]) return 1;
            else return -1;
        }

        int low = 0;
        int high = nums.size() - 1;
        int pivot = -1;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(mid == 0) low = mid + 1;
            else if(mid == nums.size() - 1) high = mid - 1;
            else if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]){
                pivot = mid;
                break;
            }
            else if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                pivot = mid + 1;
                break;
            }
            else if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        if(pivot == -1){

            int low = 0;
            int high = nums.size()-1;

            int res = laga_binary_search(low,high,nums,target);
            return res;

        }
        else if(target >= nums[0] && target <= nums[pivot-1]){

            int low = 0;
            int high = pivot - 1;

            int res = laga_binary_search(low,high,nums,target);

            return res;
        }
        else{

            int low = pivot;
            int high = nums.size() - 1;

            int res = laga_binary_search(low,high,nums,target);

            return res;
        }

        return -1;
    }
};