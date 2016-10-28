class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n = path.length(), i = 0;
        while(i < n){
            string aux = "/";
            while(i < n && path[i] == '/') i++;
            while(i < n && path[i] != '/') aux += path[i++];
            if(aux == "/.") aux = "/";
            if(aux == "/.."){
                if(!s.empty()) s.pop();
            }else if(aux != "/"){
                s.push(aux);
            }
        } 
        string ret;
        while(!s.empty()){
            ret = s.top() + ret;
            s.pop();
        }
        return ret.empty() ? "/" : ret;
    }
};
