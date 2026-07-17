class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());

        string first = strs[0];
        string last = strs[strs.size()-1];

        string emp_str = "";

        for(int i=0;i<(min(first.size(),last.size()));i++){
            if(first[i] == last[i]){
                emp_str += first[i];
            }
            else return emp_str;
        }

        return emp_str;
    }
};