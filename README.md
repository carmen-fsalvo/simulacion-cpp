# Cálculo Numérico y Álgebra Lineal en C++

Este repositorio reúne algoritmos fundamentales de análisis numérico, resolución de ecuaciones diferenciales y métodos matriciales desarrollados en C++ en la Universidad Autónoma de Madrid (UAM)[cite: 2, 3, 6].

## Contenido del Repositorio

* **Álgebra Lineal y Sistemas Matriciales:**
  * Métodos directos e iterativos de resolución de sistemas lineales: Descomposición LU, Gauss-Seidel e iteración de Jacobi (`cmatrixLU.cpp`, `gauss_seidel.cpp`, `jacobidiagonalizacion.cpp`)[cite: 6].
  * Análisis de matrices con diagonal dominante y utilidades de lectura/procesamiento de matrices (`dominantediagonal.cpp`, `lectormatrizp3.cpp`)[cite: 6].

* **Cálculo de Raíces y Búsqueda Numérica:**
  * Algoritmos de búsqueda de ceros y optimización: Método de Bisección, Newton-Raphson y búsqueda de valores máximos (`biseccion1.cpp`, `mainnewtonraphson.cpp`, `buscarvalormax.cpp`)[cite: 6].

* **Integración y Diferenciación Numérica:**
  * Cuadratura numérica mediante Regla de Simpson y Cuadratura de Gauss (`simpson_vs_gauss.cpp`, `simpsontresoct_simple.cpp`)[cite: 6].
  * Derivación numérica y resolución de Ecuaciones Diferenciales Ordinarias (EDO) por diferencias finitas (`derivadaNum.cpp`, `EDO_dif_finitas.cpp`)[cite: 6].

## Requisitos
* Compilador C++ (soporte para Estándar C++11 o superior)
