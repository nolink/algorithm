int rangeBitwiseAnd(int m, int n) {
  
  int changed = m^n;
  int count = 0;
  for(;changed > 0;changed = changed >> 1, count++);
  
  return m >> count << count;
  
}