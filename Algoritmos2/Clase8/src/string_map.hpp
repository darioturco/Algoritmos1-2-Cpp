template <typename T>
string_map<T>::string_map(){
    raiz = nullptr;
    _size = 0;
    conjclaves = {};
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    destruir(this->raiz);
    this->_size = d.size();
    this->conjclaves = d.cclaves();
    for(pair<string,T> p : d.cclaves()){
        this->insert(p);
    }
}
template<typename T>
vector<pair<string,T>> string_map<T>::cclaves() const{
    return conjclaves;
};
template<class T>
void string_map<T>::destruir(string_map<T>::Nodo* nodo) {
    if(nodo != nullptr){
        for(Nodo* n : nodo->siguientes) {
            destruir(n);
        }
        if(nodo->definicion != nullptr){
            delete nodo->definicion;
        }
        delete nodo;
    }
}

template <typename T>
string_map<T>::~string_map(){
    destruir(raiz);
    _size=0;
    conjclaves = {};
}
template <typename T>
void string_map<T>::insert(const pair<string, T>& p){
    conjclaves.push_back(p);
    if(raiz==nullptr){
        Nodo* s = new Nodo();
        raiz = s;
    }
    int i=0;
    Nodo* pre = raiz;
    while(i<(p.first).size()){
        int str = int((p.first)[i]);
        if(pre->siguientes[str] != nullptr){
            pre=pre->siguientes[str];
            i++;
        }else {
            break;
        }
    }
    while(i<(p.first).size()){
        int t = int((p.first)[i]);
        Nodo* d = new Nodo();
        pre->siguientes[t] = d;
        pre = d;
        i++;
    }
    if(pre->definicion != nullptr){
        delete pre->definicion;
        pre->definicion = nullptr;
    }
    pre->definicion = new T(p.second);
    _size++;
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    if(_size == 0) {
        return 0;
    }else{
        Nodo* punt = raiz;
        int i=0;
        while (i<clave.size()) {
            int str = int(clave[i]);
            if ((punt->siguientes)[str] == nullptr) {
                return 0;
            } else {
                punt = (punt->siguientes)[str];
                i++;
            }
        }
        if((punt->definicion)==nullptr){
            return 0;
        }else{
            return 1;
        }
    }
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* punt = raiz;
    int i=0;
    while(i<clave.size()){
        int str = int(clave[i]);
        punt = (punt->siguientes)[str];
        i++;
    }
    return *(punt->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* punt = raiz;
    int i=0;
    while(i<clave.size()){
        int str = int(clave[i]);
        punt = (punt->siguientes)[str];
        i++;
    }
    return *(punt->definicion);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    _size--;
    vector<pair<string,T>> borr = {};
    for(pair<string,T> s : conjclaves){
        if(s.first != clave){
            borr.push_back(s);
        }
    }
    conjclaves = borr;
    Nodo* ult = raiz;
    Nodo* act = raiz;
    int i = 0;
    int k = 0;
    while(i<clave.size()){
        int str = int(clave[i]);
        int l = 0;
        for(Nodo* g : act->siguientes){
            if(g != nullptr){
                l++;
            }
        }
        if(l>1 || (act->definicion != nullptr)){
            ult = act;
            k=i;
        }
        act=act->siguientes[str];
        i++;
    }
    delete act->definicion;
    act->definicion = nullptr;
    int x = 0;
    for(Nodo* h : act->siguientes){
        if(h != nullptr){
            x++;
        }
    }
    if(x != 0){
        int b = int(clave[k + 1]);
        Nodo* sig = ult->siguientes[b];
        k++;
        ult->siguientes[b] = nullptr;
        ult = sig;
        while (k < clave.size() - 1) {
            int c = int(clave[k + 1]);
            Nodo* si = ult->siguientes[c];
            k++;
            ult->siguientes[c] = nullptr;
            delete ult;
            ult = si;
        }
        delete ult;
    }
    int u = 0;
    for(int i=0;i<(raiz->siguientes).size();i++){
        if((raiz->siguientes)[i] != nullptr){
            u++;
        }
    }
    if(u==0 && raiz->definicion == nullptr){
        raiz=nullptr;
        delete raiz;
    }
}


template <typename T>
int string_map < T >::size() const{
    return _size;
}

template <typename T>
bool string_map < T>::empty() const {
    return (_size == 0);
}
