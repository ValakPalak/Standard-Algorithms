#include <bits/stdc++.h>
using namespace std;

void computeLPSArray (string pattern, int* lps, int M) {
	int len = 0;
	int i = 1;
	lps[0] = 0;

	while(i < M){
		if(pattern[i] == pattern[len]){
			lps[i] = len + 1;
			len++;
			i++;
		}
		else if (len != 0) {
			len = lps[len - 1];
		}
		else {
			lps[i] = 0;
			i++;
		}
	}
}

// o n i o n s 
// 0 0 0 1 2 0

// a a b a a a c
// 0 1 0 1 2 2 0

void KMPSearch (string pattern, string txt) {

	int n = txt.length();
	int m = pattern.length();

	int lps[m] = {0};

	computeLPSArray(pattern, lps, m);
	
// 	for(auto x : lps){
// 	    cout << x << "\n";
// 	}

	int i = 0;
	int j = 0;

	while (i < n) {
		if (txt[i] == pattern[j]){
			i++;
			j++;
		}
		else if (j != 0) {
			j = lps[j-1];
		}
		else {
			i++;
		}

		if(j == m){
			cout << i-j;
			j = lps[j-1];
		}
	}
}

int main() {

	string txt, pattern;

	cin >> pattern >> txt;

	KMPSearch(pattern, txt);

	return 0;
}