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
QuickSort::Pequeno(std::vector<int> vector) {
  return vector.size() <= 1;
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
std::vector<int> 
QuickSort::resolverPequeno(std::vector<int> vector) {
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
std::vector<std::vector<int>> 
QuickSort::Divide(std::vector<int> vector, int tamano) {
  if (vector.size() <= 1) {
    return {vector, {}};
  }
  int pivot = vector[tamano - 1];
  std::vector<int> izquierda, derecha;
  derecha.push_back(pivot);
  for (int i = 0; i < tamano - 1; ++i) {
    if (vector[i] < pivot) {
      izquierda.push_back(vector[i]);
    } else {
      derecha.push_back(vector[i]);
    }
  }
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
std::vector<int> 
QuickSort::Combine(std::vector<int> vector1, std::vector<int> vector2) {
  std::vector<int> solucion;
  solucion = vector1;  
  solucion.insert(solucion.end(), vector2.begin(), vector2.end());
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
