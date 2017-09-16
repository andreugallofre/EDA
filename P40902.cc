#include<map>
#include<string>
#include<iostream> 

using namespace std;

int main(){

map<string,int> players;
string s, s2;
int i;

while(cin >> s){
	cin >> s2;

	if (s2 == "enters"){
		auto esta = players.find(s);
		if(esta == players.end()){
			players[s] = 0;
		}
		else cout << s << " is already in the casino" << endl;
	}
	if (s2 == "leaves"){
		auto esta = players.find(s);
		if(esta != players.end()){
			cout << esta->first << " has won " << esta->second << endl;
			players.erase(esta);
		}
		else cout << s << " is not in the casino" << endl;
	}
	if (s2 == "wins"){
		cin >> i;
		auto esta = players.find(s);
		if(esta != players.end()){
			esta->second += i;
		}
		else cout << s << " is not in the casino" << endl;
	}
}

cout << "----------" << endl;

for(auto it = players.begin(); it != players.end(); it++){
	cout << it->first << " is winning " << it->second << endl; 
}

}
