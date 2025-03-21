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

#include "../Clases/MergeSort.h"

/**
 * @brief Determina si el vector es lo suficientemente pequeño para ser resuelto directamente.
 * 
 * Este método verifica si el tamaño del vector es menor o igual a 1. Si es así, 
 * el vector se considera lo suficientemente pequeño como para no requerir más divisiones 
 * y se puede devolver tal cual.
 * 
 * @param vector El vector a evaluar.
 * @return Verdadero si el tamaño del vector es menor o igual a 1, falso en caso contrario.
 */
bool 
MergeSort::Pequeno(std::pair<std::vector<int>,int> vector) {
  return vector.first.size() <= 1;
}

/**
 * @brief Resuelve el problema para un vector pequeño.
 * 
 * Si el tamaño del vector es suficientemente pequeño, este método simplemente 
 * lo devuelve tal como está sin realizar más divisiones.
 * 
 * @param vector El vector a resolver.
 * @return El mismo vector como resultado.
 */
std::pair<std::vector<int>,int>
MergeSort::resolverPequeno(std::pair<std::vector<int>,int> vector) {
  return vector;
}

/**
 * @brief Divide el vector en dos subvectores.
 * 
 * Este método divide el vector de entrada en dos subvectores. Uno contiene los 
 * elementos desde el principio hasta el medio del vector, y el otro contiene 
 * los elementos restantes. Estos subvectores serán procesados recursivamente.
 * 
 * @param vector El vector que se va a dividir.
 * @param tamano El tamaño del vector, aunque no se utiliza directamente en este método.
 * @return Un vector de dos subvectores que contienen las partes divididas.
 */
std::vector<std::pair<std::vector<int>,int>> 
MergeSort::Divide(std::pair<std::vector<int>,int> vector, int tamano) {
  int medio = vector.first.size()/2;
  std::pair<std::vector<int>,int> izquierda;
  izquierda.first = std::vector<int>(vector.first.begin(), vector.first.begin() + medio);
  izquierda.second = vector.second++;
  std::pair<std::vector<int>,int> derecha;
  derecha.first = std::vector<int>(vector.first.begin() + medio, vector.first.end());
  derecha.second = vector.second++;
  return {izquierda, derecha};
}

/**
 * @brief Combina dos subvectores ordenados en un único vector ordenado.
 * 
 * Este método recibe dos subvectores que ya están ordenados y los combina en 
 * un solo vector, manteniendo el orden. El algoritmo recorre ambos subvectores 
 * y va agregando el menor elemento de cada uno al vector resultante.
 * 
 * @param vector1 El primer subvector a combinar.
 * @param vector2 El segundo subvector a combinar.
 * @return Un vector que contiene los elementos de los dos subvectores, ordenados.
 */
std::pair<std::vector<int>,int>
MergeSort::Combine(std::pair<std::vector<int>,int>vector1, std::pair<std::vector<int>,int> vector2) {
  std::pair<std::vector<int>,int> resultado;
  size_t i = 0;
  size_t j = 0;
  while (i < vector1.first.size() && j < vector2.first.size()) {
    if (vector1.first[i] < vector2.first[j]) {
      resultado.first.push_back(vector1.first[i]);
      i++;
    } else {
      resultado.first.push_back(vector2.first[j]);
      j++;
    }
  }
  while (i < vector1.first.size()) {
    resultado.first.push_back(vector1.first[i++]);
  }
  while (j < vector2.first.size()) {
    resultado.first.push_back(vector2.first[j++]);
  }  
  if (vector1.second > vector2.second) {
    resultado.second = vector1.second;
  } else {
    resultado.second = vector2.second;
  }
  return resultado;
}

/**
 * @brief Devuelve el número de subproblemas en el algoritmo.
 * 
 * Este método indica cuántos subproblemas se generan en cada paso del algoritmo. 
 * En el caso del MergeSort, siempre se generan 2 subproblemas, uno para la mitad 
 * izquierda y otro para la mitad derecha del vector.
 * 
 * @return Una cadena que representa el número de subproblemas.
 */
std::string
MergeSort::numSubProblemas() {
  return "2";
}

/**
 * @brief Devuelve el factor de reducción del tamaño del problema.
 * 
 * Este método devuelve el factor por el cual se reduce el tamaño del problema 
 * en cada paso. En el caso del MergeSort, el tamaño se divide entre 2.
 * 
 * @return Una cadena que representa el factor de reducción del tamaño del problema.
 */
std::string
MergeSort::factorReduccion() {
  return "n/2";
}

/**
 * @brief Devuelve el tiempo de combinación en el algoritmo.
 * 
 * Este método devuelve la complejidad temporal del paso de combinación en el 
 * algoritmo. En MergeSort, el tiempo de combinación es proporcional al tamaño 
 * del vector, es decir, O(n).
 * 
 * @return Una cadena que representa el tiempo de combinación.
 */
std::string
MergeSort::tiempoCombinacion() {
  return "O(n)";
}
