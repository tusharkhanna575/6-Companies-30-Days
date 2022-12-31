class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto i: tokens) {
            if(isdigit(i[0]) || i.size()>1) {
                st.push(stoi(i));
            }
            else {
                long long int x=st.top();
                st.pop();
                long long int y=st.top();
                st.pop();
                long long int result=0;
                if(i=="+") {
                    result=x+y;
                }
                else if(i=="-") {
                    result=y-x;
                }
                else if(i=="*") {
                    result=x*y;
                }
                else if(i=="/") {
                    result=y/x;
                }
                st.push(result);
            }
        }
        return st.top();
    }
};


/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
