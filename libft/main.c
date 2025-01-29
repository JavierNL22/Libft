/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:51:34 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/14 18:08:10 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"

// Función para ejecutar pruebas en un proceso hijo
void run_test(void (*test_function)(void)) {
    pid_t pid = fork(); // Crear un proceso hijo
    if (pid == 0) {
        // Código del proceso hijo: ejecuta la prueba
        test_function();
        exit(0); // Salir del proceso hijo si la prueba es exitosa
    } else if (pid > 0) {
        // Código del proceso padre: esperar al hijo
        int status;
        waitpid(pid, &status, 0); // Esperar a que termine el hijo

        if (WIFSIGNALED(status)) {
            int signal = WTERMSIG(status);
            printf("Error: La función provocó un fallo (signal %d: %s).\n", signal, strsignal(signal));
        } else if (WIFEXITED(status)) {
            printf("Prueba completada correctamente.\n");
        }
    } else {
        // Si fork falla
        perror("Error al crear el proceso hijo");
    }
}

// Prueba para ft_strlen
void test_ft_strlen() {
    char input[256];
    printf("Introduce una cadena: ");
    scanf(" %[^\n]", input);

    // Comparar resultados
    size_t original = strlen(input);
    size_t custom = ft_strlen(input);
    printf("Resultado de strlen: %zu\n", original);
    printf("Resultado de ft_strlen: %zu\n", custom);
}

// Prueba para ft_strncmp
void test_ft_strncmp() {
    char str1[256], str2[256];
    int n;
    printf("Introduce la primera cadena: ");
    scanf(" %[^\n]", str1);
    printf("Introduce la segunda cadena: ");
    scanf(" %[^\n]", str2);
    printf("Introduce el número de caracteres a comparar: ");
    scanf("%d", &n);

    // Comparar resultados
    int original = strncmp(str1, str2, n);
    int custom = ft_strncmp(str1, str2, n);
    printf("Resultado de strncmp: %d\n", original);
    printf("Resultado de ft_strncmp: %d\n", custom);
}

void test_ft_memset() {
    char str1[256];
    int c;
    int n;
    printf("Introduce cadena a modificar: ");
    scanf(" %[^\n]", str1);
    printf("Introduce el caracter: ");
    scanf("%d", &c);
    printf("Introduce el número de caracteres a cambiar: ");
    scanf("%d", &n);

    // Comparar resultados
    char *original = (char *) memset(str1, c, n);
    char *custom = (char *) ft_memset(str1, c, n);
    printf("Resultado de memset: %s\n", original);
    printf("Resultado de ft_memset: %s\n", custom);
}

void test_ft_bzero() {
    char str1[256];
    int n;
    printf("Introduce cadena a modificar: ");
    scanf(" %[^\n]", str1);
    printf("Introduce el número de caracteres a poner a 0: ");
    scanf("%d", &n);

    bzero(str1, n);
    ft_bzero(str1, n);
    // Comparar resultados
    printf("Resultado de bzero: %s\n", str1);
    printf("Resultado de ft_bzero: %s\n", str1);
}

// Menú principal
int main() {
    int opcion;

    while (1) {
        printf("\n*** Libft Tester ***\n");
        printf("1. Probar ft_strlen\n");
        printf("2. Probar ft_strncmp\n");
        printf("3. Probar ft_memset\n");
        printf("4. Probar ft_bzero\n");
        printf("5. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("\n[Prueba: ft_strlen]\n");
            run_test(test_ft_strlen); // Ejecutar prueba en un proceso hijo
            break;
        case 2:
            printf("\n[Prueba: ft_strncmp]\n");
            run_test(test_ft_strncmp); // Ejecutar prueba en un proceso hijo
            break;
        case 3:
            printf("\n[Prueba: ft_memset]\n");
            run_test(test_ft_memset); // Ejecutar prueba en un proceso hijo
            break;
        case 4:
            printf("\n[Prueba: ft_bzero]\n");
            run_test(test_ft_bzero); // Ejecutar prueba en un proceso hijo
            break;
        case 5:
            printf("Saliendo del tester.\n");
            return 0;
        default:
            printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    }
}
