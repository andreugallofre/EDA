#include <iostream>
#include <vector> 

using namespace std;

typedef vector<bool> vb; 
typedef vector<vb> matriu;

void printMatrix(matriu &m) {
	for (int i = 0; i < m.size(); ++i){
		for (int j = 0; j < m[0].size(); ++j){
			if(m[i][j]) cout << "R";
			else cout << ".";
		}
		cout << endl;
	}

	cout << endl;
}

void backtracking(matriu &m, vb &f, vb &c, int i) {
	if (i == m.size()) printMatrix(m);
	else{
		for (int j = 0; j < m[0].size(); ++j){
			if (not f[i] and not c[j]){
				c[j] = true;
				f[i] = true;
				m[i][j] = true;

				backtracking(m, f, c, i+1);

				c[j] = false;
				f[i] = false;
				m[i][j] = false;

			}
		}
	}

	return;
}


int main () {
	int n, m;
	cin >> n >> m;

	matriu mat(n,vb(m,false));

	vb f(n, false);
	vb c(m, false);

	backtracking(mat, f, c, 0);

	//printMatrix(mat);

}