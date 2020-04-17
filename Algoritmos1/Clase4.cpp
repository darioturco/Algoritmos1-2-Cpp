#include <iostream>
#include <vector>

using namespace std;

bool pico(const vector<int>& vec){
	bool res = false;
	for(int i = 1; i<vec.size(); i++){
		res = res || (vec[i-1] < vec[i] && vec[i+1] < vec[i]);
	}
	return res;
}

int mcd(int n, int m){
	int a = n, b = m;
	while(a % b != 0){
		int aux = a;
		a = a%b;
		b = aux;
	}
	return b;
}

int minimo(const vector<int>& vec, int l, int r){
	int res = r;
	for(int i = r ; i>=l ; i--){
		if(vec[i] < vec[res]) res = i;
	}
	return res;
}

void ordena(vector<int>& vec){
	int aux, min;
	for(int i = 0 ; i<vec.size()-1 ; i++){
		min = minimo(vec, i, vec.size()-1);
		aux = vec[i];
		vec[i] = vec[min];
		vec[min] = aux;
	}
}

int main(){
	
	return 0;
}
