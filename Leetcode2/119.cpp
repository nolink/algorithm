class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret, aux;
        if(rowIndex >= 0){
            ret.resize(rowIndex+1, 1);
            aux.resize(rowIndex+1, 1);
            for(int i=2;i<=rowIndex;i++){
                for(int j=1;j<i;j++){
                    ret[j] = aux[j-1] + aux[j];
                }
                aux = ret;
            }
        }
        return ret;
    }
};
