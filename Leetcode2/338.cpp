class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(1, 0);
        for(int i = 1, aux = 1;i<=num;i++){
            aux = i;
            aux = (aux & 0x55555555) + ((aux >> 1) & 0x55555555);
            aux = (aux & 0x33333333) + ((aux >> 2) & 0x33333333);
            aux = (aux & 0x0f0f0f0f) + ((aux >> 4) & 0x0f0f0f0f);
            aux = (aux & 0x00ff00ff) + ((aux >> 8) & 0x00ff00ff);
            aux = (aux & 0x0000ffff) + ((aux >> 16) & 0x0000ffff);
            ret.push_back(aux);
        }
        return ret;
    }
};
