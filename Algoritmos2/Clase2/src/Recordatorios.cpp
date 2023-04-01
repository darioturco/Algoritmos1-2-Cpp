#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();
    bool operator==(Fecha o);

  private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia): mes_(mes), dia_(dia){};

int Fecha::mes(){
  return mes_;
}

int Fecha::dia(){
  return dia_;
}

ostream& operator<<(ostream& os, Fecha fec){
  os << fec.dia() << "/" << fec.mes();
  return os;
}

bool Fecha::operator==(Fecha o) {
    bool igual_dia = (this->dia() == o.dia() && this->mes() == o.mes());
    return igual_dia;
}

void Fecha::incrementar_dia(){
  dia_++;
  if(dia_ > dias_en_mes(mes_)){
    dia_ = 1;
    mes_++;
    if(mes_ >= 12) mes_ = 1;
  }
}

// Ejercicio 11, 12

// Clase Horario
class Horario{
  public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario hor);
    bool operator<(Horario h);

  private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {};

uint Horario::hora(){
  return hora_;
}

uint Horario::min(){
  return min_;
}

ostream& operator<<(ostream& os, Horario hor){
  os << hor.hora() << ":" << hor.min();
  return os;
}

bool Horario::operator==(Horario hor) {
  bool igual_horario = (this->hora() == hor.hora() && this->min() == hor.min());
  return igual_horario;
}

bool Horario::operator<(Horario h) {
  bool hEsMayor;
  if(this->hora() < h.hora()){
    hEsMayor = true;
  }else{
    if(this->hora() == h.hora() && this->min() < h.min()){
      hEsMayor = true;
    }else{
      hEsMayor = false;
    }
  }
  return hEsMayor;
}

// Ejercicio 13

// Clase Recordatorio
class Recordatorio{
  public:
    Recordatorio(Fecha fec, Horario hor, string mes);
    Fecha getFecha();
    Horario getHorario();
    string getString();
    bool operator<(Recordatorio rec);

  private:
    Fecha fec_;
    Horario hor_;
    string mes_;
};

Recordatorio::Recordatorio(Fecha fec, Horario hor, string mes): fec_(fec), hor_(hor), mes_(mes){};

Fecha  Recordatorio::getFecha(){
  return fec_;
}

Horario Recordatorio::getHorario(){
  return hor_;
}

string Recordatorio::getString(){
  return mes_;
}

ostream& operator<<(ostream& os, Recordatorio rec){
  os << rec.getString() << " @ " << rec.getFecha() << " " << rec.getHorario();
  return os;
}

bool Recordatorio::operator<(Recordatorio rec) {
  bool recEsMayor = this->getHorario() < rec.getHorario();
  return recEsMayor;
}

// Ejercicio 14

// Clase Agenda

class Agenda {
  public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

  private:
    list<Recordatorio> listaRecordatorios_; //Siempre esta ordenada
    Fecha diaActual_;
};

Agenda::Agenda(Fecha fecha_inicial): listaRecordatorios_(list<Recordatorio>()), diaActual_(fecha_inicial) {};

void Agenda::agregar_recordatorio(Recordatorio rec){//Siempre agrega en orden
  list<Recordatorio> listaux;
  listaux.push_back(rec); //Crea una lista de un solo elemento
  listaRecordatorios_.merge(listaux); //Junta las dos listas ordenadas en listaRecordatorios_
}

void Agenda::incrementar_dia(){
  diaActual_.incrementar_dia();//Funcion del ejercicio 10
}

list<Recordatorio> Agenda::recordatorios_de_hoy(){
  return listaRecordatorios_;
}

Fecha Agenda::hoy(){
  return diaActual_;
}

ostream& operator<<(ostream& os, Agenda age) {
  os << age.hoy() << endl;
  os << "=====" << endl;
  for(Recordatorio rec : age.recordatorios_de_hoy()){//imprime los elementos de la lista que tengan la fecha de hoy
    if(age.hoy() == rec.getFecha()) os << rec << endl;
  }
  return os;
}
