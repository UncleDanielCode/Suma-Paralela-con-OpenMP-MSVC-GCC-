#include <cstdio>
#include <cstdlib>
#include <omp.h>

int main(int argc, char* argv[]) {
    // 1) Determinar cuántos hilos usar
    int threads = omp_get_max_threads();
    if (argc > 1) {
        int r = std::atoi(argv[1]);
        if (r > 0) threads = r;
    }
    omp_set_num_threads(threads);

    // 2) Tamaño del arreglo
    const int N = 100000000;

    // 3) Reserva de memoria (cast necesario en C++)
    int* A = static_cast<int*>(std::malloc(N * sizeof(int)));
    if (!A) {
        std::fprintf(stderr, "Error: memoria insuficiente\n");
        return 1;
    }

    // 4) Inicialización
    for (int j = 0; j < N; ++j) {
        A[j] = 1;
    }

    // 5) Suma en paralelo
    long long sum = 0;
    double t0 = omp_get_wtime();
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i) {
        sum += A[i];
    }
    double t1 = omp_get_wtime();

    // 6) Mostrar resultados
    std::printf("Hilos: %d   Suma = %lld   Tiempo = %.6f s\n",
        threads, sum, t1 - t0);

    std::free(A);
    return 0;
}
