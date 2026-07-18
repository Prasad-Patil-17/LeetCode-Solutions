class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size()) return false;

        unordered_map<char,char> map_1;
        unordered_map<char,char> map_2;

        for(int i=0;i<s.size();i++){

            char ch1 = s[i];
            char ch2 = t[i];

            if(
                map_1.find(ch1) == map_1.end() &&
                map_2.find(ch2) == map_2.end()
            ){
                map_1[ch1] = ch2;
                map_2[ch2] = ch1;
            }
            else if(
                map_1[ch1] != ch2 || map_2[ch2] != ch1
            ) return false;
        }

        return true;
    }
};