#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
//declaracion de variables

struct tienda
{
	string nombre;
	int numero;
	char genero[100];
	string clasificacion;
	string descripcion;
	string consola, status;
	int precio;
	int preciot;
};
int contador, alta;
int decision1;
tienda* registro; // uso de punteros
//funciones con void
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();

int main()
{
	int opc;
	cout << "\t ***MENU DE OPCIONES***  \n" << endl;
	cout << "1.-Alta de articulos   \n" << endl;
	cout << "2.-Modificacion de articulos   \n" << endl;
	cout << "3.-Baja de articulos   \n" << endl;
	cout << "4.-Lista de articulos   \n" << endl;
	cout << "5.-Limpiar Pantalla   \n" << endl;
	cout << "6.-Salir   \n" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		modificar();
		return main();
		break;


	case 3:
		eliminar();
		return main();
		break;


	case 4:
		listas();
		return main();
		break;

	case 5:
		system("cls"); //system("clear");
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}
void Alta() // Da de alta los articulos que queremos ingresar
{
	cout << "¿cuantos productos desea dar de alta? \n";
	cin >> alta;
	registro = new tienda[alta]; // uso de new para hacer el arreglo dinamico
	for (int i = 0; i < alta; i++)
	{
		cout << "   \n" << endl;
		cout << "Alta de articulos \n" << endl;
		cin.ignore();
		cout << "Ingrese el nombre del articulo: \n";
		getline(cin, registro[i].nombre);
		cout << "Numero del articulo \n";
		cin >> registro[i].numero;
		cin.ignore();
		cout << "Genero del articulo \n";
		gets_s(registro[i].genero);
		cin.ignore();
		cout << "Clasificacion del articulo \n";
		getline(cin, registro[i].clasificacion);
		cin.ignore();
		cout << "Descripcion del articulo \n";
		getline(cin, registro[i].descripcion);
		cout << "Tipo de consola del articulo \n";
		getline(cin, registro[i].consola);
		cout << "Precio del articulo \n";
		cin >> registro[i].precio;
		//IMPUESTOS
		registro[i].preciot = (registro[i].precio + (registro[i].precio * 0.16));
		//cin.ignore();
	}
	//REGRESAR AL MENU

	cout << " " << endl;
	cout << "¿Desea agregar otro articulo?	(1.-Si   2.-No) " << endl;
	cin >> decision1;

	if (decision1 == 1)
	{
		return;
	}

	else
	{
		return;
	}

}

void listas() // Imprime una lista de los articulos que ya ingresamos
{
	for (int i = 0; i < alta; i++)
	{
		if (registro[i].status == "ELIMINADO")
		{
			cout << "REGISTRO ELIMINADO" << i + 1 << endl;
		}
		else
		{
			cout << " registro" << i + 1 << endl;
			cout << registro[i].nombre << endl;
			cout << registro[i].numero << endl;
			cout << registro[i].genero << endl;
			cout << registro[i].clasificacion << endl;
			cout << registro[i].descripcion << endl;
			cout << registro[i].consola << endl;
			cout << registro[i].preciot << endl;
		}
	}
}
void eliminar() // Elimina los articulos que ya no necesitamos y aparece un mensaje donde ya esta eliminado
{
	int j;
	cout << "ingrese el  registro a eliminar " << endl;
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		cout << "Eliminando registro" << j + 1 << endl;
		registro[i].status = "ELIMINADO";
	}
}
void modificar() // Modifica los aspectos del articulo y nos pregunta cual queremos en especifico modificar
{
	int j, opcion, op2;
	do
	{
		cout << "ingrese el numero registro a modificar" << endl;
		cin >> j;
		j = j - 1; // esto debido a que i inicia en 0

		for (int i = j; i == j; i++)
		{
			if ((registro[i].status == "ELIMINADO"))
			{
				cout << "REGISTRO ELIMINADO" << i + 1 << endl;
				cout << "ingrese un registro valido \n" << endl;
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	cout << "ingrese que desea modificar 1.-Nombre, 2.-Numero, 3.- Genero. 4.-Clasificacion, 5.-Descripcion, 6.-Tipo de consola, 7.-Precio " << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el nombre" << endl;
			getline(cin, registro[i].nombre);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			//while (getchar() != '\n'); //se vacia el buffer o el espacio
			cout << "Ingrese el numero" << endl;
			cin >> registro[i].numero;
		}
		break;
	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el genero" << endl;
			gets_s(registro[i].genero);
		}
		break;

	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el la clasificacion" << endl;
			getline(cin, registro[i].clasificacion);
		}
		break;

	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese la descripcion" << endl;
			getline(cin, registro[i].descripcion);
		}
		break;

	case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el tipo de consola" << endl;
			getline(cin, registro[i].consola);
		}
		break;
	case 7:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese el precio sin IVA" << endl;
			cin >> registro[i].precio;
			registro[i].preciot = (registro[i].precio + (registro[i].precio * 0.16));
		}
	}


}

void archivos() // Crea el archivo y guarda el contenido y tambien nos termina la ejecucion del programa
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	string texto;
	string texto2;
	int texto3;

	nombrearchivo = "Videojuegosymas.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	archivo << "NOMBRE" << "\t";
	archivo << "NUMERO" << "\t";
	archivo << "GENERO" << "\t";
	archivo << "CLASIFICACION" << "\t";
	archivo << "DESCRIPCION" << "\t";
	archivo << "TIPO DE CONSOLA" << "\t";
	archivo << "PRECIO" << "\t";
	archivo << "STATUS" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (registro[i].status == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			texto = registro[i].nombre;
			archivo << texto << "\t" << "\t";
			texto3 = registro[i].numero;
			archivo << texto3 << "\t" << "\t";
			texto = registro[i].genero;
			archivo << texto << "\t " << "\t";
			texto = registro[i].clasificacion;
			archivo << texto << "\t " << "\t";
			texto = registro[i].descripcion;
			archivo << texto << "\t " << "\t";
			texto = registro[i].consola;
			archivo << texto << "\t " << "\t";
			texto3 = registro[i].preciot;
			archivo << texto3 << "\t " << "\n";
		}
	}


	archivo.close();
}