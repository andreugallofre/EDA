/* Si el graf té un cicle l'algorisme para pero el programa no explota
Un graf dirigit que té un cicle, no té ordenació topologica, ens serveis
per veure si un graf té cicles o no*/

#include <queue>
#include <iostream>
#include <vector>

using namespace std;

using VE = vector<int>;
using ME = vector<VE>;

int main() {
    int n,m;
    while (cin >> n >> m) {
        
        ME G(n);
        VE grau(n,0);

        for (int r = 0; r < m; ++r) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            ++grau[y];
        }

        priority_queue<int> pq;

        for(int x = 0; x < n; ++x)
            if (grau[x] == 0) pq.push(-x);
       
        bool primer = true;

        while(not pq.empty()) {
            int x = pq.top(); pq.pop();

            if(primer){ primer = false;}
            else cout << " ";
            cout << -x; 

            for (int y : G[-x])
                if (--grau[y] == 0) pq.push(-y);
        }
        cout << endl;
    }
}
