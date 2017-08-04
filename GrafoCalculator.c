#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Ejercicio n°10
Desarrollar un algoritmo y luego codificarlo en C que permite mostrar el número de
vértices y aristas que tiene un grafo utilizando la matriz de adyacencia.

Ejercicio no11
Desarrollar un algoritmo y luego codificarlo en C que permite mostrar el grado de
cada vértice de un grafo utilizando la matriz de adyacencia.

Ejercicio no12
Desarrollar un algoritmo y luego codificarlo en C que permite consultar si entre dos
vértices existe una arista de un grafo utilizando la matriz de incidencia.

Ejercicio no13
Desarrollar un algoritmo y luego codificarlo en C que dado un grafo dirigido A calcule
la transpuesta de la matriz de adyacencia de A. ¿Qué información nos brinda la matriz
transpuesta?

Ejercicio no14
Desarrollar un algoritmo y luego codificarlo en C que dada la matriz de incidencia de
un grafo A, calcule A.At

.¿Que representan los elementos de esa matriz producto?
*/

int mostrarMenu();
int menu();
int crearMatrizAdyacencia(int matrizAdyacencia[10][10],int vertices);
void crearMatrizIncidencia(int matrizAdyacencia[10][10],int vertices,int aristas);
void dibujarMatrizAdyacencia(int matrizAdyacencia[10][10],int vertices);
void generarMatriz(int matrizAdyacencia[10][10]);
void mostrarGradoDeVertice(int matrizAdyacencia[10][10],int vertices);
void calcularPorAdyacencia(int matrizAdyacencia[10][10],int vertices);
void calcularPorIncidencia(int matrizAdyacencia[10][10],int vertices,int aristas);

int main()
{
	int matrizAdyacencia[10][10];
    int matrizIncidencia[10][10];

	int vertices = -1;
	int aristas = -1;
	int opcion = 0;
    int valencia = 0;

	while(opcion < 1 || opcion > 5)
	{

		opcion = menu();

		switch (opcion){

            case 1 :
                while(vertices < 1 || vertices > 10 )
                {
                    printf("Ingrese un valor entre 1 y 10 los vertices: " );
                    scanf("%i", &vertices);
                };

                aristas = crearMatrizAdyacencia(matrizAdyacencia,vertices);
                printf(" \n" );
                printf( "%i vertices elegidos, creando matriz ingrese los grados\n", vertices);
                dibujarMatrizAdyacencia(matrizAdyacencia,vertices);
                printf("  Numero de vertices: %d \n", vertices);
                printf("  Numero de aristas: %d \n", aristas);
                printf("  Valencia total: %d \n", aristas*2);
                mostrarGradoDeVertice(matrizAdyacencia, vertices);

                break;

            case 2 :
                while(vertices < 1 || vertices > 10 )
                {
                    printf("Ingrese un valor entre 1 y 10 los vertices: " );
                    scanf("%i", &vertices);
                };
                while(aristas < 0)
                {
                    printf("ingrese un entero mayor o igual a 0 para las aristas: " );
                    scanf("%d", &aristas);
                };
                crearMatrizIncidencia(matrizAdyacencia,vertices,vertices);
                break;

            case 3 :
                while(vertices < 1 || vertices > 10 )
                {
                    printf("Ingrese un valor entre 1 y 10 los vertices: " );
                    scanf("%i", &vertices);
                };
                break;

            case 4 :
                printf(" \n" );
                printf("Generando grafo con valores aleatorios \n" );
                generarMatriz(matrizAdyacencia);
                printf(" \n" );
                break;

            case 5 :
                printf(" \n" );
                printf("Saliendo del menu \n" );
                printf(" \n" );
                break;
            default:
                break;

        }
	}
	getchar();
	return 0;
}

int crearMatrizAdyacencia(int matrizAdyacencia[10][10], int vertice)
{
	int i, j;
	int aristas = 0;
	for(i = 0; i < vertice; i++)
	{
		for(j = i; j < vertice; j++)
		{
			printf("ingrese el numero de caminos entre el vertice %d y el vertice %d\n", i,j );
			matrizAdyacencia[i][j] = -1;
			while(matrizAdyacencia[i][j] < 0)
			{
				printf("ingrese un entero positivo: " );
				scanf("%i", &matrizAdyacencia[i][j]);
				matrizAdyacencia[j][i] = matrizAdyacencia[i][j];
				aristas = aristas + matrizAdyacencia[i][j];
			};
		}
	}
    return aristas;
}

void dibujarMatrizAdyacencia(int matriz[10][10], int vertices)
{
	int i, j;
	printf("Dibujando la matriz: \n");
    printf("\n");
	for(i = 0; i < vertices ;i++)
	{
        printf("  ");
		for(j = 0; j < vertices; j++)
		{
            printf(" %i", matriz[i][j]);
		}
        printf("\n");
        printf("\n");
	}
    printf("\n");
}

int menu()
{
		int opcion = 0;
		while(opcion < 1 || opcion > 5)
		{
            printf("  -------------- MENU --------------  \n");
            printf("  1. Crear la matriz de adyacencia \n");
            printf("  2. Crear la matriz de incidencia \n");
            printf("  3. Crear la matriz de adyacencia y de incidencia \n");
            printf("  4. Generar grafo automaticamente    \n");
            printf("  5. Salir                            \n");
            printf("  ----------------------------------  \n");
            printf("  Seleccione una opcion [1 - 5]:      ");
            scanf("%i",&opcion);
		}

		return opcion;

}
void calcularPorAdyacencia(int matrizAdyacencia[10][10],int vertices)
{


};
void calcularPorIncidencia(int matrizAdyacencia[10][10],int vertices,int aristas){};
void crearMatrizIncidencia(int matrizAdyacencia[10][10],int vertices,int aristas){};
void generarMatriz(int matrizAdyacencia[10][10])
{
    srand(time(NULL));
    int vertices = (rand() % (10 - 1)) + 1;
 	int i = 0,j,aristas = 0;

	for(i; i < vertices; i++)
	{
		for(j = i; j < vertices; j++)
		{
		    matrizAdyacencia[i][j] = (rand() % (3 - 0)) + 0;
			printf("generado el numero de caminos entre el vertice %d y el vertice %d: %d\n", i,j,matrizAdyacencia[i][j] );
            matrizAdyacencia[j][i] = matrizAdyacencia[i][j];
            aristas = aristas + matrizAdyacencia[i][j];

		}
	}
    dibujarMatrizAdyacencia(matrizAdyacencia, vertices);
    printf("  Numero de vertices: %d \n", vertices);
    printf("  Numero de aristas: %d \n", aristas);
    printf("  Valencia total: %d \n", aristas*2);

    mostrarGradoDeVertice(matrizAdyacencia, vertices);
}
void mostrarGradoDeVertice(int matrizAdyacencia[10][10],int vertices)
{
    int max = 0;
    int vertMax = 1;
    int sum = 0;
    int i = 0,j;

    for(i; i < vertices; i++)
	{
		for(j = i; j < vertices; j++)
		{
          sum += matrizAdyacencia[i][j];
		}

		printf("  La valencia del vertice %d: %d \n", i+1,sum);
		if(sum > max){
            vertMax = i + 1;
            max = sum;
		}
		sum = 0;
	}
    printf("  El vertice con mayor grado es %d con %d \n", vertMax,max);
}

