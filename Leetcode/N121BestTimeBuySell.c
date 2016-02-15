int maxProfit(int* prices, int pricesSize) {
    
    if(NULL == prices || pricesSize <= 1){
        return 0;
    }
    
    int max[pricesSize-1];
    int i=0;
    max[pricesSize-2]=prices[pricesSize-1];
    for(i=pricesSize-3;i>=0;i--){
        max[i] = prices[i+1] > max[i+1] ? prices[i+1] : max[i+1];
    }
    
    int maxProfit = 0;
    
    for(i=0;i<pricesSize-1;i++){
        if(max[i] - prices[i] > maxProfit){
            maxProfit = max[i] - prices[i];
        }
    }
    
    return maxProfit;
    
}