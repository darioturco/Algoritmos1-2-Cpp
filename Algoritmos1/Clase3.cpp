#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool divide(const vector<int>& vec, int a){ // 2.1
	bool res = true;
	for(int i = 0 ; i<vec.size() ; i++){
		res = res && ((vec[i] % a) == 0);
	}
	return res;
}

int mayor(const vector<int>& vec){ // 2.2
	int max = -1;
	if(vec.size() > 0){	
		max = vec[0];
		for(int i = 1 ; i<vec.size() ; i++){
			if(vec[i] > max) max = vec[i];
		}
	}
	return max;
}

vector<int> reverso(const vector<int>& vec){ // 2.3
	vector<int> res;
	for(int i = vec.size()-1 ; i >= 0 ; i--){
		res.push_back(vec[i]);
	}
	return res;
}

vector<int> rotar(const vector<int>& vec, int k){ // 2.4
	int largo = vec.size();
	vector<int> res(largo);
	if(largo > 0){
		for(int i = 0 ; i<largo ; i++){
			res[(i+k) % largo] = vec[i];
		}
	}
	return res;
}

bool estaOrdenado(const vector<int>& vec){ // 2.5
	bool res = true;
	for(int i = 0 ; i<vec.size()-1 ; i++){
		res = res && vec[i] <= vec[i+1];
	}
	return res;
}

void muestraVector(const vector<int>& vec){ // 2.6
	int i;
	cout << "[";
	for(i = 0 ; i<vec.size()-1 ; i++){
		cout << vec[i] << " , ";
	}
	cout << vec[i] << "]" << endl;
}

int vectorANumero(const vector<int>& vec, int sig){
	int res = 0, mult = 1;
	for(int i = vec.size()-1 ; i >= 0 ; i--){
		res += vec[i]*mult;
		mult *= 10;
	}
	return sig*res;
}
void agregaRes(vector<int>& res, vector<int>& aux, int& signo){
	res.push_back(vectorANumero(aux, signo)); //vuelca el numero a res
	signo = 1;
	aux.clear(); //limpia el acumulador
}
vector<int> leerVector(string nombreArchivo){ // 3.1
	char car;
	int signo = 1;
	vector<int> res, aux;
	ifstream archivo;
	archivo.open(nombreArchivo.c_str(), ios::app);
	archivo >> noskipws; //desabilita el ignorar los espacios en blanco
	while(!archivo.eof()){
		archivo >> car;
		if(car == ' '){
			agregaRes(res, aux, signo);
		}else{
			if(car == '-'){
				signo = -1;
			}else{
				aux.push_back(car - '0');
			}
		}
	}
	archivo.close();
	aux.pop_back();
	agregaRes(res, aux, signo);
	return res;
}

void guardarVector(const vector<int>& vec, string nombreArchivo){ // 3.2
	int i = 0;
	ofstream archivo;
	archivo.open(nombreArchivo.c_str(), ios::app);
	archivo << "[";
	for(i = 0 ; i<vec.size()-1 ; i++){
		archivo << vec[i] << ", ";
	}
	if(vec.size() > 0){
		archivo << vec[i] << "]";
	}else{
		archivo << "]";
	}
	archivo.close();	
}

int cuentaEliminaUltimoElemento(vector<int>& vec){
	vector<int> res;
	int cant = 1;
	int num = vec[vec.size()-1];
	vec.pop_back();
	for(int i = 0 ; i<vec.size() ; i++){
		if(vec[i] == num){
			cant++;
		}else{
			res.push_back(vec[i]);
		}
	}
	vec = res;
	return cant;
}
void cantApariciones(string nombreArchivo){ // 3.3
	vector<int> vec = leerVector(nombreArchivo);
	vector<int> res;
	string escribeArchivo = "archivos/out/" + nombreArchivo;
	int i = 0, num = 0, cant = 0;
	ofstream archivo;
	archivo.open(escribeArchivo.c_str(), ios::app);
	while(vec.size() > 0){
		num = vec[vec.size()-1];
		cant = cuentaEliminaUltimoElemento(vec);
		i++;
		archivo << "Linea " << i << ": " << num << " " << cant << endl;
	}
	archivo.close();
}

int main(){
	return 0;
}


