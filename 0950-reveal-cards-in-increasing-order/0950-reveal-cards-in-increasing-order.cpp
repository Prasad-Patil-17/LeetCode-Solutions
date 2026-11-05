class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n = deck.size();

        // Sort cards in increasing order
        sort(deck.begin(), deck.end());

        queue<int> q;

        // Store indices in the queue
        for(int i = 0; i < n; i++) {
            q.push(i);
        }

        vector<int> result(n);

        for(int i = 0; i < n; i++) {

            // Reveal the next card at the front index
            result[q.front()] = deck[i];
            q.pop();

            // Move the next index to the back
            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return result;
    }
};
