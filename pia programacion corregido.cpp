#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <limits>
#include <cctype>
#include <stdlib.h>


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

using namespace std;

int main()
{
	int opc;
	do
	{
		
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

	} while (opc != 6);
	
	delete[ ] registro; // Liberando la memoria por si el usuario decide salir

	return 0;
}

void Alta() // Da de alta los articulos que queremos ingresar
{
	int i = 0, j = 0, k = 0, contador = 0, longitud = 0, misma_clave = 0;
	string copia_nombre;

	cout << "¿cuantos productos desea dar de alta? \n";
	cin >> alta;
	registro = new tienda[alta]; // uso de new para hacer el arreglo dinamico
	for (int i = 0; i < alta; i++)
	{
		cout << "   \n" << endl;
		cout << "Alta de articulos \n" << endl;
		cin.ignore();
		
		do
		{
			cout << "Ingrese el nombre del articulo: \n";
			fflush(stdin); // Vacia el buffer de entrada estandar
			getline(cin, registro[i].nombre);
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Para eliminar el salto de linea al final de la cadena de caracteres

			longitud = registro[i].nombre.length();
			copia_nombre = registro[i].nombre;

			if (longitud == 0)
			
				cout<<"LA CADENA NO DEBE ESTAR VACIA";
			
			else
			{
				j = 0;
				contador = 0;

				while (copia_nombre[j] != '\0')
				{
					if (isalpha(copia_nombre[j]) || copia_nombre[j] == 32)
					
						contador++;
					
					j++; // j = j + 1
				}
				
			}
			

		} while ((longitud != contador) || longitud == 0);
		

		do
		{

			if (i > 0)
			{
				cout << "Numero del articulo \n";
				fflush(stdin);
				cin >> registro[i].numero;

				misma_clave = 0;
				for ( k = 0; k < i; k++)
				{
					if (registro[i].numero == registro[k].numero)
					
						misma_clave = 1; // Verdadero, existe una clave similar
					
				}
			}
			else
			{
				cout << "Numero del articulo \n";
				fflush(stdin);
				cin >> registro[i].numero;
			}
			
		} while (registro[i].numero > 0 || misma_clave);
		
		cin.ignore();
		cout << "Genero del articulo \n";
		fflush(stdin);
		gets_s(registro[i].genero, 100);
		cin.ignore();
		cout << "Clasificacion del articulo \n";
		fflush(stdin);
		getline(cin, registro[i].clasificacion);
		cin.ignore();
		cout << "Descripcion del articulo \n";
		fflush(stdin);
		getline(cin, registro[i].descripcion);
		cout << "Tipo de consola del articulo \n";
		fflush(stdin);
		getline(cin, registro[i].consola);
		cout << "Precio del articulo \n";
		fflush(stdin);
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
	
		return;
	

	else
	
		return;
	

}

void listas() // Imprime una lista de los articulos que ya ingresamos
{
	int i = 0, dato = -1;
	string busqueda;
	int opcion;

	do
	{
		dato = -1;
		do
		{
			cout<<"Desea buscar las listas por"<<endl;
			cout<<"1. Genero"<<endl;
			cout<<"2. Clasificacion"<<endl;
			cout<<"3. Consola"<<endl;
			cout<<"4.Salir"<<endl;
			fflush(stdin);
			cin>>opcion;
		} while (opcion < 1 || opcion > 4);

		switch (opcion)
		{
			case 1:
			cout<<"Ingrese el genero el cual desea buscar: ";
			fflush(stdin);
			getline(cin, busqueda);

			for ( i = 0; i < alta; i++)
			{
				if (busqueda == registro[i].genero)
				{
					dato = i;
					break;
				}
				
			}

			if (dato == -1)
			{
				cout<<"No se pudo encontrar el articulo";
			}
			else
			{
				cout << " Registro" << dato << endl;
				cout << registro[dato].nombre << endl;
				cout << registro[dato].numero << endl;
				cout << registro[dato].genero << endl;
				cout << registro[dato].clasificacion << endl;
				cout << registro[dato].descripcion << endl;
				cout << registro[dato].consola << endl;
				cout << registro[dato].preciot << endl;
			}
			
			break;

			case 2:
				cout<<"Ingrese la clasificacion la cual desea buscar: ";
			fflush(stdin);
			getline(cin, busqueda);

			for ( i = 0; i < alta; i++)
			{
				if (busqueda == registro[i].clasificacion)
				{
					dato = i;
					break;
				}
				
			}

			if (dato == -1)
			{
				cout<<"No se pudo encontrar el articulo";
			}
			else
			{
				cout << " Registro" << dato << endl;
				cout << registro[dato].nombre << endl;
				cout << registro[dato].numero << endl;
				cout << registro[dato].genero << endl;
				cout << registro[dato].clasificacion << endl;
				cout << registro[dato].descripcion << endl;
				cout << registro[dato].consola << endl;
				cout << registro[dato].preciot << endl;
			}
			break;

			case 3:
				cout<<"Ingrese la consola la cual desea buscar: ";
			fflush(stdin);
			getline(cin, busqueda);

			for ( i = 0; i < alta; i++)
			{
				if (busqueda == registro[i].consola)
				{
					dato = i;
					break;
				}
				
			}

			if (dato == -1)
			{
				cout<<"No se pudo encontrar el articulo";
			}
			else
			{
				cout << " Registro" << dato << endl;
				cout << registro[dato].nombre << endl;
				cout << registro[dato].numero << endl;
				cout << registro[dato].genero << endl;
				cout << registro[dato].clasificacion << endl;
				cout << registro[dato].descripcion << endl;
				cout << registro[dato].consola << endl;
				cout << registro[dato].preciot << endl;
			}
			break;
		}
		
	} while (opcion != 4);
	
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
			gets_s(registro[i].genero,100);
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