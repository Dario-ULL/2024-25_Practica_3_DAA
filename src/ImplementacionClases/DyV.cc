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

#include "../Clases/DyV.h"

/**
 * @brief Resuelve el problema utilizando el algoritmo de Divide y Venceras.
 * 
 * Este método aplica el patrón de Divide y Venceras, dividiendo el vector en 
 * subproblemas más pequeños hasta que alcanza un tamaño lo suficientemente 
 * pequeño para ser resuelto de manera directa. Luego combina los resultados 
 * de los subproblemas para obtener la solución final.
 * 
 * @param vector El vector de enteros que se va a procesar.
 * @param tamano El tamaño del vector.
 * @return Un vector que contiene la solución combinada de los subproblemas.
 */
std::pair<std::vector<int>,int>
DyV::Resolver(std::pair<std::vector<int>,int> vector, int tamano) {
  if (Pequeno(vector)) {
    return resolverPequeno(vector);
  } else {
    std::vector<std::pair<std::vector<int>,int>> m = Divide(vector, tamano);
    std::pair<std::vector<int>,int> S1 = Resolver(m[0], m[0].first.size());
    std::pair<std::vector<int>,int> S2 = Resolver(m[1], m[1].first.size());
    std::pair<std::vector<int>,int> S = Combine(S1, S2);
    return S;
  }
}

/**
 * @brief Genera la recurrencia del algoritmo.
 * 
 * Este método devuelve una representación de la recurrencia que describe 
 * la complejidad temporal del algoritmo. En el caso de Divide y Venceras, 
 * la recurrencia se expresa en términos de los subproblemas, el factor de 
 * reducción y el tiempo de combinación.
 * 
 * @return Una cadena que representa la recurrencia del algoritmo.
 */
std::string
DyV::recurrencia() {
  return "T(n) = " + numSubProblemas() + "T(" + factorReduccion() + ") + " + tiempoCombinacion();
}
