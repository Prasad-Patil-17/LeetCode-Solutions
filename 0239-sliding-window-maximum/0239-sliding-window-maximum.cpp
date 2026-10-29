class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0 || k <= 0 || k > n) {
            return {};
        }

        // Find the next greater element index.
        vector<int> next_greater_idx(n);
        stack<int> st;

        next_greater_idx[n - 1] = n;
        st.push(n - 1);  // Push the index, not the value.

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                next_greater_idx[i] = n;
            } else {
                next_greater_idx[i] = st.top();
            }

            st.push(i);
        }

        // Move the sliding window.
        int i = 0;
        int j = k - 1;

        vector<int> sliding_window_max;

        while (j < n) {
            int itr = i;
            int current_window_max = nums[itr];

            while (next_greater_idx[itr] < i + k) {
                itr = next_greater_idx[itr];
                current_window_max = nums[itr];
            }

            sliding_window_max.push_back(current_window_max);

            i++;
            j++;
        }

        return sliding_window_max;
    }
};