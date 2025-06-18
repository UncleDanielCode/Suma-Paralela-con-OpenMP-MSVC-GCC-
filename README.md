````markdown
# Suma Paralela con OpenMP (MSVC & GCC)

Este proyecto implementa la suma de un arreglo de 100 000 000 de enteros de manera paralela usando OpenMP. Permite medir el **speedup**, la **eficiencia** y analizar la escalabilidad de una sección de código en función del número de hilos.

---

## Contenido del repositorio

- `suma_openmp_msvc.cpp`  
  Código C++ para Windows/Visual Studio (MSVC + OpenMP).

- `suma_openmp.c` *(opcional)*  
  Versión en C para GCC/Clang (Linux / WSL).

- `README.md`  
  Este documento.

---

## Requisitos

- **Windows + MSVC**  
  - Visual Studio 2019/2022 con “Desktop development with C++” y soporte OpenMP.
- **Linux/WSL**  
  - GCC o Clang con soporte OpenMP (`gcc`, `g++`, `libomp-dev`).

---

## Compilación

### MSVC (Windows)

1. Abra **Developer Command Prompt for VS** o **Developer PowerShell for VS**.  
2. Sitúese en el directorio del proyecto:
   ```bat
   cd C:\Proyectos\COpenMP
````

3. Compile con:

   ```bat
   cl /EHsc /openmp suma_openmp_msvc.cpp
   ```
4. Obtendrá `suma_openmp_msvc.exe`.

### GCC (Linux / WSL)

1. Abra su terminal de Linux o WSL.
2. Instale las dependencias:

   ```bash
   sudo apt update
   sudo apt install build-essential libomp-dev
   ```
3. Sitúese en el directorio del proyecto:

   ```bash
   cd /mnt/c/Proyectos/COpenMP
   ```
4. Compile con:

   ```bash
   g++ -std=c++11 -fopenmp suma_openmp.c -o suma_openmp
   ```
5. Obtendrá `suma_openmp`.

---

## Uso

Ejecute el programa indicando (opcionalmente) el número de hilos:

```bash
# MSVC
suma_openmp_msvc.exe [num_hilos]

# GCC
./suma_openmp [num_hilos]
```

* Si no se pasa `[num_hilos]`, el programa usa tantos hilos como núcleos detecte.
* Ejemplo:

  ```bash
  .\suma_openmp_msvc.exe    # usa todos los hilos
  .\suma_openmp_msvc.exe 4  # fuerza 4 hilos
  ```

La salida es:

```
Hilos: p   Suma = 100000000   Tiempo = Tp s
```

---

## Medición de métricas

1. Ejecute con **1, 2, 4, 8, 16** hilos y anote cada `Tp`.
2. Calcule:

   * **Speedup** $S(p) = T(1) / T(p)$
   * **Eficiencia** $E(p) = S(p) / p$
3. Trace gráficos de Speedup y Eficiencia vs. hilos.
4. Compare con la **Ley de Amdahl**:

   $$
     S_{\mathrm{Amdahl}}(p) \;=\; \frac{1}{(1 - f) + \frac{f}{p}}
   $$

   usando la fracción paralelizable $f$.

---

## Estructura del informe

En su informe PDF debe incluir:

* Descripción del algoritmo y directivas OpenMP.
* Tabla de tiempos, speedup y eficiencia.
* Gráficos de rendimiento.
* Aplicación de la Ley de Amdahl y comparación.
* Conclusiones.
* Enlace al repositorio y enlace al video de presentación.


```
