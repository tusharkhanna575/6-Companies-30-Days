class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        vector<int> frequency(10,0);
        for(int i=0;i<secret.size();i++) {
            int s=secret[i]-'0', g=guess[i]-'0';
            if(s==g) {
                bulls++;
            }
            else {
                if (frequency[g]-->0)  cows++;
                if (frequency[s]++<0)  cows++;
            }
        }
        return(to_string(bulls)+"A"+to_string(cows)+"B");
    }
};

/*
    Time Complexity : O(n)
    Space Complexity : O(1) [since frquency vector is always of size 10]
*/