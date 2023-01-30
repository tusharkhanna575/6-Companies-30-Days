class Solution {

private :
    bool isprime(int n)
    {
        if(n==2)return true;
        if(n==1 || n%2==0)return false;
        for(int i=3;i*i<=n;i+=2)
        {
            if(n%i==0)return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> v;
        int cnt=0;
        for(int i=left ;i <= right ; i++ )
        {
            if(isprime(i)){
            v.push_back(i);
            cnt++;
            }
        }
        if(cnt<2)return {-1,-1};
        int num2=v[v.size()-1],num1=v[v.size()-2];
        int diff=num2-num1;
        for(int i=v.size()-2;i>=1;i--)
        {
            if(diff>=v[i]-v[i-1])
            {
                diff=v[i]-v[i-1];
                num2=v[i];
                num1=v[i-1];
            }
        }
        return {num1,num2};
    }
};

/*
  Time Complexity : O(n^2)
  Space Complexity : O(n)
*/  
