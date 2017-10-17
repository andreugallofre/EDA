#include <vector>
#include <iostream>

using namespace std;

bool resistant_search2(double x, const vector<double>& v, int e, int d){
	if (e > d) return false;
	int m = (e+d)/2;
	
	double y = v[m];
	if(m != 0 and y < v[m-1]) y = v[m-1];
	else if(m != (int)v.size()-1 and y > v[m+1]) y = v[m+1];

	if (x < y) return resistant_search2(x,v,e,m-1);
	if (x > y) return resistant_search2(x,v,m+1,d);

	return true;
}

bool resistant_search(double x, const vector<double>& v){
	return resistant_search2(x,v,0,v.size()-1);
}
