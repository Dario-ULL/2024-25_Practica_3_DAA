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

#include "../Clases/QuickSort.h"

/**
 * @brief Verifica si el tamaño del vector es menor o igual a 1.
 * 
 * Esta función determina si el vector tiene un tamaño suficiente 
 * como para ser dividido más. Si tiene un solo elemento o ninguno, 
 * se considera pequeño y no requiere dividirse más.
 * 
 * @param vector El vector a verificar.
 * @return true Si el vector tiene 1 o menos elementos.
 * @return false Si el vector tiene más de 1 elemento.
 */
bool 
QuickSort::Pequeno(std::pair<std::vector<int>,int> vector) {
  return vector.first.size() <= 1;
}

/**
 * @brief Retorna el mismo vector sin realizar ninguna operación.
 * 
 * Esta función es utilizada cuando el vector es pequeño, es decir,
 * tiene 1 o menos elementos. Dado que no es necesario realizar 
 * operaciones de ordenamiento en estos casos, se devuelve el vector tal cual.
 * 
 * @param vector El vector a devolver.
 * @return El mismo vector sin modificaciones.
 */
std::pair<std::vector<int>,int>
QuickSort::resolverPequeno(std::pair<std::vector<int>,int> vector) {
  return vector;
}

/**
 * @brief Divide el vector en dos subvectores basados en un pivote.
 * 
 * Este método selecciona el último elemento del vector como pivote 
 * y divide los demás elementos en dos subvectores: uno con elementos 
 * menores que el pivote y otro con los mayores o iguales.
 * 
 * @param vector El vector a dividir.
 * @param tamano El tamaño del vector.
 * @return Un vector que contiene dos subvectores: uno con elementos 
 *         menores al pivote y otro con los mayores o iguales.
 */
std::vector<std::pair<std::vector<int>,int>> 
QuickSort::Divide(std::pair<std::vector<int>,int> vector, int tamano) {
  if (vector.first.size() <= 1) {
    return {vector, {}};
  }
  int pivot = vector.first[tamano - 1];
  std::pair<std::vector<int>,int> izquierda, derecha;
  derecha.first.push_back(pivot);
  for (int i = 0; i < tamano - 1; ++i) {
    if (vector.first[i] < pivot) {
      izquierda.first.push_back(vector.first[i]);
    } else {
      derecha.first.push_back(vector.first[i]);
    }
  }
  izquierda.second = vector.second++;
  derecha.second = vector.second++;
  return {izquierda, derecha};
}

/**
 * @brief Combina dos vectores en uno solo.
 * 
 * Esta función toma dos vectores ordenados y los combina en uno solo, 
 * insertando los elementos del segundo vector al final del primero.
 * 
 * @param vector1 El primer vector a combinar.
 * @param vector2 El segundo vector a combinar.
 * @return Un vector que contiene los elementos de ambos vectores.
 */
std::pair<std::vector<int>,int>
QuickSort::Combine(std::pair<std::vector<int>,int> vector1, std::pair<std::vector<int>,int> vector2) {
  std::pair<std::vector<int>,int> solucion;
  solucion = vector1;  
  solucion.first.insert(solucion.first.end(), vector2.first.begin(), vector2.first.end());
  if (vector1.second > vector2.second) {
    solucion.second = vector1.second;
  } else {
    solucion.second = vector2.second;
  }
  return solucion;
}

/**
 * @brief Retorna el número de subproblemas en los que se divide el problema.
 * 
 * En el caso del algoritmo QuickSort, siempre se divide en dos subproblemas: 
 * el subvector con los elementos menores al pivote y el subvector con los mayores.
 * 
 * @return Una cadena que representa el número de subproblemas, en este caso "2".
 */
std::string
QuickSort::numSubProblemas() {
  return "2";
}

/**
 * @brief Retorna el factor de reducción del problema.
 * 
 * Este factor se refiere a cómo se reduce el tamaño del problema en cada 
 * paso recursivo. En QuickSort, el tamaño de los subproblemas se reduce 
 * aproximadamente a la mitad en cada división, por lo que el factor es "n/2".
 * 
 * @return Una cadena que representa el factor de reducción, en este caso "n/2".
 */
std::string
QuickSort::factorReduccion() {
  return "n/2";
}

/**
 * @brief Retorna el tiempo de combinación de los resultados de los subproblemas.
 * 
 * En el caso de QuickSort, después de dividir y ordenar los subvectores, 
 * los elementos se combinan en un tiempo proporcional al número de elementos 
 * en los vectores, es decir, "n".
 * 
 * @return Una cadena que representa el tiempo de combinación, en este caso "n".
 */
std::string
QuickSort::tiempoCombinacion() {
  return "n";
}
