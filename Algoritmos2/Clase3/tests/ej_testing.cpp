#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
  EXPECT_EQ(15 + 7, 22);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
  EXPECT_EQ(pow(10, 2), 100);
}

// Ejercicios 6
TEST(Aritmetica, potencia_general) {
  for(int i = -5 ; i<=5 ; i++){
    EXPECT_EQ(pow(i, 2), i*i);
  }
}

// Ejercicios 7
TEST(Diccionario, definir) {
  map<int, int> dic;
  int k = 10;
  dic[k] = 42;
  EXPECT_EQ(dic[k], 42);
}

// Ejercicios 8
TEST(Diccionario, definir) {
  map<int, int> dic;
  int k = 10;
  EXPECT_EQ(dic.count(k), 0); // Testeo que k no este defnido
  dic[k] = 42;
  EXPECT_EQ(dic.count(k), 1); // Testeo que k no este defnido
}

// Ejercicios 9
