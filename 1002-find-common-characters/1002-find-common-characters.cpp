class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>freq1(27,0);
        vector<int>freq2(27,0);
        vector<string>ans;
        for(int i=0;i<words[0].size();i++)freq1[words[0][i]-'a']++;
        for(int i=1;i<words.size();i++)
        {
            vector<int>freq2(27,0);
            for(int j=0;j<words[i].size();j++)
            {
                freq2[words[i][j]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                freq1[i] = min(freq1[i],freq2[i]);
            }
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<freq1[i];j++)
            {
                char ch = 'a'+i;
                ans.push_back(string(1,ch));
            }
        }
        return ans;
    }
};