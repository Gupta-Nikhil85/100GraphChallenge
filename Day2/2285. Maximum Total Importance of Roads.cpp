// Link to the problem:- https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n,0);
        for(auto edge :roads){
            cnt[edge[0]]++;
            cnt[edge[1]]++;
        }
        sort(cnt.begin(), cnt.end());
        long long ans=0;
        for(int i=1;i<=n; i++){
            ans+=(long long) cnt[i-1]*i;
        }
        return ans;
    }
};