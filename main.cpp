#include "Item.h"

vector<Item> cargarTodosLosItems(const string& nombreArchivo) {
    // Complejidad:
    // Mejor caso: O(n)
    // Promedio: O(n)
    // Peor caso: O(n)
    vector<Item> items;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo de ítems (" << nombreArchivo << ")\n";
        return items;
    }

    int id;
    string nombre, rareza, tipo;
    while (archivo >> id >> nombre >> rareza >> tipo) {
        items.emplace_back(id, nombre, rareza, tipo);
    }
    archivo.close();
    return items;
}

void mostrarItemsFiltrados(const vector<Item>& items, const string& filtroTipo = "", const string& filtroRareza = "", char letra = '\0') {
    // Complejidad:
    // Mejor caso: O(n)
    // Promedio: O(n)
    // Peor caso: O(n)
    cout << "\nITEMS DISPONIBLES\n";
    for (const auto& it : items) {
        bool coincide = true;
        if (!filtroTipo.empty() && it.getTipo() != filtroTipo) coincide = false;
        if (!filtroRareza.empty() && it.getRareza() != filtroRareza) coincide = false;
        if (letra != '\0' && toupper(it.getNombre()[0]) != toupper(letra)) coincide = false;
        if (coincide) it.mostrarInventario();
    }
}

