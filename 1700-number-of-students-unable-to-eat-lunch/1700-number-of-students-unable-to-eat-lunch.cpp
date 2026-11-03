class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        //1. make the students array as queue
        queue<int> stud_q;
        for(int i=0;i<students.size();i++){
            stud_q.push(students[i]);
        }

        int size = stud_q.size();
        int j = 0;
        int unsatisfied_count = 0;

        while(!stud_q.empty() && unsatisfied_count < stud_q.size()){
            if(stud_q.front() == sandwiches[j]){
                stud_q.pop();
                j++;
                unsatisfied_count = 0;
            }
            else{
                int temp = stud_q.front();
                stud_q.pop();
                stud_q.push(temp);
                unsatisfied_count++;
            }
        }

        return stud_q.size();
    }
};