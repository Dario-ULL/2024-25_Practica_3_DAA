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

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "DyV.h"

class QuickSort: public DyV {
 protected:
 bool Pequeno(std::pair<std::vector<int>,int>  vector);
 std::pair<std::vector<int>,int>  resolverPequeno(std::pair<std::vector<int>,int>  vector);
 std::vector<std::pair<std::vector<int>,int> > Divide(std::pair<std::vector<int>,int>  vector, int tamano);
 std::pair<std::vector<int>,int>  Combine(std::pair<std::vector<int>,int>  vector1, std::pair<std::vector<int>,int>  vector2);
 std::string numSubProblemas();
 std::string factorReduccion();
 std::string tiempoCombinacion();
};

#endif