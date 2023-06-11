class Solution {
public:
    #define int2 long long
    #define pp pair<int,int>
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int2 ans = 0;
        int n = costs.size();
        vector<bool>hired(n,false); 
        priority_queue<pp,vector<pp>,greater<pp>>pq1;
        priority_queue<pp,vector<pp>,greater<pp>>pq2;
        // this {cost[i],i}
        int p1 = 0;
        int p2 = n-1;
        // we will be inserting candidates..
        while(p1<n && p1<candidates){
            pq1.push({costs[p1],p1});
            hired[p1] = true;
            p1++;
        }
        int count = 0;
        while(p2>=0 && count<candidates){
            if(hired[p2] == false){
                pq2.push({costs[p2],p2});
                hired[p2] = true;
                count++;
            }
            else{
                break;
            }
            p2--;
        }
        // for now we will go for hiring..
        for(int i = 0;i<k;i++){
            // one worker in each sesssion...
            if(pq1.size() !=  0 && pq2.size() != 0){
                if(pq1.top().first == pq2.top().first){
                    if(pq1.top().second < pq2.top().second){
                        pp t = pq1.top();
                        pq1.pop();
                        ans += t.first;
                        // p1 should be pushed..
//                         if(p1<n && hired[p1] == false){
//                             pq1.push({cost[p1],p1});
//                             hired[p1] = true;
//                             p1++;
                            
//                         }
//                         else{
//                             p1 = n;
//                         }
                        while(p1<n){
                            if(hired[p1] == false){
                                pq1.push({costs[p1],p1});
                                hired[p1] = true;
                                p1++;
                                break;
                            }
                            p1++;
                        }
                    }
                    else{
                        pp t = pq2.top();
                        ans += t.first;
                        pq2.pop();
                        // p2 should be pushed..
                        while(p2>=0){
                            if(hired[p2] == false){
                                pq2.push({costs[p2],p2});
                                hired[p2] = true;
                                p2--;
                                break;
                            }
                            p2--;
                        }
                    }
                }
                else if(pq1.top().first > pq2.top().first){
                      pp t = pq2.top();
                    ans += t.first;
                      pq2.pop();
                    // p2 should be pushed..
                    while(p2>=0){
                            if(hired[p2] == false){
                                pq2.push({costs[p2],p2});hired[p2] = true;
                                p2--;
                                break;
                            }
                            p2--;
                        }
                    
                }
                else{
                        pp t = pq1.top();
                        pq1.pop();
                    ans += t.first;
                    // p1 should be pushed..
                    while(p1<n){
                            if(hired[p1] == false){
                                pq1.push({costs[p1],p1});
                                hired[p1] = true;
                                p1++;
                                break;
                            }
                            p1++;
                        }
                }
            }
            else if(pq1.size() != 0){
               pp t = pq1.top();
                ans += t.first;
                pq1.pop();
                while(p1<n){
                            if(hired[p1] == false){
                                pq1.push({costs[p1],p1});
                                hired[p1] = true;
                                p1++;
                                break;
                            }
                            p1++;
                        }
            }
            else if(pq2.size() != 0){
                pp t = pq2.top();
                      pq2.pop();
                    // p2 should be pushed..
                ans += t.first;
                    while(p2>=0){
                            if(hired[p2] == false){
                                pq2.push({costs[p2],p2});hired[p2] = true;
                                p2--;
                                break;
                            }
                            p2--;
                        }
            }
            
        }
        return ans;
    }
};