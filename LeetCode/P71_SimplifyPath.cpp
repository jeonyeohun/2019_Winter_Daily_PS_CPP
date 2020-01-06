class Solution {
public:
    string simplifyPath(string path) {
        string result = "/";
        vector<string> directories;
        
        for (int i = 0 ; i < path.size() ; i++){
            if (isalpha(path[i])){
                string dir;
                while(path[i] != '/' && i < path.size()) dir.push_back(path[i++]);
                dir.push_back('/');
                directories.push_back(dir);
            }
            else if (path[i] == '.'){
                string dir;
                while (path[i] != '/' && i < path.size()) dir.push_back(path[i++]);
                if (dir.size() == 2 && !directories.empty()) {
                    directories.pop_back();
                }
                else if (dir.size() > 2){
                    dir.push_back('/');
                    directories.push_back(dir);
                }
            }
        }
        for (string str : directories){
            result += str;
        }
        
        if (result.back() == '/' && result.size() > 1) result.pop_back();
        
        return result;
    }
};