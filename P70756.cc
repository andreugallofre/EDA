#include <iostream> 
#include <vector>
#include <string>

using namespace std;

typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<bool> VB;

VB vb;

void printVectors(VVS& vvs){
	for (int i = 0; i < vvs.size(); ++i) {
		cout << "subset " << i+1 << ": {";
		for (int j = 0; j < vvs[i].size(); ++j){
			if (j == vvs[i].size()-1) cout << vvs[i][j];
			else cout << vvs[i][j] << ",";
		}
		cout << "}" << endl;
	}
	cout << endl;
}

void backtracking(int i, VVS& vvs, VS& vs){
	if (i == vs.size()) printVectors(vvs);
	else{
		if (not vb[i]){
			for (int j = 0; j < vvs.size(); ++j){
				vb[i] = true;
				vvs[j].push_back(vs[i]);
				backtracking(i+1, vvs, vs);
				vvs[j].pop_back();
				vb[i] = false;
			}
		}
	}
}

int main () {
	int x; cin >> x; 

	VS vs(x);
	vb = VB(x);

	for (int i = 0; i < x; ++i) {
		string s; cin >> s;
		vs[i] = s;
	}

	cin >> x;

	VS vsn;
	VVS vvs(x, vsn);

	backtracking(0, vvs, vs);
}
