# Evidencia problemas

**Problema 1**

Video problema 1: https://drive.google.com/file/d/1SM8U746mkQ9k_MjK2RnBqt4VgAaTLlbn/view?usp=sharing

Enlace submission: https://leetcode.com/problems/largest-number/submissions/1826573723/

**Problema 2**

Video problema 2: https://drive.google.com/file/d/16DcOTqTvW4pKn8VjhxLjtv1UdRQKbUrp/view?usp=drive_link

Enlace submission: https://leetcode.com/problems/reverse-linked-list/submissions/1826585446/

**Problema 3**

Video problema 3: https://drive.google.com/file/d/1MQK0AOkFJVQ7mub306-Rhs2qHl89zh9y/view?usp=sharing

Enlace submission: https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

# Proyecto: Inventario RPG
Este proyecto consiste en la creación de un sistema de inventario para un videojuego RPG que permite almacenar, visualizar, ordenar y administrar objetos de distintos tipos y rarezas.
En este avance se amplía la funcionalidad del sistema para incluir mecánicas de combate con recompensas aleatorias, manejo de historial de objetos agregados, uso de pociones desde una pila de acceso rápido y guardado automático del inventario en un archivo externo.

## Descripción del avance 1
En el primer avance se implementó la clase Item con sus atributos y métodos básicos.
Se creó un vector de objetos Item que funciona como inventario inicial.
El programa incluye las siguientes funcionalidades:

- Mostrar el inventario en su estado original.
- Ordenar el inventario por nombre, tipo y rareza usando std::sort.
- Agregar nuevos ítems al inventario introduciendo manualmente sus datos.

## Descripción del avance 2
En el segundo avance, el proyecto evolucionó a un sistema más dinámico e interactivo, en el que los ítems ya no se crean manualmente, sino que se seleccionan desde un archivo externo (items.txt) que contiene todos los ítems disponibles en el juego.
Además, se añadio un inventario rápido de pociones manejado con una pila (stack), donde la última poción agregada es la primera que se puede usar.

### Cambios sobre el primer avance
1. Lectura de ítems desde archivo (items.txt)

- En lugar de crear ítems manualmente desde el teclado, ahora se leen desde un archivo de texto.

- Este cambio mejora la escalabilidad del programa y facilita la administración de una base de datos de ítems predefinida.

2. Filtrado avanzado al agregar ítems

- El usuario puede buscar ítems por tipo (Arma, Armadura, Pocion), rareza (Comun, Rara, Epica, Legendaria) o por la letra inicial del nombre.

- Esto simula un sistema de búsqueda más realista dentro del inventario de un RPG.

3. Implementación de una pila (stack) de inventario rápido de pociones

- Las pociones se agregan automáticamente a un stack adicional.

- Se puede “tomar” una poción usando la opción correspondiente del menú, la cual extrae la última agregada (LIFO).

- Representa una mecánica clásica de los videojuegos donde las pociones se usan en orden inverso al que fueron obtenidas.

4. Nuevo menú con más funcionalidades

- Se agregan las opciones para filtrar ítems al agregarlos y para usar una poción del inventario rápido.

5. Mejor manejo del historial de ítems agregados

- El historial (stack<Item>) guarda el último ítem agregado y se puede consultar fácilmente.

Razón de los cambios:
Estos cambios permiten hacer el programa más modular, escalable y cercano a un entorno real de videojuego RPG, donde los ítems no se escriben manualmente sino que provienen de una base de datos predefinida y pueden ser manipulados por tipo o rareza.

## Descripción del avance 3
En este tercer avance se integran nuevas funcionalidades relacionadas con el combate, la gestión de recompensas y el guardado automático del progreso del jugador, casi no se cambiaron funciones del segundo avance, unicamente se agregaron funciones.

El sistema ahora incluye:

- Una función de pelea (pelear()) que permite al jugador realizar ataques rápidos o fuertes, donde si el jugador gana la batalla, obtiene una recompensa aleatoria seleccionada del archivo de ítems. estas recompensas se agregan automáticamente al inventario y al historial.
- Se implementó una función de guardado automático que almacena el inventario completo en un archivo (inventario_guardado.txt) al salir del programa.
- Con la implementación del guardado automático, ahora que carga primero el inventario guardado, si se borra el archivo de texto llamado inventario_guardado.txt se iniciara con el inventario por default

### Cambios sobre el segundo avance
1. Incorporación del sistema de combate.
Razón: dar un propósito dinámico al inventario, simulando un entorno real de juego donde los ítems tienen valor estratégico.

2. Recompensas aleatorias.
Razón: agregar aleatoriedad y rejugabilidad al programa, usando rand() para seleccionar ítems al azar del archivo base.

