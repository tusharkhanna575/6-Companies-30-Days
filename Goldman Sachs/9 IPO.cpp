class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> q;
        vector<pair<int, int>> v;
        for (int i = 0; i < Profits.size(); i++) {
            v.push_back({Capital[i], Profits[i]});
        }
        sort(v.begin(), v.end());
        int i = 0;
        while (k--) {
            while (i < v.size() && v[i].first <= W) {
                q.push(v[i].second);
                i++;
            }
            if (q.empty()) {
                break;
            }
            W += q.top();
            q.pop();
        }
        return W;
    }
};


/*
    Time Complexity : O(nlogn)
    Space Complexity : O(n)
*/
