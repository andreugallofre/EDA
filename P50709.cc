#include<queue>
#include<iostream> 

using namespace std;

int main(){

	int x,y;
	char c;

	priority_queue<int> pq;

	while (cin >> c){
		switch(c){
			case 'S':
				cin >> x;
				pq.push(x);
			break;
			case 'A':
				if(!pq.empty()) cout << pq.top() << endl;
				else cout << "error!" << endl;
			break;
			case 'R':
				if(!pq.empty()) pq.pop();
				else cout << "error!" << endl;
			break;
			case 'I':
				cin >> x;
				if(!pq.empty()){
					y = pq.top() + x;
					pq.pop();
					pq.push(y);
				} 
				else cout << "error!" << endl;
			break;
			case 'D':
				cin >> x;
				if(!pq.empty()){
					y = pq.top() - x;
					pq.pop();
					pq.push(y);
				} 
				else cout << "error!" << endl;
			break;
		}

	}
}
