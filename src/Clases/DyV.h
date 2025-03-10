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

#ifndef DYV_H_
#define DYV_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

class DyV {
 protected:
  virtual bool Pequeno(std::vector<int> vector) = 0;
  virtual std::vector<int> resolverPequeno(std::vector<int> vector) = 0;
  virtual std::vector<std::vector<int>> Divide(std::vector<int> vector, int tamano) = 0;
  virtual std::vector<int> Combine(std::vector<int> vector1, std::vector<int> vector2) = 0;
  virtual std::string numSubProblemas() = 0;
  virtual std::string factorReduccion() = 0;
  virtual std::string tiempoCombinacion() = 0;
 public:
  DyV() {}
  ~DyV() {}
  std::vector<int> Resolver(std::vector<int> vector, int tamano);
  std::string recurrencia();
};

#endif