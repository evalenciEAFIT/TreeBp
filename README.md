
# Árbol B+

## Descripción

Un Árbol B+ es una estructura de datos autoajustable que extiende el concepto de árbol B. En un árbol B+, todos los valores (claves) se almacenan en los nodos hoja y están ordenados de forma que permiten realizar búsquedas, inserciones, eliminaciones y recorridos de manera eficiente. A diferencia del árbol B, los nodos internos no almacenan copias de los valores, solo las claves que indican el rango de valores en los nodos hijos.

## Utilidad

Los árboles B+ se utilizan principalmente en bases de datos y sistemas de archivos. Son ideales para aplicaciones que requieren búsquedas rápidas y un acceso secuencial eficiente, ya que todos los valores están almacenados en los nodos hoja, lo que permite recorridos rápidos en orden.

## Funciones principales

### 1. Insertar

El algoritmo de inserción sigue estos pasos:
1. **Buscar el nodo hoja**: Se busca el nodo hoja en el que debe insertarse el valor.
2. **Insertar el valor**: Si el nodo hoja tiene espacio, se inserta el valor en el lugar adecuado.
3. **Dividir el nodo (si está lleno)**: Si el nodo está lleno después de insertar, se divide en dos, promoviendo una clave al nodo padre. Este proceso puede repetirse hacia arriba si los nodos padres también se llenan.

### 2. Buscar

Para buscar un valor:
1. **Comenzar desde la raíz**: Se comienza desde la raíz y se compara el valor con las claves en cada nodo.
2. **Desplazarse hacia abajo**: Se sigue el camino correspondiente hasta llegar a un nodo hoja.
3. **Verificar la presencia del valor**: En el nodo hoja, se verifica si el valor está presente.

### 3. Recorrer

El recorrido de un árbol B+ se realiza en orden ascendente. Esto es posible ya que todos los valores se almacenan en los nodos hoja y están conectados entre sí. El recorrido comienza en la primera hoja y continúa hasta la última.

## Algoritmos

### Algoritmo de inserción
```plaintext
Insertar(valor):
    Si el árbol está vacío:
        Crear un nodo hoja y agregar el valor
    Si la raíz está llena:
        Dividir la raíz en dos nodos y promover una clave al nuevo nodo raíz
    Encontrar el nodo hoja adecuado para el valor
    Insertar el valor en el nodo hoja
    Si el nodo hoja está lleno:
        Dividir el nodo hoja en dos y promover una clave al nodo padre
```

### Algoritmo de búsqueda
```plaintext
Buscar(valor):
    Comenzar desde la raíz
    Mientras no lleguemos a un nodo hoja:
        Comparar el valor con las claves del nodo actual
        Desplazarse al nodo hijo correspondiente
    Si el valor está en el nodo hoja, devolverlo; de lo contrario, devolver que no se encontró
```

### Algoritmo de recorrido
```plaintext
Recorrer():
    Comenzar desde la primera hoja (la más a la izquierda)
    Mientras haya nodos hoja:
        Imprimir los valores en el nodo actual
        Desplazarse al siguiente nodo hoja
```

## Estructura de archivos

- **ArbolBMas.h**: Contiene la implementación del árbol B+ (inserción, búsqueda, recorrido).
- **main.cpp**: Contiene la función principal que usa el árbol B+ para realizar operaciones de ejemplo.
- **Makefile**: Archivo para compilar el proyecto.
- **README.md**: Este archivo con la descripción del proyecto y su uso.

## Compilación y ejecución

Para compilar el programa, ejecuta:
```bash
make
```

Para ejecutarlo:
```bash
make run
```

Para limpiar los archivos generados:
```bash
make clean
```

## Ejemplo de salida

```plaintext
Recorrido del árbol B+: 5 6 7 10 12 17 20 30 

Árbol B+ con estructura jerárquica:
└── Nodo: 10 , 20
    ├── Nodo: 5 , 6 , 7
    └── Nodo: 12 , 17 , 30
```
