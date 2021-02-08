#include <bits/stdc++.h>
using namespace std;

int nolength(long long no){
	int len=1;
	while(no/10 == 0){
		len++;
		no /= 10;
	}
	return len;
}

long long multiply(long long x, long long y){
	int xlen = nolength(x);
	int ylen = nolength(y);

	int n = max(xlen, ylen);

	n = (n/2) + n%2;

	long long m = pow(10, n);

	long long x1 = x/m;
	long long x2 = x - x1*m;
	long long y1 = y/m;
	long long y2 = y - y1*m;

	long long a = multiply(x1, y1);
	long long b = multiply(x2, y2);
	long long c = multiply(x1 + x2, y1 + y2);

	return ((a * (long long)(pow(10, 2*n))) + ((c - a - b) * m) + b);
}

int main(){

	long long x, y;
	cin >> x >> y;

	cout << multiply(x, y);
	
	return 0;
}