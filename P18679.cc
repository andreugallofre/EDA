#include <iostream>
#include <vector>

using namespace std; 

void backtracking (vector<int> &v, int i, int r, int m){
	if (i == v.size()){
		if (r >= 0 and r <= m/2 or r < 0 and r >= -m/2) 
			cout << r << endl;
	} 
	else {
		if (r >= 0 and r <= m/2 or r < 0 and r >= -m/2){
			int x;
			x = r + v[i];
			backtracking(v, i+1, x, m);
			x = r - v[i];
			backtracking(v, i+1, x, m);
		}
	}
}

int main () {
	int n, nn;
	cin >> n >> nn; 

	vector<int> vec(nn);

	for (int i = 0; i < nn; ++i){
		int x; cin >> x;
		vec[i] = x;
	}

	backtracking(vec, 0, 0, n);

}
