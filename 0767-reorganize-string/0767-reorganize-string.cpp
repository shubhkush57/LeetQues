class Solution {
public:
    #define pp pair<int,char>
    string reorganizeString(string s) {
        priority_queue<pp>pq;
        // maximum priority_queue;
        vector<int>count(26,0);
        
        int n = s.size();
        for(int i = 0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        for(int i =0;i<26;i++){
            if(count[i]>0)
            pq.push({count[i],'a'+i});
        }
        string ans = "";
        while(pq.size()>=2){
            pp t1 = pq.top();pq.pop();
            pp t2 = pq.top();pq.pop();
            ans.push_back(t1.second);
            ans.push_back(t2.second);
            if(t1.first-1 >0){
                pq.push({t1.first-1,t1.second});
            }
            if(t2.first-1>0){
                pq.push({t2.first-1,t2.second});
            }
            
        }
        if(pq.size() == 1 && pq.top().first == 1){
            pp t = pq.top();pq.pop();
            ans.push_back(t.second);
        }
        if(pq.empty() == false){
            return "";
        }
        return ans;
    }
};