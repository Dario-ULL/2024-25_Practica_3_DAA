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

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "DyV.h"

class MergeSort: public DyV {
 protected:
  bool Pequeno(std::vector<int> vector);
  std::vector<int> resolverPequeno(std::vector<int> vector);
  std::vector<std::vector<int>> Divide(std::vector<int> vector, int tamano);
  std::vector<int> Combine(std::vector<int> vector1, std::vector<int> vector2);
  std::string numSubProblemas();
  std::string factorReduccion();
  std::string tiempoCombinacion();
};

#endif