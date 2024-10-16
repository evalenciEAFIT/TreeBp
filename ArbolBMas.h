
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Clase que representa un nodo en el árbol B+
class NodoBMas {
public:
    bool esHoja; // Indica si el nodo es una hoja
    std::vector<int> llaves; // Contiene las llaves (valores) en el nodo
    std::vector<NodoBMas*> hijos; // Contiene los punteros a los hijos

    NodoBMas(bool esNodoHoja) : esHoja(esNodoHoja) {}
};

// Clase del árbol B+
class ArbolBMas {
    NodoBMas* raiz; // Puntero a la raíz del árbol B+
    int maxLlaves;  // Máximo número de llaves permitidas por nodo
public:
    ArbolBMas(int maxK) : raiz(nullptr), maxLlaves(maxK) {}

    // Inserta una llave en el árbol B+
    void insertar(int llave);

    // Busca una llave en el árbol B+
    void buscar(int llave);

    // Recorre el árbol y muestra las llaves
    void recorrer();

    // Muestra el árbol B+ de forma jerárquica
    void mostrarArbol();

private:
    // Inserta una llave en un nodo que no está lleno
    void insertarEnNoLleno(NodoBMas* nodo, int llave);

    // Divide un nodo cuando está lleno
    NodoBMas* dividirHijo(NodoBMas* nodo, int indice);

    // Función auxiliar para recorrer a partir de un nodo específico
    void recorrerNodo(NodoBMas* nodo);

    // Función auxiliar para mostrar el árbol desde un nodo específico
    void mostrarArbolAux(NodoBMas* nodo, std::string prefix, bool esUltimo);
};
