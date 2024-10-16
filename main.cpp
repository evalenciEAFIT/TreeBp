
#include "ArbolBMas.h"

int main() {
    // Creamos un árbol B+ con máximo de 3 llaves por nodo
    ArbolBMas arbol(3);

    // Insertamos varias llaves
    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(5);
    arbol.insertar(6);
    arbol.insertar(12);
    arbol.insertar(30);
    arbol.insertar(7);
    arbol.insertar(17);

    // Buscamos llaves
    arbol.buscar(6);   // Llave encontrada
    arbol.buscar(15);  // Llave no encontrada

    // Recorremos el árbol y mostramos las llaves
    std::cout << "Recorrido del árbol B+: ";
    arbol.recorrer();
    std::cout << std::endl;

    // Mostramos el árbol B+ en una estructura jerárquica
    std::cout << "\nÁrbol B+ con estructura jerárquica:\n";
    arbol.mostrarArbol();

    return 0;
}
