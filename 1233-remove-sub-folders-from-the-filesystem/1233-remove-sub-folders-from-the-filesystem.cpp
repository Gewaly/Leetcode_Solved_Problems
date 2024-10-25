class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        string lastFolder = folder[0];

        for(int i=1; i<folder.size(); i++){
            string currFolder = folder[i];

            if(currFolder.find(lastFolder + '/') != 0){
                ans.push_back(currFolder);
                lastFolder = currFolder;
            }
        }
        return ans;
    }
};