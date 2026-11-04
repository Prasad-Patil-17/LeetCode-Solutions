class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> result;

        for(int i=0;i<nums.size();i++){

            //if current element is greater than the element in deque pop cont;
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();

            //if element is small push at the back//
            dq.push_back(i);

            //if the previous maximum in the deque lies before the window range pop from font//
            while(!dq.empty() && dq.front() < (i-k+1)) dq.pop_front();

            //if we reach the end of the window front will always be the maximum//
            if(i >= k-1) result.push_back(nums[dq.front()]);
        }

        return result;
    }
};