#include <vector>
#include <map>
#include <set>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    map<int, bool> listaDeRepetidos;// Supongo que todos los valores del diccionario se inicializan en false
    for(int i = 0 ; i<s.size(); i++){
        if(!listaDeRepetidos[s[i]]){
            listaDeRepetidos[s[i]] = true;
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res;
    set<int> conjuntoDeRepetidos;
    for(int i = 0 ; i<s.size(); i++){
        if(conjuntoDeRepetidos.count(s[i]) == 0){//Si no es en el conjunto
            conjuntoDeRepetidos.insert(s[i]);
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> elementosDeA;
    set<int> elementosDeB;
    for(int i = 0 ; i<a.size(); i++){
        elementosDeA.insert(a[i]);
    }
    for(int i = 0 ; i<b.size(); i++){
        elementosDeB.insert(b[i]);
    }
    return elementosDeA == elementosDeB;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return mismos_elementos(a, b);//Como use set en el anterior ejercicio lo dejo igual
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;
    for(int i = 0 ; i<s.size(); i++){
        res[s[i]] = 0;//inicializa cada numero en 0 apariciones
    }
    for(int i = 0 ; i<s.size(); i++){
        res[s[i]]++;
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map<int, int> cantidadDeLista = contar_apariciones(s);
    vector<int> res;
    for(int i = 0 ; i<s.size(); i++){//Lo agrega solo si esta una sola vez
        if(cantidadDeLista[s[i]] == 1) res.push_back(s[i]);
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int elem : a){
        if(b.count(elem) > 0) res.insert(elem);
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for(int i = 0 ; i<s.size() ; i++){
        res[s[i] % 10].insert(s[i]);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    for(int i = 0 ; i<str.size() ; i++){
        bool encontro = false;
        int j = 0;
        for(j = 0 ; j<tr.size() && encontro == false ; j++){
            if(tr[j].first == str[i]) encontro = true;    
        }
        if(encontro) str[i] = tr[j-1].second;
        
    }
    return str;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    for(int i = 0 ; i<s.size() ; i++){
        for(int j = 0 ; j<s.size() ; j++){
            if(i != j){
                set<LU> interseccion;
                for(LU elem : s[i].libretas()){
                    if(s[j].libretas().count(elem) > 0) interseccion.insert(elem);
                }
                res = res || (interseccion != s[i].libretas() && !interseccion.empty());
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    Fecha ultimo;
    for(int i = 0 ; i<s.size() ; i++){
        if(s[i].adjunto() && res.count(s[i].libretas()) == 0){
            ultimo = i;
            for(int j = 0 ; j<s.size() ; j++){
                if(s[j].adjunto() && s[j].libretas() == s[ultimo].libretas() && s[ultimo].fecha() < s[j].fecha()) ultimo = j;
            }
            res[s[ultimo].libretas()] = s[ultimo];
        }
    }
    return res;
}

