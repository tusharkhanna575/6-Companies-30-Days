class Solution {
public:
    const int NUM_SECTIONS = 12;
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector <int> arrowsRequiredForSection;
        for (int numSectionArrowsAlice: aliceArrows) {
            arrowsRequiredForSection.push_back(numSectionArrowsAlice+1);
        }
        
        vector <int> sectionPoints;
        for (int i=0; i<NUM_SECTIONS; i++) {
            sectionPoints.push_back(i);
        }
        vector<int> optimalShots =  knapsack(numArrows, arrowsRequiredForSection, sectionPoints);
        int arrowsUsed = accumulate(optimalShots.begin(), optimalShots.end(), 0);
        if (numArrows > arrowsUsed) {
            optimalShots[0] += numArrows - arrowsUsed;
        }
        
        return optimalShots;
        
    }
    
    vector <int> knapsack(const int capacity, const vector<int>& costs, const vector<int>& itemValues) {
                
        int numItems = costs.size();
        int dp[numItems+1][capacity+1];
        bool isCurItemPicked[numItems+1][capacity+1];
        memset(dp,0,sizeof(dp));
        memset(isCurItemPicked,0,sizeof(isCurItemPicked));
        for (int i=1; i<=numItems; i++) {
            for (int j=1; j<=capacity; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= costs[i-1]) {
                    int valueIfCurItemIsPicked = dp[i-1][j-costs[i-1]] + itemValues[i-1];
                    if (valueIfCurItemIsPicked > dp[i][j]) {
                        dp[i][j] = valueIfCurItemIsPicked;
                        isCurItemPicked[i][j] = true;
                    }
                }
                
            }
        }
        vector <int> spent;
        int weight = capacity;
        for (int i=numItems; i>0; i--) {            
            if (isCurItemPicked[i][weight]) {
                weight -= costs[i-1];
                spent.push_back(costs[i-1]);
            } else {
                spent.push_back(0);
            }
        }
        reverse(spent.begin(), spent.end());
        return spent;
    }
};


/*
    Time Complexity : O(n^2)
    Space Complexity : O(n^2)
*/
