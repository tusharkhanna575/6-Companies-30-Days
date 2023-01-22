class Solution {
private:
    void getip(vector<string> &temp, vector<string>&ip, string &s, int index) {
        if(index==s.size() && temp.size()==4) {
            string valid_ip=temp[0]+'.'+temp[1]+'.'+temp[2]+'.'+temp[3];
            ip.push_back(valid_ip);
            return;
        }
        string temp_str="";
        for(int i=index; i<s.size() && temp.size()<4; i++) {
            if(s[i]-'0' >9) {
                continue;
            }
            temp_str += s[i];
            int temp_int=stoi(temp_str);
            if(0<=temp_int && temp_int<=255) {
                temp.push_back(temp_str);
                getip(temp, ip, s, i+1);
                temp.pop_back();
            }
            if(temp_int<=0 || temp_int>255) {
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ip;
        vector<string> temp;
        getip(temp, ip, s, 0);
        return ip;
    }
};


/*
    Time Complexity : O(1)
    Space Complexity : O(1)
*/
