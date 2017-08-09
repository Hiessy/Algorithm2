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

*/

int mostrarMenu();
int menu();
int crearMatrizAdyacencia(int matrizAdyacencia[10][10],int vertices);
void crearMatrizIncidencia(int matrizAdyacencia[10][10],int vertices,int aristas);
void dibujarMatriz(int matrizAdyacencia[10][10],int vertices, int aristas);
void generarMatriz(int matrizAdyacencia[10][10]);
void dibujarCabecera(int aristas);
void mostrarGradoDeVertice(int matrizAdyacencia[10][10],int vertices);
void calcularPorAdyacencia(int matrizAdyacencia[10][10],int vertices);
void calcularPorIncidencia(int matrizAdyacencia[10][10],int vertices,int aristas);
void consultarVertice(int matriz[10][10],int vertices);

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
                    printf("  Ingrese un valor entre 1 y 10 los vertices: " );
                    scanf("  %i", &vertices);
                };

                aristas = crearMatrizAdyacencia(matrizAdyacencia,vertices);
                printf(" \n" );
                printf("  %i vertices elegidos, creando matriz ingrese los grados\n", vertices);
                dibujarMatriz(matrizAdyacencia,vertices,vertices);
                printf("  Numero de vertices: %d \n", vertices);
                printf("  Numero de aristas: %d \n", aristas);
                printf("  Valencia total: %d \n", aristas*2);
                mostrarGradoDeVertice(matrizAdyacencia, vertices);

                break;

            case 2 :
                while(vertices < 1 || vertices > 10 )
                {
                    printf(  "  Ingrese un valor entre 1 y 10 para la cantidad de vertices: " );
                    scanf("  %i", &vertices);
                };
                while(aristas < 0)
                {
                    printf("  Ingrese un entero mayor o igual a 0 para la cantidad de aristas: " );
                    scanf("  %d", &aristas);
                };
                crearMatrizIncidencia(matrizIncidencia,vertices,aristas);
                break;

            case 3 :
                while(vertices < 1 || vertices > 10 )                {
                    printf("  Ingrese un valor entre 1 y 10 los vertices: " );
                    scanf("  %i", &vertices);
                };
                break;

            case 4 :
                printf(" \n" );
                printf("  Generando grafo con valores aleatorios \n" );
                generarMatriz(matrizAdyacencia);
                printf(" \n" );
                break;

            case 5 :
                printf(" \n" );
                printf("  Saliendo del menu \n" );
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
			printf("  Ingrese el numero de caminos entre el vertice %d y el vertice %d\n", i,j );
			matrizAdyacencia[i][j] = -1;
			while(matrizAdyacencia[i][j] < 0)
			{
				printf("  Ingrese un entero positivo: " );
				scanf("%i", &matrizAdyacencia[i][j]);
				matrizAdyacencia[j][i] = matrizAdyacencia[i][j];
				aristas = aristas + matrizAdyacencia[i][j];
			};
		}
	}
    return aristas;
}

void dibujarMatriz(int matriz[10][10], int vertices, int aristas)
{
	int i, j;
	printf("  Dibujando la matriz: \n");
    dibujarCabecera(aristas);

	for(i = 0; i < vertices ;i++)
	{
        printf(" %i |", i);
		for(j = 0; j < aristas; j++)
		{
            printf(" %i |", matriz[i][j]);
		}
        printf("\n");
        printf("  ");
        printf(" %.*s\n", (aristas*4+1), "==================================================================================");
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
void crearMatrizIncidencia(int matrizIncidencia[10][10],int vertices,int aristas)
{
    srand(time(NULL));
    int i, j, n;
    int conexion[vertices];
    int sum = 0;

	for(i = 0; i < vertices; i++)
	{
		for(j = 0; j < aristas; j++)
		{
		    matrizIncidencia[i][j] = 0;
		    if(i == 0){
                printf("\n");
                matrizIncidencia[i][j]=(rand() % 2);
		    }else if(i == vertices-1){
                sum = 0;
                for(n = i-1; n >= 0; n--){
                    sum += matrizIncidencia[n][j];
                }
		        if(sum == 1){
                    matrizIncidencia[i][j] = 1;
                }else {
                    matrizIncidencia[i][j] = 0;

                }

		    }else{
                matrizIncidencia[i][j]= (rand() % 2);
                if (matrizIncidencia[i][j] == 1){
                    sum = 0;
                    for(n = i-1; n >= 0; n--){
                        sum += matrizIncidencia[n][j];
                    }
                    if(sum == 2){
                        matrizIncidencia[i][j]=0;
                        printf("%d\n", matrizIncidencia[i][j]);
                    }
                }

		    }

		}

	}
    dibujarMatriz(matrizIncidencia, vertices, aristas);
    consultarVertice(matrizIncidencia, vertices);
};
void generarMatriz(int matrizAdyacencia[10][10])
{
    srand(time(NULL));
    int vertices = (rand() % (10 - 1)) + 1;
 	int i = 0,j,aristas = 0;

	for(i; i < vertices; i++)
	{
		for(j = i; j < vertices; j++)
		{
		    matrizAdyacencia[i][j] = (rand() % 4);
			printf("  Generado el numero de caminos entre el vertice %d y el vertice %d: %d\n", i,j,matrizAdyacencia[i][j] );
            matrizAdyacencia[j][i] = matrizAdyacencia[i][j];
            aristas = aristas + matrizAdyacencia[i][j];

		}
	}
    dibujarMatriz(matrizAdyacencia, vertices, vertices);
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
		for(j = 0; j < vertices; j++)
		{
        if( i == j){
            sum += matrizAdyacencia[i][j]*2;
        }else{
             sum += matrizAdyacencia[i][j];
        }

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

void dibujarCabecera(int aristas)
{
    int i = 0;
    printf(" \\  ");
    for(i; i < aristas; i++)
	{
	    printf(" %i  ", i);
	}
     printf("\n %.*s==\n", (aristas*4+1), "==================================================================================");
}

void consultarVertice(int matriz[10][10], int vertices)
{

    int vert1 = -1;
    int vert2 = -1;
    char opcion = 'z';
    printf("  Desea consultar si existe una arista entre dos vertices S/N: \n");

    while(opcion != 'S' && opcion != 'N' && opcion != 's' && opcion != 'n')
    {
        scanf("%c",&opcion);
    }
    fflush(stdin);
    if(opcion == 'S' || opcion == 's')
    {
        printf("  Ingrese el primer vertice (desde 0 hasta %d): \n", vertices-1);
        while(vert1 < 0 || vert1 > vertices-1 ){
            scanf("%i",&vert1);
        }

        printf("  Ingrese el segundo (desde 0 hasta %d): \n", vertices-1);
        while(vert2 < 0 || vert2 > vertices-1 ){
            scanf("%i",&vert2);
        }
    }

};
