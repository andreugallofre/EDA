#include <iostream>
#include <vector> 

using namespace std;

typedef vector<bool> vb; 
typedef vector<vb> matriu;

// void printMatrix(matriu &m) {
// 	for (int i = 0; i < m.size(); ++i){
// 		for (int j = 0; j < m[0].size(); ++j){
// 			if(m[i][j]) cout << "R";
// 			else cout << ".";
// 		}
// 		cout << endl;
// 	}

// 	cout << endl;
// }


vb diagonal1;
vb diagonal2;

int backtracking(matriu &m, vb &f, vb &c, int i) {
	if (i == m.size()) return 1;
	int r = 0;
	for (int j = 0; j < m.size(); ++j){
		if (not f[i] and not c[j] and not diagonal1[i+j] and not diagonal2[i-j+m.size()]){
			c[j] = true;
			f[i] = true;
			diagonal1[i+j] = true;
			diagonal2[i-j+m.size()] = true;
			m[i][j] = true;

			r += backtracking(m, f, c, i+1);

			c[j] = false;
			f[i] = false;
			diagonal1[i+j] = false;
			diagonal2[i-j+m.size()] = false;
			m[i][j] = false;

		}
	}


	return r;
}


int main () {
	int n;
	cin >> n;

	matriu mat(n,vb(n,false));

	vb f(n, false);
	vb c(n, false);

	diagonal2 = vb(n*2-1, false);
	diagonal1 = vb(n*2-1, false);

	cout << backtracking(mat, f, c, 0) << endl;

	//printMatrix(mat);

}