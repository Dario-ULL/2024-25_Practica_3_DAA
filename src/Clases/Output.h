/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    11/03/2024
 * @brief   Implementacion de algoritmos de Divide y Venceras,
 *          utilizando el patron Template.
 *          
*/

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

#include "DyV.h"

class Output {
 private:
  std::string fichero_;
 public:
  Output();
  Output(std::string fichero);
  ~Output();
  void MostrarVector(const std::pair<std::vector<int>,int>& v);
  void MostrarNivelArbol(const std::pair<std::vector<int>,int>& v);
  void medirTiempoEjecucion(DyV* algoritmo, const std::pair<std::vector<int>,int>& A, const int n);
};

#endif