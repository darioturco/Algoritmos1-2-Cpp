#include "Lista.h"

Lista::Lista() : pri_(NULL), ult_(NULL) { }

Lista::Lista(const Lista& l) : Lista() {
    // Inicializa una lista vacía y luego utiliza operator=
    // para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    struct Nodo* aux = pri_;
    // Recorro toda la lista y elimino el elemento en el que
    // estoy parado, hasta encontrar nu puntero NULL

    while (pri_ != NULL) {
      aux = pri_ -> next; // Antes de eliminar lo que apunta pri_ guardo en siguiente nodo en aux
      delete pri_;
      pri_ = aux;
    }
    
    ult_ = NULL;
    // Pongo ult_ en NULL para dejar a lista vacia completamente
}

Lista& Lista::operator=(const Lista& aCopiar) {
    struct Nodo* aux = aCopiar.pri_;
    // Hago que this sea una lista vacia y le voy agregando cada elemento de aCopiar
    pri_ = NULL;
    ult_ = NULL;
    while(aux != NULL){
      this -> agregarAtras(aux -> data);
      aux  = aux -> next;
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    struct Nodo* nuevo = new struct Nodo;
    // Creo un nuevo nodo en el que guardo el dato
    // Ese nodo va a ser el primero de la lista y no va a tener anterior
    nuevo -> next = pri_;
    nuevo -> prev = NULL;
    nuevo -> data = elem;
    if(pri_ != NULL) pri_ -> prev = nuevo;
    pri_ = nuevo;
    if(ult_ == NULL) ult_ = nuevo;
}

void Lista::agregarAtras(const int& elem) {
    struct Nodo* nuevo = new struct Nodo;
    // Creo un nuevo nodo en el que guardo el dato
    // Ese nodo va a ser el ultimo de la lista y no va a tener siguiente
    nuevo -> next = NULL;
    nuevo -> prev = ult_;
    nuevo -> data = elem;
    if(ult_ != NULL) ult_ -> next = nuevo;
    ult_ = nuevo;
    if(pri_ == NULL) pri_ = nuevo;
}

void Lista::eliminar(Nat i) {
    int size = longitud(); // Calculo le largo de la lista
    if(i < size){ // si i >= no hago nada (No lo pongo como Pre-condicion porque el enunciado no lo pide)
      struct Nodo* aux = pri_;

      if(i == 0){

        // Si quiero eliminar el primer elemento
        pri_ = pri_ -> next;
        if(pri_ != NULL) pri_ -> prev = NULL;
        if(size == 1) ult_ = NULL;

      }else{
        if(i == size-1){

          // Si quiero eliminar el ultimo elemento
          aux = ult_;
          ult_ = ult_ -> prev;
          if(ult_ != NULL) ult_ -> next = NULL;
          if(size == 1) pri_ = NULL;

        }else{

          // Si quiero eliminar un elemento del medio
          while (i > 0) {
            aux = aux -> next;
            i--;
          }
          aux -> prev -> next = aux -> next;
          aux -> next -> prev = aux -> prev;

        }
      }
      delete aux;
    }
}

int Lista::longitud() const {
    // Voy a usar la variable res para guardar el resultado
    // y aux para iterar recursivamente la lista
    int res = 0;
    struct Nodo* aux = pri_;

    while (aux != NULL) {
      res++;
      aux = aux -> next;
    }

    return res;
}

// Pre: Nat i < longitud(lista)
const int& Lista::iesimo(Nat i) const {
    assert(i < longitud()); // Me fijo que se cumpla la Pre-condicion

    struct Nodo* aux = pri_;

    //Recorro la lista i veces para encontrar el dato que estaba buscando
    while (i > 0) {
      aux = aux -> next;
      i--;
    }

    return aux -> data; // Retorno el dato de la posicion i
}

// Pre: Nat i < longitud(lista)
int& Lista::iesimo(Nat i) {
    assert(i < longitud()); // Me fijo que se cumpla la Pre-condicion

    struct Nodo* aux = pri_;

    //Recorro la lista i veces para encontrar el dato que estaba buscando
    while (i > 0) {
      aux = aux -> next;
      i--;
    }

    return aux -> data; // Retorno el dato de la posicion i
}

// Imprime la lista de adelante para atras (sirve para ver si todos los nodos apuntan bien a su siguiente nodo)
void Lista::mostrarAdelante(ostream& o) {
    struct Nodo* aux = pri_;
    o << "[";
    if(aux != NULL){
      while (aux -> next != NULL) {
        o << aux -> data << ", ";
        aux = aux -> next;
      }
      o << aux -> data;
    }
    o << "]";
}

// Imprime la lista de atras para adelante (sirve para ver si todos los nodos apuntan bien a su anterior nodo)
void Lista::mostrarAtraz(ostream& o) {
    struct Nodo* aux = ult_;
    o << "[";
    if(aux != NULL){
      while (aux -> prev != NULL) {
        o << aux -> data << ", ";
        aux = aux -> prev;
      }
      o << aux -> data;
    }
    o << "]" << endl; // Salta de linea, la otra funcion no lo hace
}
