class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<vector<int>>events;
        for(int i=0;i<n;i++)
        {
            events.push_back({times[i][0],times[i][1],i});
        }
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>occupied;
        priority_queue<int,vector<int>,greater<int>>free;
        for(int i=0;i<n;i++)free.push(i);
        for(auto event : events)
        {
            int arrival = event[0];
            int leave = event[1];
            int index = event[2];

            while(!occupied.empty()&&occupied.top().first<=arrival)
            {
                free.push(occupied.top().second);
                occupied.pop();
            }

            int chair = free.top();
            free.pop();

            if(index==targetFriend)return chair;
            occupied.push({leave,chair});
        }
        return -1;
    }
};