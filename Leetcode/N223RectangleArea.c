int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    
    int height_1 = D - B;
    int width_1 = C - A;
    int height_2 = H - F;
    int width_2 = G - E;
    
    if(H <= B || F >= D || E >= C || G <= A){
        return height_1*width_1 + height_2*width_2;
    }
    
    if(A <= E && B <= F && G <= C && H <= D){
        return height_1*width_1;
    }
    
    if(A > E && B > F && G > C && H > D){
        return height_2*width_2;
    }
    
    
    int height = 0;
    int width = 0;
    if(B <= F && H <= D){
        height = H-F;
    }else if(B > F && H > D){
        height = D - B;
    }else if(B > F && H > B && H <= D){
        height = H - B;
    }else if(B <= F && F < D && H > D){
        height = D - F;
    }
    
    if(A <= E && G <= C){
        width = G - E;
    }else if(A > E && G > C){
        width = C - A;
    }else if(A > E && G > A && G <= C){
        width = G - A;
    }else if(A <= E && E < C && G > C){
        width = C - E;
    }
    
    return  height_1*width_1 + height_2*width_2 - height*width;
    
}