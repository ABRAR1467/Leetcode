class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize == 1)
            return true;
        map<int, int> mp;
        for (int i = 0; i < hand.size(); i++)
            mp[hand[i]]++;
        int size = 0, x, y;
        while (mp.size() != 0) {
            for (auto it = mp.begin(); it != mp.end();) {
                //cout<<it->first<<" "<<it->second<<endl;
                if (size == 0) {
                    x = it->first;
                    it->second--;
                    if (it->second == 0)
                        mp.erase(x);
                    size++;
                    it++;
                }
                while (size != 0 && size < groupSize) {
                    if (mp.find(x + 1) != mp.end()) {
                        //if(it!=mp.end())cout<<"LOOP "<<it->first<<" "<<it->second<<endl;
                        it->second--;
                        if (it->second == 0)mp.erase(it->first);
                        x++;
                        size++;
                        it++;
                    } else {
                        return false;
                    }
                }
                if (size == groupSize) {
                    it = mp.begin();
                    size = 0;
                }
                //if(it!=mp.end())cout<<"Outer LOOP "<<it->first<<" "<<it->second<<endl;
            }
        }
        return true;
    }
};