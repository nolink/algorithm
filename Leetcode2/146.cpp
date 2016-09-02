
typedef list<int>::iterator lit;
typedef unordered_map<int, pair<lit, int>>::iterator mit;

class LRUCache{
private:
    list<int> visits;
    unordered_map<int, pair<lit, int>> data;
    int max_capacity;
    
    void visit(mit it){
        int key = it->first;
        visits.erase(it->second.first);
        visits.push_front(key);
        it->second.first = visits.begin();
    }
    
public:
    LRUCache(int capacity) {
        max_capacity = capacity;
    }
    
    int get(int key) {
        auto it = data.find(key);
        if(it != data.end()){
            visit(it);
            return it->second.second;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it = data.find(key);
        if(it != data.end()){
            visit(it);
        }else{
            if(data.size() == max_capacity){
                data.erase(visits.back());
                visits.pop_back();
            }
            visits.push_front(key);
        }
        data[key] = {visits.begin(), value};
    }
};
