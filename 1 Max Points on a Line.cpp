class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)    return 1;

        int res=INT_MIN;  
        for(int i=0;i<points.size();i++){
            unordered_map<float, int> mp;
            double sloap;
            int x_axis=0;
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]==points[j][0]){
                    x_axis++;
                    if(x_axis>res) {
                        res = x_axis;
                    }
                }
                else{
                    sloap = ((double)points[i][1]-(double)points[j][1])/((double)points[i][0]-(double)points[j][0]);                    
                    mp[sloap]++;
                    if(mp[sloap]>res) {
                        res = mp[sloap];
                    }
                }
            }            
        }
        return res+1;
    }
};

/*
    Time Complexity : O(n^2)
    Space Complexity : O(n)
*/
