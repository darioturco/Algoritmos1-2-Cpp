#include <iostream>
#include <vector>
#include <string>

using namespace std;

void imprimeVector(const vector<string>& vec){
	for(int i = 0 ; i<vec.size() ; i++){
		cout << vec[i] << endl;
	}
}

vector<string> split(const string& s, char delim){
	vector<string> res;
	string aux;
	int i = 0;
	for(i = 0 ; i<s.size() ; i++){
		if(s[i] == delim){
			res.push_back(aux);
			aux.clear();
		}else{
			aux.push_back(s[i]);
		}
	}
	if(s[i-1] != delim) res.push_back(aux);
	return res;
}

string darVueltaPalabra(string s){
	vector<string> separado = split(s, ' ');
	string res; 
	for(int i = separado.size()-1 ; i>=0 ; i--){
		for(int j = 0 ; j<separado[i].size() ; j++){
			res.push_back(separado[i][j]);
		}
		res.push_back(' ');
	}
	return res;
}

bool subsecuencia(string s, string t){
	int i = 0;
	int j = 0;
	while(i < s.size() && j < t.size()){
		if(s[i] == t[j]) j++;
		i++;
	}
	return j == t.size();
}

bool sonAnagramas(string s, string t){
	if (s.size() != t.size()) return false;
	int ssum = 0;
	int tsum = 0;
	for(int i = 0 ; i<s.size() ; i++){
		ssum += s[i];
		tsum += t[i];
	}
	return ssum == tsum;
}

vector< vector<string> > agruparAnagramas(const vector<string>& vec){
	vector< vector<string> > res;
	res.push_back({});
	for(int i = 0 ; i<vec.size() ; i++){
		for(int j = 0 ; res.size()-1 ; j++){
			if(sonAnagramas(vec[i], res[j][0])){
				res[j].push_back(vec[i]);
				res.push_back({});
			}
		}
	}
	return res;
}

bool esPalindromo(const string& s){
	bool res = true;
	for(int i = 0 ; i<s.size()/2 ; i++){
		res = res && s[i] == s[s.size()-i-1];
	}
	return res;
}

bool tieneRepetidos(const string& s){
	bool res = false;
	for(int i = 0 ; i<s.size() ; i++){
		for(int j = 0 ; j<i ; j++){
			res = res || s[i] == s[j]; 
		}
	}
	return res;
}

int main(){
	
	return 0;
}
