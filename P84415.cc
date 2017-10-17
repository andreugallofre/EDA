#include <string>
#include <map>
#include <iostream>
using namespace std;

int main() {
	map<string, int> dic;
	string instr;
	while (cin >> instr) {
		if (instr == "minimum?") {
			if (dic.empty())
				cout << "indefinite minimum" << endl;
			else {
				map<string, int>::iterator it= dic.begin();
				cout << "minimum:" << " " << it->first << ", " << it->second << " time(s)" << endl;
			}
		}
		else if (instr == "maximum?") {
			if (dic.empty())
				cout << "indefinite maximum" << endl;
			else {
				map<string, int>::iterator it= dic.end();
				--it;
				cout << "maximum:" << " " << it->first << ", " << it->second << " time(s)" << endl;
			}
		}
		else if (instr == "store") {
			string p;
			cin >> p;
			if (dic.find(p) != dic.end()) {
				++dic[p];
			}
			else {
				dic[p] = 1;
			}
		}
		else if (instr == "delete") {
			string p;
			cin >> p;
			if (dic.find(p) != dic.end()) {
				if (dic[p] > 1) {
					--dic[p];
				}
				else
					dic.erase(p);
			}
		}
	}
}
