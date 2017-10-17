#include <vector>
#include <iostream>
//no_elements en interval e->d = d-e+1
using namespace std;

int first_occurrence2(double x, const vector<double>& v, int e, int d){
	if (e > d) return -1;
	int m = (e+d)/2;
	if (x < v[m]) return first_occurrence2(x,v,e,m-1);
	if (x > v[m]) return first_occurrence2(x,v,m+1,d);
	//Trobem un x qualsevol i mirem si mĂŠs enrrere tenim algun altre
	if (m == 0 or v[m-1] != x) return m;
	return first_occurrence2(x,v,e,m-1);
}

int first_occurrence(double x, const vector<double>& v){
	return first_occurrence2(x,v,0,v.size()-1);
}
