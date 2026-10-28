class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //1. find the next smaller index array//
        stack<int> st;
        vector<int> next_smaller_idx(heights.size());

        next_smaller_idx[heights.size()-1] = heights.size();
        st.push(heights.size()-1);

        for(int i=heights.size()-2;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) next_smaller_idx[i] = heights.size();
            else next_smaller_idx[i] = st.top();

            st.push(i);
        }

        //2. find the previous smaller index//
        stack<int> st2;
        vector<int> prev_smaller_idx(heights.size());

        prev_smaller_idx[0] = -1;
        st2.push(0);

        for(int i=1;i<heights.size();i++){
            while(!st2.empty() && heights[st2.top()] >= heights[i]) st2.pop();

            if(st2.empty()) prev_smaller_idx[i] = -1;
            else prev_smaller_idx[i] = st2.top();

            st2.push(i);
        }

        int max_area = 0;
        for(int i=0;i<heights.size();i++){
            int height = heights[i];
            int width = next_smaller_idx[i] - prev_smaller_idx[i] - 1;
            int area = height * width;
            max_area = max(max_area,area);
        }

        return max_area;
    }
};