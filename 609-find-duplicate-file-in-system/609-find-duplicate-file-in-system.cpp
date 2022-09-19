class Solution {
public:

    void f(string path,unordered_map<string, vector<string>>& m ){
        string path_ = "";
        int i = 0;
        for(; path[i] != ' '; i++){
            path_ += path[i];
        }
        string file = "";
        string content = "";
        
        while(path[i] != '\0'){
            if(path[i]=='('){
                while(path[i] != ')'){
                    i++;
                    content += path[i];
                }
                i++;
                string spath = path_ + "/" + file;
                m[content].push_back(spath);
                file = "";
                content = "";
            }
            else if(path[i] == ' '){
                i++;
                while(path[i] !='('){
                    
                    file += path[i];
                    i++;
                }
            }
            
            
        }
        
        
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        unordered_map<string, vector<string>> m;
        
        for(int i =0 ; i< n; i++){
            f(paths[i], m);
        }
        
        vector<vector<string>> ans;
        
        for(auto i : m){
            if(i.second.size() >= 2){
                vector<string> tmp;
                for(auto j: i.second){
                    tmp.push_back(j);
                }
                ans.push_back(tmp);
            }
            
        }
        
        return ans;
    }
};