class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {

        vector<int> answer(nums.size());
        stack<int> st;

        answer[nums.size()-1] = 0;
        st.push(nums[nums.size()-1]);

        for(int i=nums.size()-2;i>=0;i--){

            int count = 0;
            bool flag = false;
            while(!st.empty() && st.top() <= nums[i]){
                flag = true;
                count++;
                st.pop();
            }

            if(!flag) answer[i] = (++count);
            else if(flag && !st.empty()) answer[i] = (++count);
            else answer[i] = count;

            st.push(nums[i]);
        }

        return answer;
    }
};