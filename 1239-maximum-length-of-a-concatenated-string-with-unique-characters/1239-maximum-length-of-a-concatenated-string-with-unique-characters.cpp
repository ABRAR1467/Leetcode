class Solution {
    unordered_map<string,int>mp;
    bool hasduplicate(string &s1,string &s2)
    {
        vector<int>freq(26,0);
        for(char ch: s1)
        {
            if(freq[ch-'a']>0)return true;
            freq[ch-'a']++;
        }
        for(char ch:s2)
        {
            if(freq[ch-'a']>0)return true;
        }
        return false;
    }
    int solve(int ind,int n,vector<string>& arr,string temp)
    {
        if(ind>=n)
        {
            return temp.size();
        }
        if(mp.find(temp)!=mp.end())return mp[temp];
        int include = 0;
        int exclude = 0;
        if(!hasduplicate(arr[ind],temp))
        {
            include = solve(ind+1,n,arr,temp+arr[ind]);
        }
        exclude = solve(ind+1,n,arr,temp);
        return mp[temp] = max(include,exclude);
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return solve(0,n,arr,temp);
    }
};