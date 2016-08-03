const string ROMAN[] = {"I", "V", "X", "L", "C", "D", "M"};
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        for(int aux = 0, idx = 0;num > 0;idx += 2, num /= 10){
            aux = num % 10;
            if(aux == 0){
                continue;
            }else if(aux < 4){
                for(int i=0;i<aux;++i) ret = ROMAN[idx] + ret;
            }else if(aux == 4){
                ret = ROMAN[idx] + ROMAN[idx+1] + ret;
            }else if(aux < 9){
                for(int i=1;i+4<aux;++i) ret = ROMAN[idx]  + ret;
                ret = ROMAN[idx+1] + ret;
            }else{
                ret = ROMAN[idx] + ROMAN[idx+2] + ret;
            }
        }
        return ret;
    }
};
