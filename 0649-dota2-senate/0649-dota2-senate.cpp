class Solution {
public:
    string predictPartyVictory(string senate) {

        //create 3 queues each one for r,d and string senate;
        queue<int> q;
        queue<int> r;
        queue<int> d;

        for(int i=0;i<senate.size();i++){
            q.push(i);
            if(senate[i] == 'R') r.push(i);
            if(senate[i] == 'D') d.push(i);
        }

        //traverse the senate queue(q);

        while(!q.empty()){
            if(senate[q.front()] == 'X') q.pop();
            else if(senate[q.front()] == 'R'){
                if(d.empty()) return "Radiant";
                else{
                    senate[d.front()] = 'X';
                    d.pop();

                    q.push(q.front());
                    q.pop();

                    r.push(r.front());
                    r.pop();
                }
            }
            else{
                if(r.empty()) return "Dire";
                else{
                    senate[r.front()] = 'X';
                    r.pop();

                    q.push(q.front());
                    q.pop();

                    d.push(d.front());
                    d.pop();
                }
            }
        }

        if(senate[q.front()] == 'R') return "Radiant";

        return "Dire"; 
    }
};