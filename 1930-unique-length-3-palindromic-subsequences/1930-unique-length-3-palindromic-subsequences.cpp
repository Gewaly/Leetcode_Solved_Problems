class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> start(26, -1);
        vector<int> end(26, -1);
        vector<int> vis(26, 0);
        for(int i=0;i<n;i++)
        {
            if(!vis[s[i]-'a'])
            {
                vis[s[i]-'a'] = 1;
                start[s[i]-'a'] = i;
            }
        }
        for(int i=0;i<26;i++)
        {
            vis[i] = 0;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(!vis[s[i]-'a'])
            {
                vis[s[i]-'a'] = 1;
                end[s[i]-'a'] = i;
            }
        }
        // for(auto i:start)
        // {
        //     cout<<i<<' ';
        // }
        // cout<<endl;
        // for(auto i:end)
        // {
        //     cout<<i<<' ';
        // }
        // cout<<endl;
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            if(start[i]!=-1 && end[i]!=-1 && start[i]<end[i])
            {
                unordered_set<char> st;
                for(int k = start[i]+1;k < end[i]; k++)
                {
                    st.insert(s[k]);
                }
                ans+=st.size();
            }
        }
        return ans;
    }
};