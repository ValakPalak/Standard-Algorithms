//Minimum Characters required to make a String Palindromic

vector<int> lpsv(string s){
    int i = 0;
    int j = 1;
    int n = s.length();
    vector<int> lps(n, 0);
    
    while(j < n){
        if(s[i] == s[j]){
            lps[j] = i + 1;;
            i++;
            j++;
            
        }
        else{
            if(i != 0){
                i = lps[i-1];
            }
            else{
                lps[j] = 0;
                j++;
            }
        }
    }
    return lps;
}

int Solution::solve(string A) {
    string P = A;
    reverse(P.begin(), P.end());
    string p = A + '$' + P;
    int m = p.length();
    int q = A.length();
    vector<int> a;
    a = lpsv(p);
    
    return (- a[m-1] + q);
}

