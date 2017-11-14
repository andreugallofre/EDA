#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using MC = vector<VC>;

int n,m;
int tresures;
MC M;

int prof(int x, int y) {
	if(x < 0 or x >= n or y < 0 or y >= m) return 0; 
	if(M[x][y] == 'X') return 0;

	if(M[x][y] == 't'){
		cerr << x << " " << y << endl;
		cerr << "tresor" << endl;
		++tresures;
	} 
	M[x][y] = 'X';
	return prof(x+1,y) + prof(x-1,y) + prof(x,y+1) + prof(x,y-1);

}

int main() {
	cin >> n >> m;

	M = MC(n, VC(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) cin >> M[i][j];
	int x, y;
	cin >> x >> y;

	int rest = prof(x-1,y-1);
	cerr << rest;
	cout << tresures << endl;
}
