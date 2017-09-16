#include<unordered_map>
#include<iostream>

using namespace std;


int calcul_next(int x, int y,int n){
        if(n%2 == 0) return n/2 +x;
        else return n*3+y;
}

int calcul_cicle(int x, int y, int n){

        int res = 1;
        bool cicle = false;
        unordered_map<int,int> nums;

        nums[n] = res; //Afegim el primer numero

        while(!cicle && (n <= 100000000)){
                n = calcul_next(x,y,n);
                ++res;
                auto it = nums.find(n);
                if(it == nums.end()) nums[n] = res;
                else return res - it->second;
        }
        return n;
}

int main(){
        int x,y,n;
        while (cin >> x >> y >> n) cout << calcul_cicle(x,y,n) << endl;
}
