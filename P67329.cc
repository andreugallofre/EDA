#include<iostream>
#include<vector>
	
using namespace std;
	
typedef vector<bool> VB;
	
VB vb;
int n;
	
void backtraking (vector<char> &c, int i, string r){
	if ( i == n) cout << r << endl;
	else{
		string x;
		for (int j = 0; j < c.size(); ++j){
				x = r + c[j];
				backtraking(c, i+1, x);
			}
		}
}
	
int main() {
	vector<char> c = {'A','C','G','T'};
	VB vbn(c.size(), false);
	vb = vbn;
	cin >> n;
	backtraking(c, 0, "");			
}