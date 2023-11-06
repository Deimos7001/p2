#include <stdio.h>
#include <string.h>
#include <omp.h>

//INF-317 - 1ER EXAMEN PARCIAL
//NOMBRE: VICTOR GABRIEL CAPIA ALI
//CI: 4762494 LP
//PREGUNTA 2. Mediante OpenMP realice la división de una frase en dos, por ejemplo “tres tristes tigres trigaban trigo por culpa del bolivar”; la división seria “tres tigres trigo culpa bolivar” y “tristes trigaban por del”.

int main() {
    // Definimos la frase original
    char frase[] = "tres tristes tigres trigaban trigo por culpa del bolivar";
    
    // Definimos las vectores para las dos frases resultantes
    char frase1[100] = "";
    char frase2[100] = "";

    // Definimos un arreglo para almacenar las palabras
    char* palabras[20];
    int num_palabras = 0;

    // Tokenizar la frase original
    char* token = strtok(frase, " ");
    while (token != NULL) {
        palabras[num_palabras] = token; // Almacena la palabra en el arreglo
        num_palabras++; // Incrementa el contador de palabras
        token = strtok(NULL, " "); // Obtiene la siguiente palabra
    }

    // Dividir las palabras entre las dos frases usando OpenMP
    #pragma omp parallel for
    for (int i = 0; i < num_palabras; i++) {
        if (i % 2 == 0) {
            // Palabras con índices pares en la primera frase
            strcat(frase1, palabras[i]); // Agrega la palabra a la primera frase
            strcat(frase1, " "); // Agrega un espacio después de la palabra
        } else {
            // Palabras con índices impares en la segunda frase
            strcat(frase2, palabras[i]); // Agrega la palabra a la segunda frase
            strcat(frase2, " "); // Agrega un espacio después de la palabra
        }
    }

    // Imprime las dos frases resultantes
    printf("Frase 1: %s\n", frase1);
    printf("Frase 2: %s\n", frase2);

    return 0;
}

