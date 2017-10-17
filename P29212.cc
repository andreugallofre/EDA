#include <vector>
#include <iostream>

using namespace std;

int potencia(int x, int n, int m){
	if (n == 0) return 1;
	int y = potencia(x,n/2,m);
	y = (y*y)%m;
	if (n%2 == 1) y = (y*x)%m;
	return y;
}

int main(){

	int n,k,m;
	while (cin >> n >> k >> m) {
		cout << potencia(n,k,m) << endl;
	}
}
