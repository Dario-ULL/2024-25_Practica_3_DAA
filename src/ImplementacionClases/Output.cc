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

#include "../Clases/Output.h"

/**
 * @brief Constructor por defecto de la clase Output.
 * 
 * Este constructor inicializa un objeto de la clase Output sin 
 * asociarlo a ningún archivo en particular. El objeto estará listo 
 * para ser utilizado, pero no realizará operaciones con archivos 
 * hasta que se le proporcione un nombre de fichero.
 */
Output::Output() {}

/**
 * @brief Constructor de la clase Output que inicializa con un archivo.
 * 
 * Este constructor inicializa el objeto Output con el nombre de un 
 * archivo y abre dicho archivo en modo truncamiento para escribir en él. 
 * Si el archivo no puede abrirse, se muestra un mensaje de error.
 * 
 * @param fichero El nombre del archivo con el que se inicializa el objeto Output.
 */
Output::Output(std::string fichero) { 
  fichero_ = fichero;
  std::ofstream file(fichero_, std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo " << fichero_ << std::endl;
    }
}

/**
 * @brief Destructor de la clase Output.
 * 
 * Este destructor es utilizado para liberar recursos cuando el objeto 
 * Output ya no sea necesario. Actualmente, no realiza ninguna operación 
 * específica ya que la clase no maneja recursos complejos.
 */
Output::~Output() {}

/**
 * @brief Muestra el contenido de un vector de enteros.
 * 
 * Este método imprime el contenido de un vector de enteros en la salida 
 * estándar o en un archivo, dependiendo de si se ha especificado un archivo 
 * en el constructor. Si el archivo está definido, los resultados se 
 * escriben en él. De lo contrario, se muestra el vector en la consola.
 * 
 * @param v El vector de enteros a mostrar.
 */
void 
Output::MostrarVector(const std::vector<int>& v) {
  if (fichero_ != "") { 
    std::ofstream file(fichero_, std::ios::app);
    if (file.is_open()) {
      file << "[ ";
      for (int num : v) {
        file << num << " ";
      }
      file << "]" << std::endl;
    } else {
      std::cerr << "Error al abrir el archivo " << fichero_ << std::endl;
    }
  } else {
    std::cout << "[ ";
    for (int num : v) {
      std::cout << num << " ";
    }
    std::cout << "]" << std::endl;
  }
}

/**
 * @brief Mide y muestra el tiempo de ejecución de un algoritmo.
 * 
 * Este método mide el tiempo que tarda en ejecutar el método Resolver 
 * de un algoritmo pasado como parámetro. Los tiempos de ejecución se 
 * muestran en la consola o se escriben en un archivo, según la configuración 
 * de la clase Output.
 * 
 * @param algoritmo El algoritmo que se va a ejecutar.
 * @param A El vector de datos sobre el que se ejecuta el algoritmo.
 * @param n El tamaño del vector, que se utiliza en la salida para mostrar el tamaño del problema.
 */
void 
Output::medirTiempoEjecucion(DyV* algoritmo, const std::vector<int>& A, const int n) {
  if (fichero_ != "") { 
    std::ofstream file(fichero_, std::ios::app);
    if (file.is_open()) {
    auto inicio = std::chrono::high_resolution_clock::now();
    algoritmo->Resolver(A, A.size());
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    file << "Tiempo de ejecución("<< n << "): " << duracion.count() << " ms\n";
    } else {
    std::cerr << "Error al abrir el archivo " << fichero_ << std::endl;
    }
  } else {
    auto inicio = std::chrono::high_resolution_clock::now();
    algoritmo->Resolver(A, A.size());
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    std::cout << "Tiempo de ejecución("<< n << "): " << duracion.count() << " ms\n";
  }
}
