# Proyecto: INVENTARIO RPG
Este proyecto consiste en la creación de un sistema sencillo de ordenamiento de objetos de un inventario de un videojuego RPG.
El programa permite almacenar 3 distintos ítems (armas, armaduras y pociones) junto con sus atributos principales como ID, nombre, rareza y tipo.
Además, el usuario puede interactuar con un menú en consola para:
- Agregar nuevos objetos al inventario.
- Visualizar el inventario.
- Ordenar los objetos bajo diferentes criterios: por nombre, por tipo o por rareza.
- Salir del programa.
Para lograr los ordenamientos se usó la función std::sort de la librería <algorithm>

## Descripción del avance 1
En este primer avance se implementó la clase Item con sus atributos y métodos básicos.
Se creó un vector de objetos Item que funciona como inventario inicial.
El programa incluye las siguientes funcionalidades:
- Mostrar el inventario en su estado original.
- Ordenar el inventario por nombre, tipo y rareza usando std::sort
- Agregar nuevos items al inventario    

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Las entradas requeridas en el programa son las siguientes:
- Elección del usuario del menu
- Informacion del item a agregar

## Descripción de las salidas del avance de proyecto
El programa genera como salida distintas cosas segun la eleccion del usuario, estas puedes ser las siguientes:
- Inventario original (predefinido en el main).
- Inventario ordenado por nombre (alfabético).
- Inventario ordenado por tipo (Arma → Armadura → Pocion).
- Inventario ordenado por rareza (Comun → Rara → Epica → Legendaria).
- Inventario actualizado cuando se agregan nuevos ítems.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se utilizó el algoritmo std::sort, el cual implementa introsort el cual es una combinación de quicksort, heapsort y mergesort. Estos se activan segun la situación como se muestra a continuación. 

**Introsort**
- Es el algoritmo base de std::sort.  
- Comienza usando Quicksort.  
- Si la recursión de Quicksort se hace demasiado profunda (señal de un mal rendimiento), cambia a Heapsort.  
- Cuando los subarreglos que se crean son muy pequeños, usa Insertion sort porque es más eficiente en ese caso. 
##### Complejidad:  
- Mejor caso: O(n log n)
- Caso promedio: O(n log n) 
- Peor caso: O(n log n) 

**Quicksort**
- Es el que se usa la mayor parte del tiempo por su rapidez.
- Divide el arreglo según un pivote y ordena recursivamente.  
- Es rápido y eficiente en promedio, por eso es el que más se usa en std::sort.  
##### Complejidad:
- Mejor caso: O(n log n)  
- Promedio: O(n log n)  
- Peor caso: O(n²) 

**Heapsort**
- No se usa siempre debido a que su rapidez es más baja
- Se activa solo si Quicksort está cayendo en su peor caso.  
- Garantiza que la complejidad de Introsort sea O(n log n) en su peor caso
##### Complejidad:  
- Mejor caso: O(n log n) 
- Promedio: O(n log n)  
- Peor caso: O(n log n)  

**Insertion sort**
- Aunque su mejor caso sea el de complejidad más baja, no se usa siempre ya que es poco probable.
- Usado en subarreglos de tamaño reducido (≈16 elementos o menos).  
- Aunque tiene complejidad cuadrática, es muy eficiente en pocos elementos debido a baja recursividad.
##### Complejidad: 
- Mejor caso: O(n) 
- Promedio: O(n²)  
- Peor caso: O(n²) 

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Creo yo que la decisión de usar std::sort fue adecuada debido a que es fácil de implementar y es eficiente tanto en memoria como en tiempo ya que cambia segun la situación como se describe a continuación:

**Eficiencia en memoria:**  
- Quicksort es eficiente en memoria porque trabaja in-place, es decir, no requiere arreglos auxiliares grandes, solo un stack de recursión de tamaño.  
- Insertion sort, usado en subarreglos pequeños, también es in-place y no necesita memoria adicional.  
- Heapsort, usado solo como respaldo, también es in-place, garantizando que incluso en el peor caso no se requiera espacio extra considerable.  

**Eficiencia en tiempo:**
- En arreglos de tamaño pequeño o mediano, Quicksort es muy rápido en promedio gracias a su estrategia de dividir y a la buena localización de memoria, que aprovecha la caché del procesador.  
- Insertion sort acelera la ordenación de subarreglos pequeños dentro de Introsort, reduciendo la recursión y comparaciones innecesarias.  
- Heapsort asegura que nunca se degrade la complejidad a O(n²), manteniendo un límite máximo de O(n log n) en el peor caso.  
- Combinando estas estrategias, std::sort ofrece un rendimiento eficiente y robusto en prácticamente todos los escenarios posibles, lo que simplifica el diseño del programa y evita tener que implementar manualmente varios algoritmos de ordenamiento.

