#include <stack>

template <class T>
Conjunto<T>::Conjunto() : _raiz(NULL) { }

template <class T>
Conjunto<T>::~Conjunto() { 
    if (_raiz != NULL) destruir(_raiz);
}

template <class T>
void Conjunto<T>::destruir(Conjunto<T>::Nodo* n){
    if(n != NULL){
        destruir(n -> der);
        destruir(n -> izq);
        delete n;
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* nodo = _raiz;
    while(nodo != NULL){
        if(nodo -> valor == clave) return true;
        if(nodo -> valor < clave){
            nodo = nodo -> der;
        }else{
            nodo = nodo -> izq;
        }
    }
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(_raiz == NULL){
        _raiz = new Nodo(clave);
    }else{
        Nodo* nodo = _raiz;
        while(nodo != NULL){
            if(nodo -> valor != clave){
                if(nodo -> valor < clave){
                    if(nodo -> der ==  NULL){
                        nodo -> der = new Nodo(clave);
                        nodo = NULL;
                    }else{
                        nodo = nodo -> der;
                    }
                }else{
                    if(nodo -> izq ==  NULL){
                        nodo -> izq = new Nodo(clave);
                        nodo = NULL;
                    }else{
                        nodo = nodo -> izq;
                    }
                }
            }else{
                nodo = NULL;
            }
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    assert(this->pertenece(clave));
    Nodo* nodo  = _raiz;
    Nodo* padre = NULL;
    while(nodo -> valor != clave){
        padre = nodo;
        if(nodo -> valor < clave){
            nodo = nodo -> der;
        }else{
            nodo = nodo -> izq;
        }
    }
    Nodo** hijo;
    if(padre == NULL){
        hijo = &_raiz;
    }else{
        if(padre -> der == nodo){
            hijo = &padre -> der;
        }else{
            hijo = &padre -> izq;
        }
    }
    if(nodo -> der == NULL && nodo -> izq == NULL){
        *hijo = NULL;
        delete nodo;
    }else{
        if(nodo -> der == NULL){
            *hijo = nodo -> izq;
            delete nodo;
        }else{
            if(nodo -> izq == NULL){
                *hijo = nodo -> der;
                delete nodo;
            }else{
                T sig = this -> siguiente(clave);
                this -> remover(sig);
                nodo -> valor = sig;
            }
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(this -> pertenece(clave));
    assert(this -> maximo() != clave);
    Nodo* nodo = _raiz;
    stack<Nodo*> rama;
    while(nodo -> valor != clave){
        rama.push(nodo);
        if(nodo -> valor < clave){
            nodo = nodo -> der;
        }else{
            nodo = nodo -> izq;
        }
    }
    if(nodo -> der == NULL){
        while(!rama.empty()){
            if((nodo -> valor == clave && rama.top() -> valor > clave) || (nodo -> valor != clave && rama.top() -> valor > clave && rama.top() -> valor < nodo -> valor)) nodo = rama.top();
            rama.pop();
        }
    }else{
        return minimoNodo(nodo -> der);
    }
    return nodo -> valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    assert(this -> cardinal() > 0);
    return minimoNodo(_raiz);
}

template <class T>
const T& Conjunto<T>::minimoNodo(Conjunto<T>::Nodo* n) const{
    if(n -> izq == NULL && n -> der == NULL) return n -> valor;
    if(n -> izq == NULL){
        if(minimoNodo(n -> der) < n -> valor){
            return minimoNodo(n -> der);
        }else{
            return n -> valor;
        }
    }
    return minimoNodo(n -> izq);
}

template <class T>
const T& Conjunto<T>::maximo() const {
    assert(this -> cardinal() > 0);
    return (maximoNodo(_raiz));
}

template <class T>
const T& Conjunto<T>::maximoNodo(Conjunto<T>::Nodo* n) const{
    if(n -> izq == NULL && n -> der == NULL) return n -> valor;
    if(n -> der == NULL){
        if(maximoNodo(n -> izq) < n -> valor){
            return maximoNodo(n -> izq);
        }else{
            return n -> valor;
        }
    }
    return maximoNodo(n -> der);
}

template <class T>
unsigned int Conjunto<T>::cardinalAux(Conjunto<T>::Nodo* n) const {
    if (n == NULL){
        return 0;
    }else{
        return cardinalAux(n->izq) + cardinalAux(n->der) + 1;
    }
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return cardinalAux(_raiz);
}

template <class T>
void Conjunto<T>::mostrar(std::ostream& o) const {
    o << '{';
    if(_raiz != NULL) inorder(o, _raiz); //preorder(o, _raiz); posorder(o, _raiz);
    if(this->cardinal() != 0) o << "\b\b";
    o << '}' << endl;
}



