#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using namespace std;

struct tienda
{
	char nombre[100];
	int numero;
	char genero[100];
	char clasificacion[100];
	char descripcion[1000];
	string consola;
	int precio;
	int preciot;
 };
int main()
{
	tienda alta[8];
	int menu, decision1;


	//MENU DE OPCIONES
	do
	{
		printf("\t ***MENU DE OPCIONES***  \n");
		printf("1.-Alta de articulos   \n");
		printf("2.-Modificacion de articulos   \n");
		printf("3-Baja de articulos   \n");
		printf("4.-Lista de articulos   \n");
		printf("5.-Limpiar Pantalla   \n");
		printf("6.-Salir   \n");
		cin >> menu;

		switch (menu)
		{
		case 1: //ALTA DE ARTICULOS
			for (int i = 0; i < 3; i++)
			{
				printf("   \n");
				printf("Alta de articulos \n");

				cin.ignore();
				printf("Ingrese el nombre del articulo: \n");
				gets_s(alta[i].nombre);

				printf("Numero del articulo \n");
				scanf_s("%d", &alta[i].numero);

				cin.ignore();
				printf("Genero del articulo \n");
				gets_s(alta[i].genero);

				cin.ignore();
				printf("Clasificacion del articulo \n");
				gets_s(alta[i].clasificacion);

				cin.ignore();
				printf("Descripcion del articulo \n");
				gets_s(alta[i].descripcion);

				printf("Tipo de consola del articulo \n");
				getline(cin, alta[i].consola);

				printf("Precio del articulo \n");
				scanf_s("%d", &alta[i].precio);

				//IMPUESTOS
				alta[i].preciot = (alta[i].precio + (alta[i].precio * 0.16));


				//cin.ignore();
			}
			//REGRESAR AL MENU

			cout << " " << endl;
			cout << "¿Desea agregar otro articulo?    1.-Si   2.-No " << endl;
			cin >> decision1;

			if (decision1 == 1)
			{
				return main();
			}

			else
			{
				exit(1);
			}
			break;


		case 2:
		{
			break;
		}

		case 3:
		{
			break;
		}

		case 4: //LISTA DE ARTICULOS


			for (int i = 0; i < 3; i++)
			{
				printf("NOMBRE: %s \n", alta[i].nombre);
				printf("NUMERO: %d \n", alta[i].numero);
				printf("GENERO: %s \n", alta[i].genero);
				printf("CLASIFICACION: %s \n", alta[i].clasificacion);
				printf("DESCRIPCION: %s \n", alta[i].descripcion);
				printf("CONSOLA: %s \n", alta[i].consola.c_str());
				printf("PRECIO: %d \n", alta[i].preciot);
			}
			break;



		case 5: //LIMPIAR PANTALLA
		{
			system("cls");
			break;
		}

		case 6: //SALIR
		{
			exit(1);
			break;
		}
		}
	}	
while (menu != 6);
	
}