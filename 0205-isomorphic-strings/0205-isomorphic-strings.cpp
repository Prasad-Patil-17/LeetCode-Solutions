class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(t.size() != s.size()) return false;

        vector<int> emp_vec(150,1000);

        for(int i=0;i<s.size();i++){
            int idx = (int)s[i];
            if(emp_vec[idx] == 1000){
                emp_vec[idx] = s[i]-t[i];
            }
            else if(emp_vec[idx] != s[i]-t[i]) return false;
        }

        fill(emp_vec.begin(), emp_vec.end(), 1000);

        for(int i=0;i<s.size();i++){
            int idx = (int)t[i];
            if(emp_vec[idx] == 1000){
                emp_vec[idx] = s[i]-t[i];
            }
            else if(emp_vec[idx] != s[i]-t[i]) return false;
        }

        return true;
    }
};