3. Guardado automático del inventario.
Razón: conservar el progreso del jugador al cerrar el programa, simulando una función de “guardar partida”.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o tercer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercer_avance` 

## Descripción de las entradas del avance de proyecto
Las entradas requeridas en el programa son las siguientes:
- Archivo de texto
- Opción elegida (1–9)
- Filtros al buscar ítems: tipo, rareza o letra inicial
- ID del ítem que desea agregar al inventario

## Descripción de las salidas del avance de proyecto
Dependiendo de la elección del usuario, el programa puede mostrar:
- Lista completa de ítems o filtrada según el criterio de búsqueda.
- Inventario ordenado por nombre, tipo o rareza.
- El último ítem agregado.
- Confirmación de que una poción ha sido usada desde el inventario rápido.
- Mensajes de error en caso de seleccionar un ID inexistente o una opción inválida.
- Archivo de texto con el inventario guardado

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

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El proyecto utiliza tres estructuras de datos principales: vector, stack, y ifstream (para la lectura de archivos).
Cada una fue elegida según las operaciones más frecuentes del sistema y su complejidad temporal.

**Vector**
- Se utiliza para almacenar el inventario principal de ítems.
- Permite acceso directo a cualquier elemento mediante índices (O(1)).
- La inserción al final del vector (push_back) tiene complejidad O(1) amortizada.
- El recorrido o búsqueda secuencial es O(n), adecuado para listas pequeñas.
- Permite usar std::sort directamente sobre su contenido, optimizando los procesos de ordenamiento.
##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(n)
- Peor caso: O(n log n)

**Stack**
- Se utiliza para el historial de ítems agregados y para las pociones rápidas.
- Implementa el comportamiento LIFO.
- Todas sus operaciones (push, pop, top) tienen complejidad constante O(1).
- Es ideal para modelar el historial y el uso rápido de pociones, ya que el último elemento agregado es el primero que se usa o consulta.
Razón de elección:
Se eligió stack en lugar de otras estructuras como queue o doublelinkedlist debido a la naturaleza de las acciones del juego.
El inventario rápido debe permitir usar la última poción agregada de inmediato, lo cual representa perfectamente el principio LIFO.
Una queue no respetaría este comportamiento, y una list implicaría un mayor uso de memoria y tiempos de acceso más altos sin beneficio adicional.
Por ello, stack es la opción más eficiente y semánticamente correcta para este tipo de operación.

**Analisis de complejidad de las operaciones realizadas con la pila**

#### Agregar (push):
Inserta un nuevo elemento en la parte superior de la pila.
##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(1)
- Peor caso: O(1)

#### Eliminar (pop):
Elimina el elemento superior de la pila.
##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(1)
- Peor caso: O(1)

#### Consultar el último elemento (top):
Permite acceder al elemento superior sin eliminarlo.
##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(1)
- Peor caso: O(1)

#### Búsqueda completa:
Buscar un elemento específico recorriendo toda la pila (aunque no se neceesita en este programa).
##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(n)
- Peor caso: O(n)

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Además de los algoritmos de ordenamiento y las estructuras de datos, el programa incluye varios componentes adicionales que realizan operaciones de búsqueda, filtrado, combate, manejo de archivos y guardado automático.
A continuación se detalla el análisis de complejidad de cada uno de estos componentes:

**Lectura de archivos**
El programa utiliza ifstream para leer los ítems desde un archivo de texto.
Cada línea del archivo contiene los datos de un ítem, que se almacenan en el vector de inventario mediante la operación push_back().

##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(n)
- Peor caso: O(n)

**Escritura de archivos**
Cuando el programa termina, el inventario actualizado se guarda automáticamente en inventario_guardado.txt.

##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(n)
- Peor caso: O(n)

**Busqueda de items**
Las búsquedas se realizan mediante comparación secuencial dentro del vector.

##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(n)
- Peor caso: O(n)

**Filtrar items**
El programa permite filtrar ítems por tipo, rareza o letra inicial.

##### Complejidad:
- Mejor caso: O(n)
- Caso promedio: O(n)
- Peor caso: O(n)

**Pelear con enemigos**
La función de pelea involucra únicamente cálculos aritméticos y condicionales, sin estructuras iterativas grandes, sin embargo, para determinar la recompensa se requiere recorrer los items existentes.

##### Complejidad:
- Mejor caso: O(1)
- Caso promedio: O(n)
- Peor caso: O(n)

**Menu principal**
En este caso depende de la elección del usuario.

#### Complejidad:
- Mejor caso: O(1)
- Promedio: O(n log n)
- Peor caso: O(n log n)

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

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Creo yo que la decisión de usar las estructuras vector, stack y ifstream fue la más adecuada para el desarrollo de este sistema de inventario RPG.
Cada una cumple una función específica que mejora el rendimiento general del programa y facilita su mantenimiento.
Además, todas aprovechan al máximo la biblioteca estándar de C++, lo que garantiza eficiencia, portabilidad y facilidad de implementación.

**Eficiencia en memoria**
- El uso de vector permite almacenar los ítems del inventario de manera continua en memoria, lo que mejora la localidad espacial y reduce el uso de punteros adicionales.
A diferencia de otras estructuras como list, no requiere nodos separados ni enlaces, lo que ahorra memoria y permite un acceso más rápido.
- La estructura stack, basada internamente en un contenedor secuencial (como deque o vector), también gestiona sus elementos de forma compacta y eficiente.
Esto permite que las operaciones push y pop se realicen directamente sin necesidad de reasignar grandes bloques de memoria.
- Ifstream permite mantener los datos del inventario base en un archivo de texto externo, evitando ocupar memoria del programa con todos los ítems posibles durante la ejecución.
De esta forma, solo se cargan los datos necesarios cuando el jugador decide agregar un nuevo ítem, optimizando el uso total de recursos.

**Eficiencia en tiempo**
- El vector fue elegido por su velocidad al realizar operaciones de inserción y recorrido secuencial.
Las inserciones al final tienen una complejidad de O(1) y la búsqueda directa por índice es inmediata, lo que lo hace ideal para un inventario que se modifica constantemente.
- El stack fue seleccionado porque sus operaciones (push, pop, top) tienen una complejidad constante O(1) en todos los casos.
Esto lo convierte en la opción perfecta para el historial de ítems agregados y para el inventario rápido de pociones, donde se requiere acceder al último elemento de forma inmediata.
Elegir una queue o una list habría sido menos eficiente para estas tareas, ya que no siguen el patrón de acceso LIFO que se necesita en este contexto.
- El uso de ifstream para leer los ítems desde archivo es eficiente porque realiza la lectura de manera secuencial (O(n)) y solo una vez durante la carga inicial.
Esto simplifica el mantenimiento, permite agregar nuevos objetos sin cambiar el código y mantiene un rendimiento estable sin sobrecargar el programa con estructuras innecesarias en memoria.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Considero que desarrollé esta competencia al implementar distintas funciones que permiten consultar, filtrar y mostrar información del inventario de manera eficiente y organizada.
El programa utiliza vectores para almacenar los ítems y, sobre ellos, se aplican diferentes algoritmos y funciones para obtener datos específicos según las necesidades del usuario.
- Por ejemplo, se implementaron funciones como buscarItem() para localizar un ítem por su nombre, y menús interactivos que permiten ordenar el inventario por nombre, tipo o rareza utilizando el algoritmo std::sort().
Esto demuestra un uso correcto de las estructuras de datos, ya que se aprovechan las ventajas de acceso secuencial y de ordenamiento que ofrece el vector, sin necesidad de estructuras más complejas o menos eficientes.
- Además, se agregó la función verUltimoAgregado(), que utiliza un stack para consultar el último ítem insertado en el historial.
Esto refleja la aplicación adecuada del concepto de consulta dentro de una pila, ya que solo el elemento más reciente puede ser visualizado o retirado, tal como ocurre en un historial o una acción rápida dentro de un juego RPG.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En esta parte del proyecto, la competencia se desarrolló mediante la creación de un sistema de lectura de archivos con ifstream, encargado de cargar todos los ítems posibles desde un archivo externo (items.txt).
Este archivo contiene una lista completa de objetos con sus atributos (ID, nombre, tipo y rareza), y el programa los carga en un vector de objetos Item cuando es necesario agregar un Item al inventario.
El proceso de lectura se implementó de forma secuencial y controlada, validando que cada línea del archivo contenga los datos correctos antes de almacenarlos.
De esta manera, se garantiza que las estructuras de datos del programa siempre contengan información válida y coherente con el formato del archivo.
Además, se incluyeron opciones de filtrado para que el usuario pueda buscar ítems por tipo, por rareza o por la letra inicial del nombre, aprovechando los datos cargados desde el archivo.
Esto demuestra una correcta integración entre la lectura de archivos y las estructuras de datos, ya que la información externa se utiliza de forma dinámica dentro del programa sin necesidad de reescribir o recompilar el código.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Considero que desarrollé esta competencia al implementar funciones que permiten guardar el inventario del jugador en archivos externos mediante ofstream.
El programa recorre el vector principal de ítems y escribe en inventario_guardado.txt los datos de cada objeto (ID, nombre, tipo y rareza) de forma ordenada y legible.
Este proceso se ejecuta automáticamente al finalizar el programa o tras obtener una recompensa, asegurando que los cambios se conserven entre sesiones.
En conjunto, este mecanismo demuestra un uso correcto de las estructuras de datos y del manejo de archivos, garantizando la persistencia y coherencia de los datos del juego, con esto creo yo que se demuestra como desarolle todas las competencias necesarias.
