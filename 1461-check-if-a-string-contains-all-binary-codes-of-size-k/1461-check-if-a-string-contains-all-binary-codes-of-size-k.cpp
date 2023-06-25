class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<int>st;
        
        int n = s.size();
        if(k>n){
            return false;
        }
        int total = pow(2,k)-1;
        int hash = 0;
        int i = 0,j = 0;
        int p2 = 1;
        for(;j<k;j++){
            hash += (s[j]-'0')*p2;
            p2 = p2*2;
        }
        st.insert(hash);
        // cout<<hash<<endl;
        while(j<n){
            hash -= (s[i]-'0');
            hash = hash/2;
            hash += (s[j]-'0')*pow(2,k-1);
            // cout<<hash<<endl;
            st.insert(hash);
            i++;
            j++;
        }
        // for(auto it: st){
        //     cout<<it<<endl;
        // }
        for(int i = 0;i<= total;i++){
            if(st.count(i) == false)return false;
        }
        return true;
    }
};