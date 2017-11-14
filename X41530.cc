#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using ME = vector<VE>;
using VB = vector<bool>;

int n,m;
int tresures;
ME G;
VB visit;

void prof(int x, int& v, int& a) {
	if(visit[x]) return;
	visit[x] = true;
	++v;
	for (int i = 0; i < (int)G[x].size(); ++i) {
		prof(G[x][i], v, a);
		++a;
	}
}

int solu() {
	int res = 0;
	visit  = VB(n, false);
	for (int x = 0; x < n; ++x)
			if (not visit[x]) {
				++res;
				int v = 0, a = 0;
				prof(x, v, a);
				if (a != 2*(v-1)) return -1;
			}
		return res;
}

int main() {
	while(cin >> n >> m){
		G = ME(n);
		for (int r = 0; r < m; ++r) {
			int x,y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}

		visit  = VB(n,false);
		for (int x = 0; x < n; ++x)
			if (not visit[x]) {
				int v, a;
				prof(x, v, a);
			}
	int res = solu();
	if (res == -1) cout << "no" << endl;
	else cout << res << endl;
	}

}
