class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(int i=0;i<arr1.size();i++)
        {
            mp[arr1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<arr2.size();i++)
        {
            //cout<<mp[arr2[i]]<<endl;
            int x = mp[arr2[i]];
            for(int j=0;j<x;j++)
            {
                ans.push_back(arr2[i]);
            }
            if(mp[arr2[i]])mp.erase(arr2[i]);
        }
        auto it = mp.begin();
        while(it!=mp.end())
        {
            for(int i=0;i<it->second;i++)
            {
                ans.push_back(it->first);
            }
            it++;
        }
        return ans;
        
    }
};