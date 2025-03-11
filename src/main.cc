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

#include "Clases/DyV.h"
#include "Clases/MergeSort.h"
#include "Clases/QuickSort.h"
#include "Clases/Output.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>

/**
 * @brief Genera un vector aleatorio de enteros del 1 al n.
 * 
 * Este método crea un vector que contiene los números del 1 al n, 
 * y luego los desordena aleatoriamente usando un generador de números 
 * aleatorios.
 * 
 * @param n El tamaño del vector a generar.
 * @return Un vector de enteros con los números del 1 al n, desordenados.
 */
std::vector<int> 
generar_vector(int n) {
	std::vector<int> vector;
	for (int i = 1; i <= n; ++i) {
		vector.push_back(i);
	}
	std::random_device rd; 
	std::mt19937 g(rd());   
	std::shuffle(vector.begin(), vector.end(), g);
	return vector;
}

/**
 * @brief Procesa el algoritmo con la opción de depuración activada.
 * 
 * Este método se encarga de mostrar el vector generado y el vector ordenado
 * usando el algoritmo seleccionado (MergeSort o QuickSort) cuando se ejecuta 
 * en modo depuración. El resultado se imprime por consola o se guarda en 
 * un archivo dependiendo de los argumentos proporcionados.
 * 
 * @param algoritmo El objeto del algoritmo (MergeSort o QuickSort) a ejecutar.
 * @param argc El número de argumentos de la línea de comandos.
 * @param argv Los argumentos de la línea de comandos.
 */
void 
procesarConDebug(DyV* algoritmo, int argc, char* argv[]) {
	std::cout << "Debug" << std::endl;
	int n = std::stoi(argv[3]);
	std::pair<std::vector<int>,int> vector(generar_vector(n), 0);
	if (argc == 5) {
		Output output(argv[4]);
		output.MostrarVector(vector);
		vector = algoritmo->Resolver(vector, vector.first.size());
		output.MostrarVector(vector);
		output.MostrarNivelArbol(vector);
	} else {
		Output output;
		output.MostrarVector(vector);
		vector = algoritmo->Resolver(vector, vector.first.size());
		output.MostrarVector(vector);
		output.MostrarNivelArbol(vector);	
	}
}

/**
 * @brief Procesa el algoritmo sin la opción de depuración.
 * 
 * Este método ejecuta el algoritmo para diferentes tamaños de entrada (10, 100, 10000) 
 * y mide el tiempo de ejecución. Los resultados se muestran por consola o se guardan 
 * en un archivo dependiendo de los argumentos proporcionados.
 * 
 * @param algoritmo El objeto del algoritmo (MergeSort o QuickSort) a ejecutar.
 * @param argc El número de argumentos de la línea de comandos.
 * @param argv Los argumentos de la línea de comandos.
 */
void 
procesarSinDebug(DyV* algoritmo, int argc, char* argv[]) {
	if (argc == 3) {
		Output output(argv[2]);
		for (int n : {10, 100, 10000}) {
			std::vector<int> vector = generar_vector(n);
			output.medirTiempoEjecucion(algoritmo, {vector, 0}, n);
		}
	} else {
		Output output;
		for (int n : {10, 100, 10000}) {
			std::vector<int> vector = generar_vector(n);
			output.medirTiempoEjecucion(algoritmo, {vector, 0}, n);
		}
	}
}

/**
 * @brief Función principal del programa.
 * 
 * La función main se encarga de seleccionar el algoritmo (MergeSort o QuickSort) 
 * basado en los argumentos proporcionados. Luego, dependiendo de los argumentos, 
 * ejecuta el algoritmo con o sin la opción de depuración, procesando y mostrando 
 * los resultados de acuerdo con los tamaños de entrada predefinidos.
 * 
 * @param argc El número de argumentos de la línea de comandos.
 * @param argv Los argumentos de la línea de comandos.
 * @return 0 si el programa se ejecuta correctamente, 1 si hay un error.
 */
int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Error: Numero de argumentos incorrecto." << std::endl;
		std::cerr << "Uso: ./main <M/Q> (opcional) <-d> <n> <nombre_fichero>" << std::endl;
		return 1;
	}
	DyV* algoritmo;
	char tipo = argv[1][0];
	switch (tipo) {
		case 'M':
			algoritmo = new MergeSort();
			std::cout << "MergeSort" << std::endl;
			break;
		case 'Q':
			algoritmo = new QuickSort();
			std::cout << "QuickSort" << std::endl;
			break;
		default:
			std::cerr << "Error: Algoritmo no reconocido." << std::endl;
			return 1;
	}
	if (argc > 2 && std::string(argv[2]) == "-d") {
		procesarConDebug(algoritmo, argc, argv);
	} else {
		procesarSinDebug(algoritmo, argc, argv);
	}
	return 0;
}
