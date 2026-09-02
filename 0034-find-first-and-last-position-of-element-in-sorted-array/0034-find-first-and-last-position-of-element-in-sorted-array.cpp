class Solution {
public:

    int get_first_occurence(vector<int>& nums, int target) {

        if(nums.empty()) return -1;

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {

                if(mid == 0 || nums[mid - 1] != target)
                    return mid;

                else
                    high = mid - 1;
            }

            else if(nums[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }


    int get_last_occurence(vector<int>& nums, int target) {

        if(nums.empty()) return -1;

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {

                if(mid == nums.size() - 1 || nums[mid + 1] != target)
                    return mid;

                else
                    low = mid + 1;
            }

            else if(nums[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }


    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> occ_indices;

        int first_occ_idx = get_first_occurence(nums, target);
        int last_occ_idx = get_last_occurence(nums, target);

        occ_indices.push_back(first_occ_idx);
        occ_indices.push_back(last_occ_idx);

        return occ_indices;
    }
};