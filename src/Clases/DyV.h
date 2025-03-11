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
  virtual bool Pequeno(std::pair<std::vector<int>,int>  vector) = 0;
  virtual std::pair<std::vector<int>,int> resolverPequeno(std::pair<std::vector<int>,int>  vector) = 0;
  virtual std::vector<std::pair<std::vector<int>,int> > Divide(std::pair<std::vector<int>,int>  vector, int tamano) = 0;
  virtual std::pair<std::vector<int>,int>  Combine(std::pair<std::vector<int>,int>  vector1, std::pair<std::vector<int>,int>  vector2) = 0;
  virtual std::string numSubProblemas() = 0;
  virtual std::string factorReduccion() = 0;
  virtual std::string tiempoCombinacion() = 0;
 public:
  DyV() {}
  ~DyV() {}
  std::pair<std::vector<int>,int>  Resolver(std::pair<std::vector<int>,int> vector, int tamano);
  std::string recurrencia();
};

#endif