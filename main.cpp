#include "Item.h"

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

void agregarItem(vector<Item>& inventario) {
  int id = rand() % 10000; 
  string nombre;
  int tipoNum, rarezaNum;
  string tipo, rareza;
  bool continuar = true;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Introduce el nombre del item: ";
  getline(cin, nombre);

  while (continuar) {
    cout << "1. Comun\n2. Rara\n3. Epica\n4. Legendaria\nIntroduce la rareza: ";
    cin >> rarezaNum;
    if (rarezaNum == 1) { rareza = "Comun"; continuar = false; }
    else if (rarezaNum == 2) { rareza = "Rara"; continuar = false; }
    else if (rarezaNum == 3) { rareza = "Epica"; continuar = false; }
    else if (rarezaNum == 4) { rareza = "Legendaria"; continuar = false; }
    else {
        cout << "Incorrecto, intente otra vez" << endl;
        continuar = true; // se mantiene en el bucle
    }
  }

  continuar = true;

  while (continuar) {
    cout << "1. Arma\n2. Armadura\n3. Pocion\nIntroduce el tipo: ";
    cin >> tipoNum;
    if (tipoNum == 1) { tipo = "Arma"; continuar = false; }
    else if (tipoNum == 2) { tipo = "Armadura"; continuar = false; }
    else if (tipoNum == 3) { tipo = "Pocion"; continuar = false; }
    else {
        cout << "Incorrecto, intente otra vez" << endl;
        continuar = true;
    }
  }

  

  inventario.push_back(Item(id, nombre, rareza, tipo));
  cout << "Item agregado correctamente.\n";
}

void imprimirInventario(vector<Item>& inventario){
  for (const auto& it : inventario) it.mostrarInventario();
}

void menu(){
  cout<<"1. Agregar objeto al inventario\n2. Ver inventario \n3. Ordenar por nombre\n4. Ordenar por tipo\n5. Ordenar por rareza\n6. Salir"<<endl;
}

void eleccion(vector<Item>& inventario){
  bool continuar=true;
  int op;
  int cal;
  while (continuar){
      menu();
      cout<<"Elije una opcion: ";
      cin>>op;
      if (op==1){
        agregarItem(inventario);  
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
      else if (op==6){
        cout<<"Adios"<<endl;
        continuar=false;
      }
      else{
          cout<<"La opcion no es valida"<<endl;
      }
  }
}


int main(){
  vector<Item> inventario = {
    Item(rand() % 10000, "Espada de Hierro", "Comun", "Arma"), Item(rand() % 10000, "Armadura de Hierro", "Comun", "Armadura"), Item(rand() % 10000, "Pocion HP Basica", "Comun", "Pocion"), 
    Item(rand() % 10000, "Espada Carmesi", "Rara", "Arma"), Item(rand() % 10000, "Manto del Susurro Sombrio", "Rara", "Armadura"), Item(rand() % 10000, "Elixir del Fenix", "Rara", "Pocion"),
    Item(rand() % 10000, "Excalibur", "Legendaria", "Arma"), Item(rand() % 10000, "Coraza de los Dioses", "Legendaria", "Armadura"), Item(rand() % 10000, "Pocion del Alma", "Legendaria", "Pocion")
  };

  eleccion(inventario);

  return 0;
}