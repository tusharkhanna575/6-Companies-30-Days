class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> str{bank.begin(),bank.end()};
        if(!str.count(end)) {
            return -1;
        }
        queue<string> Q;
        Q.push(start);
        int steps=0,s;
        string cur,t;
        while(!Q.empty()) {
            s=Q.size();
            while(s--){
                cur=Q.front();
                Q.pop();
                if(cur==end) {
                    return steps;
                }
                str.erase(cur);
                for(int i=0;i<8;i++) {
                    t=cur;
                    t[i]='A';
                    if(str.count(t)) {
                        Q.push(t);
                    }
                    t[i]='C';
                    if(str.count(t)) {
                        Q.push(t);
                    }
                    t[i]='G';
                    if(str.count(t)) {
                        Q.push(t);
                    }
                    t[i]='T';
                    if(str.count(t)) {
                        Q.push(t);
                    }
                }
                }
            steps++;
        }
        return -1;
     }
};


/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
