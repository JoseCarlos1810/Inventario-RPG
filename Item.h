
#ifndef ITEM_H
#define ITEM_H
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;


class Item{
    private:
        int id;
        string nombre;
        string rareza;
        string tipo;

    public:
        Item(int _id, string _nombre, string _rareza, string _tipo){
            id = _id;
            nombre = _nombre;
            rareza = _rareza;
            tipo = _tipo;
        }
        int getId() const { return id; }
        string getNombre() const { return nombre; }
        string getRareza() const { return rareza; }
        string getTipo() const { return tipo; }
        void setId(int _id){ id = _id;}
        void mostrarInventario() const {
            cout << "ID:" << id << "|" << nombre << "|" << rareza << "|" << tipo << endl;
        }
};



#endif