class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> result;

        //case1(element not present in the array)
        if(x < arr[0]){
            int upper_bound = 0;
            for(int i=upper_bound;i<k;i++){
                result.push_back(arr[i]);
            }
            sort(result.begin(),result.end());
            return result;
        }

        //case2(element not present in the array)
        if(x > arr[arr.size()-1]){
            int lower_bound = arr.size()-1;
            int pusher_idx = arr.size()-1;

            while(pusher_idx >= k){
                result.push_back(arr[pusher_idx]);
                pusher_idx--;
                lower_bound--;
            }

            sort(result.begin(),result.end());
            return result;
        }

        //case3(element is present in the array)
        int low = 0;
        int high = arr.size()-1;
        bool flag = false;
        int mid = -1;

        while(low <= high){
            mid = low + (high-low)/2;

            if(arr[mid] == x){
                flag = true;
                result.push_back(arr[mid]);
                break;
            }
            else if(arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }

        int lower_bound = high;
        int upper_bound = low;

        if(flag == true){
            lower_bound = mid - 1;
            upper_bound = mid + 1;
        }

        while(result.size() < k && lower_bound >=0 && upper_bound <= arr.size()-1){
            int left_diff = abs(arr[lower_bound] - x);
            int right_diff = abs(arr[upper_bound] - x);

            if(left_diff <= right_diff){
                result.push_back(arr[lower_bound]);
                lower_bound--;
            }
            else if(right_diff < left_diff){
                result.push_back(arr[upper_bound]);
                upper_bound++;
            }
        }

        if(lower_bound < 0){
            while(result.size() < k){
                result.push_back(arr[upper_bound]);
                upper_bound++;
            }
        }
        if(upper_bound > arr.size()-1){
            while(result.size() < k){
                result.push_back(arr[lower_bound]);
                lower_bound--;
            }
        }

        sort(result.begin(),result.end());
        return result;
    }
};