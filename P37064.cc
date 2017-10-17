#include <iostream>
#include <set>

using namespace std;

int main(){
  set<string> cont;
  set<string>::iterator it, meitat;
  it = cont.begin();
  string s;
  cin>>s;
  if (s != "END") {
    it = cont.insert(it, s);
    cout << s << endl;
    meitat = cont.begin();
    while (cin >> s && s != "END") {
      cont.insert(it, s);
      if (s < *meitat && cont.size()%2 == 0) --meitat;
      else if (s > *meitat && cont.size()%2 != 0) ++meitat;
      cout << *meitat << endl;
    }
  }

}
