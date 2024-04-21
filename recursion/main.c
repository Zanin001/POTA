#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int factorialIterative(int n) {
    long long int result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long int factorialRecursive(long long int n) {
    if (n == 0)
        return 1;
    return n * factorialRecursive(n - 1);
}

long long int fibonacciIterative(long long int n) {
    if (n <= 1)
        return n;
    long long int prev = 0, curr = 1;
    int i;
    for (i = 2; i <= n; i++) {
        long long int temp = curr;
        curr += prev;
        prev = temp;
    }
    return curr;
}

long long int fibonacciRecursive(long long int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

long long int sumIterative(long long int arr[], int size) {
    long long int sum = 0;
    int i;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

long long int sumRecursive(long long int arr[], int index) {
    if (index < 0)
        return 0;
    return arr[index] + sumRecursive(arr, index - 1);
}

int main() {
    int choice;
    int n; 
    long long int result;
    clock_t start, end;
    long long int cpu_time_used;
    int i;

    do
    {
      printf("Selecione a operacao:\n");
      printf("1. Fatorial Iterativo\n");
      printf("2. Fatorial Recursivo\n");
      printf("3. Fibonacci Iterativo\n");
      printf("4. Fibonacci Recursivo\n");
      printf("5. Soma de Elementos de um Array Iterativo\n");
      printf("6. Soma de Elementos de um Array Recursivo\n");
      printf("7. Sair\n");
      scanf("%d", &choice);

      switch (choice) {
          case 1:
              printf("Digite o valor de n para calcular o fatorial: ");
              scanf("%d", &n);
              start = clock();
              result = factorialIterative(n);
              end = clock();
              cpu_time_used = ((long long int) (end - start)) / CLOCKS_PER_SEC;
              printf("Resultado: %d\n", result);
              printf("Tempo de execucao: %f segundos\n", cpu_time_used);
              break;
          case 2:
              printf("Digite o valor de n para calcular o fatorial: ");
              scanf("%d", &n);
              start = clock();
              result = factorialRecursive(n);
              end = clock();
              cpu_time_used = ((long long int) (end - start)) / CLOCKS_PER_SEC;
              printf("Resultado: %d\n", result);
              printf("Tempo de execucao: %f segundos\n", cpu_time_used);
              break;
          case 3:
              printf("Digite o valor de n para calcular o n-esimo termo da sequencia de Fibonacci: ");
              scanf("%d", &n);
              start = clock();
              result = fibonacciIterative(n);
              end = clock();
              cpu_time_used = ((long long int) (end - start)) / CLOCKS_PER_SEC;
              printf("Resultado: %d\n", result);
              printf("Tempo de execucao: %f segundos\n", cpu_time_used);
              break;
          case 4:
              printf("Digite o valor de n para calcular o n-esimo termo da sequencia de Fibonacci: ");
              scanf("%d", &n);
              start = clock();
              result = fibonacciRecursive(n);
              end = clock();
              cpu_time_used = ((long long int) (end - start)) / CLOCKS_PER_SEC;
              printf("Resultado: %d\n", result);
              printf("Tempo de execucao: %f segundos\n", cpu_time_used);
              break;
          case 5:
              printf("Digite o tamanho do array: ");
              scanf("%d", &n);
              long long int arr[n];
              printf("Digite os elementos do array:\n");
              for (i = 0; i < n; i++) {
                  scanf("%d", &arr[i]);
              }
              start = clock();
              result = sumIterative(arr, n);
              end = clock();
              cpu_time_used = ((long long int) (end - start)) / CLOCKS_PER_SEC;
              printf("Resultado: %d\n", result);
              printf("Tempo de execucao: %f segundos\n", cpu_time_used);
              break;
          case 6:
              printf("Digite o tamanho do array: ");
              scanf("%d", &n);
              long long int arr2[n];
              printf("Digite os elementos do array:\n");
              for (i = 0; i < n; i++) {
                  scanf("%d", &arr2[i]);
              }
              start = clock();
              result = sumRecursive(arr2, n - 1);
              end = clock();
              cpu_time_used = ((long long int) (end - start)) / CLOCKS_PER_SEC;
              printf("Resultado: %d\n", result);
              printf("Tempo de execucao: %f segundos\n", cpu_time_used);
              break;
          default:
              printf("Opcao invalida.\n");
              break;
      }
    } while (choice != 7);

    return 0;
}
