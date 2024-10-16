#include "ArbolBMas.h"

// Implementación de las funciones de la clase ArbolBMas

void ArbolBMas::insertar(int llave) {
    if (!raiz) {
        raiz = new NodoBMas(true);
        raiz->llaves.push_back(llave);
    } else {
        if (raiz->llaves.size() == (size_t)maxLlaves) {
            NodoBMas* nuevaRaiz = new NodoBMas(false);
            nuevaRaiz->hijos.push_back(raiz);
            NodoBMas* hijo = dividirHijo(nuevaRaiz, 0);
            nuevaRaiz->hijos.push_back(hijo);
            raiz = nuevaRaiz;
        }
        insertarEnNoLleno(raiz, llave);
    }
}

void ArbolBMas::insertarEnNoLleno(NodoBMas* nodo, int llave) {
    if (nodo->esHoja) {
        nodo->llaves.push_back(llave);
        std::sort(nodo->llaves.begin(), nodo->llaves.end());
    } else {
        size_t i = 0;
        while (i < nodo->llaves.size() && llave > nodo->llaves[i]) {
            i++;
        }
        if (nodo->hijos[i]->llaves.size() == (size_t)maxLlaves) {
            NodoBMas* hijo = dividirHijo(nodo, i);
            nodo->hijos.insert(nodo->hijos.begin() + i + 1, hijo);
            if (llave > nodo->llaves[i]) i++;
        }
        insertarEnNoLleno(nodo->hijos[i], llave);
    }
}

NodoBMas* ArbolBMas::dividirHijo(NodoBMas* nodo, int indice) {
    NodoBMas* hijo = nodo->hijos[indice];
    NodoBMas* nuevoNodo = new NodoBMas(hijo->esHoja);

    int mitad = maxLlaves / 2;
    nodo->llaves.insert(nodo->llaves.begin() + indice, hijo->llaves[mitad]);

    nuevoNodo->llaves.assign(hijo->llaves.begin() + mitad + 1, hijo->llaves.end());
    hijo->llaves.resize(mitad);

    if (!hijo->esHoja) {
        nuevoNodo->hijos.assign(hijo->hijos.begin() + mitad + 1, hijo->hijos.end());
        hijo->hijos.resize(mitad + 1);
    }
    return nuevoNodo;
}

void ArbolBMas::buscar(int llave) {
    NodoBMas* nodo = raiz;
    while (nodo) {
        size_t i = 0;
        while (i < nodo->llaves.size() && llave > nodo->llaves[i]) i++;
        if (i < nodo->llaves.size() && llave == nodo->llaves[i]) {
            std::cout << "Llave " << llave << " encontrada\n";
            return;
        }
        nodo = (nodo->esHoja) ? nullptr : nodo->hijos[i];
    }
    std::cout << "Llave " << llave << " no encontrada\n";
}

void ArbolBMas::recorrer() {
    recorrerNodo(raiz);
}

void ArbolBMas::recorrerNodo(NodoBMas* nodo) {
    if (!nodo) return;
    for (size_t i = 0; i < nodo->llaves.size(); i++) {
        if (!nodo->esHoja) recorrerNodo(nodo->hijos[i]);
        std::cout << nodo->llaves[i] << " ";
    }
    if (!nodo->esHoja) recorrerNodo(nodo->hijos.back());
}

void ArbolBMas::mostrarArbol() {
    mostrarArbolAux(raiz, "", true);
}

void ArbolBMas::mostrarArbolAux(NodoBMas* nodo, std::string prefix, bool esUltimo) {
    if (!nodo) return;

    std::cout << prefix;
    std::cout << (esUltimo ? "└── " : "├── ");

    for (size_t i = 0; i < nodo->llaves.size(); i++) {
        std::cout << "Nodo: " << nodo->llaves[i];
        if (i != nodo->llaves.size() - 1) {
            std::cout << " , ";
        }
    }
    std::cout << std::endl;

    prefix += (esUltimo ? "    " : "|   ");
    for (size_t i = 0; i < nodo->hijos.size(); i++) {
        mostrarArbolAux(nodo->hijos[i], prefix, i == nodo->hijos.size() - 1);
    }
}