void buscarItem(const vector<Item>& inventario, const string& nombreBuscado) {
    // Complejidad:
    // Mejor caso: O(1) (si el ítem está al inicio)
    // Promedio: O(n)
    // Peor caso: O(n)
    bool encontrado = false;
    for (const auto& it : inventario) {
        if (it.getNombre() == nombreBuscado) {
            it.mostrarInventario();
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No tienes el item en tu inventario. \n";
}

void verUltimoAgregado(stack<Item> historial) {
    // Complejidad:
    // Mejor caso: O(1)
    // Promedio: O(1)
    // Peor caso: O(1)
    if (historial.empty()) {
        cout << "No hay items en el historial.\n";
        return;
    }
    cout << "Ultimo item agregado:\n";
    historial.top().mostrarInventario();
}

void tomarPocion(stack<Item>& pocionesRapidas, vector<Item>& inventario) {
    // Complejidad:
    // Mejor caso: O(1)
    // Promedio: O(1)
    // Peor caso: O(1)
    if (pocionesRapidas.empty()) {
        cout << "No tienes pociones disponibles en el inventario rapido.\n";
        return;
    }

    Item pocionTomada = pocionesRapidas.top();
    pocionesRapidas.pop();

    cout << "Has tomado la pocion: ";
    pocionTomada.mostrarInventario();

    auto it = remove_if(inventario.begin(), inventario.end(), [&](const Item& i) {
        return i.getId() == pocionTomada.getId();
    });

    inventario.erase(it, inventario.end());
}

int ordenarRareza(const string& rareza) {
  if (rareza == "Comun") return 0;
  if (rareza == "Rara") return 1;
  if (rareza == "Epica") return 2;
  if (rareza == "Legendaria") return 3;
  return 9999;
}

int ordenarTipo(const string& tipo){
  if (tipo == "Arma") return 0;
  if (tipo == "Armadura") return 1;
  if (tipo == "Pocion") return 2;
  return 9999;
}


void agregarItem(vector<Item>& inventario, stack<Item>& historial, stack<Item>& pocionesRapidas) {
  vector<Item> todosLosItems = cargarTodosLosItems("items.txt");
  if (todosLosItems.empty()) {
      cout << "No se pudo cargar la lista de ítems.\n";
      return;
  }

  int opcion;
    cout << "\nAGREGAR ITEM DESDE LISTA\n";
    cout << "1. Ver lista completa\n";
    cout << "2. Filtrar por tipo\n";
    cout << "3. Filtrar por rareza\n";
    cout << "4. Filtrar por letra inicial del nombre\n";
    cout << "Elige una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        mostrarItemsFiltrados(todosLosItems);
    } 
    else if (opcion == 2) {
        string tipo;
        bool continuar = true;
        int tipoNum;

        while (continuar) {
          cout << "1. Arma\n2. Armadura\n3. Pocion\nIntroduce el tipo: ";
          cin >> tipoNum;
          if (tipoNum == 1) { tipo = "Arma"; continuar = false; }
          else if (tipoNum == 2) { tipo = "Armadura"; continuar = false; }
          else if (tipoNum == 3) { tipo = "Pocion"; continuar = false; }
          else {
              cout << "Incorrecto, intente otra vez" << endl;
          }
        }
        cin >> tipo;
        mostrarItemsFiltrados(todosLosItems, tipo);
    } 
    else if (opcion == 3) {
        string rareza;
        bool continuar = true;
        int tipoNum;

        while (continuar) {
          cout << "1. Comun\n2. Rara\n3. Epica\n4. Legendaria\nIntroduce la rareza: ";
          cin >> tipoNum;
          if (tipoNum == 1) { rareza = "Comun"; continuar = false; }
          else if (tipoNum == 2) { rareza = "Rara"; continuar = false; }
          else if (tipoNum == 3) { rareza = "Epica"; continuar = false; }
          else if (tipoNum == 4) { rareza = "Legendaria"; continuar = false; }
          else {
              cout << "Incorrecto, intente otra vez" << endl;
          }
        }
        mostrarItemsFiltrados(todosLosItems, "", rareza);
    } 
    else if (opcion == 4) {
        char letra;
        cout << "Introduce la letra inicial del nombre: ";
        cin >> letra;
        mostrarItemsFiltrados(todosLosItems, "", "", letra);
    } 
    else {
        cout << "Opción inválida.\n";
        return;
    }

    int idSeleccion;
    cout << "\nIntroduce el ID del item que deseas agregar al inventario: ";
    cin >> idSeleccion;

    bool encontrado = false;
    for (const auto& it : todosLosItems) {
        if (it.getId() == idSeleccion) {
            inventario.push_back(it);
            historial.push(it);
            if (it.getTipo() == "Pocion")
                pocionesRapidas.push(it);
            cout << "Item agregado correctamente al inventario.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró un ítem con ese ID.\n";
    }

}

void imprimirInventario(vector<Item>& inventario){
  cout << "\n";
  for (const auto& it : inventario) it.mostrarInventario();
}

void menu(){
  cout << "\nMENU INVENTARIO\n";
  cout << "1. Agregar objeto al inventario\n";
  cout << "2. Ver inventario\n";
  cout << "3. Ordenar por nombre\n";
  cout << "4. Ordenar por tipo\n";
  cout << "5. Ordenar por rareza\n";
  cout << "6. Buscar item por nombre\n";
  cout << "7. Ver ultimo item agregado\n";
  cout << "8. Tomar una pocion del inventario rapido\n";
  cout << "9. Salir\n";
}

void eleccion(vector<Item>& inventario, stack<Item>& historial, stack<Item>& pocionesRapidas){
  bool continuar=true;
  int op;
  int cal;
  while (continuar){
      menu();
      cout<<"Elije una opcion: ";
      cin>>op;
      if (op==1){
        agregarItem(inventario, historial, pocionesRapidas); 
      }
      else if (op==2){
        imprimirInventario(inventario);
      }
      else if (op==3){
        // sort usa Introsort. En este caso está ejecutando Quicksort (O(n log n) promedio, O(n^2) peor caso) ya que el inventario es reducido (menos de 16 elementos)
        sort(inventario.begin(), inventario.end(), [](const Item& a, const Item& b) {
              return a.getNombre() < b.getNombre();
          });
          imprimirInventario(inventario);
      }
      else if (op==4){
        // sort usa Introsort. En este caso está ejecutando Quicksort (O(n log n) promedio, O(n^2) peor caso) ya que el inventario es reducido (menos de 16 elementos)
        sort(inventario.begin(), inventario.end(), [](const Item& a, const Item& b) {
          int ta = ordenarTipo(a.getTipo());
          int tb = ordenarTipo(b.getTipo());

          if (ta == tb) {
              return a.getId() < b.getId();
          }
          return ta < tb;
        });
        imprimirInventario(inventario);
      }
      else if (op==5){
        // sort usa Introsort. En este caso está ejecutando Quicksort (O(n log n) promedio, O(n^2) peor caso) ya que el inventario es reducido (menos de 16 elementos)
        sort(inventario.begin(), inventario.end(), [](const Item& a, const Item& b) {
          int ra = ordenarRareza(a.getRareza());
          int rb = ordenarRareza(b.getRareza());

          if (ra == rb) {
            return a.getId() < b.getId();
          }
          return ra < rb;
        });
        imprimirInventario(inventario);
      }
      else if (op == 6) {
          string nombre;
          cout << "Introduce el nombre exacto del item: ";
          cin >> nombre;
          buscarItem(inventario, nombre);
      }
      else if (op == 7) {
          verUltimoAgregado(historial);
      }
      else if (op == 8) {
            tomarPocion(pocionesRapidas, inventario);
        }
      else if (op == 9) {
          cout << "Adios!\n";
          continuar = false;
      }
      else{
          cout<<"La opcion no es valida"<<endl;
      }
  }
}

int main(){
  vector<Item> inventario = {
    Item(1001, "Espada_de_Hierro", "Comun", "Arma"),
    Item(1026, "Armadura_de_Hierro", "Rara", "Armadura"),
    Item(1049, "Pocion_HP_Basica", "Comun", "Pocion")
  };

  stack<Item> historial;
  stack<Item> pocionesRapidas;

  for (auto& item : inventario) {
        if (item.getTipo() == "Pocion") pocionesRapidas.push(item);
    }

  eleccion(inventario, historial, pocionesRapidas);

  return 0;
}