#include <iostream>
#include <stdlib.h>
using namespace std;

int menu, m, p, decision1, pt;
char n[100], c[100], d[10000], g[100], consola[100];

int main()
{
	cout << " " << endl;
	cout << "Bienvenido al menu de opciones" << endl;
	cout << "1.-Alta de articulos" << endl << "2.-Mod articulos " << endl << "3.-Baja de articulos " << endl << "4.- Lista de articulos " << endl << "5.- limpiar pantalla" << endl << "6.- Salir" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
	{
		cout << "Alta de articulos " << endl;

		cout << "Ingrese el nombre del articulo: " << endl;
		cin >> n;
		cout << "Numero del articulo" << endl;
		cin >> m;
		cout << "Genero del articulo " << endl;
		cin >> g;
		cout << "clasificacion del articulo: " << endl;
		cin >> c;
		cout << "Descripcion del articulo" << endl;
		cin >> d;
		cout << "Tipo de consola: " << endl;
		cin >> consola;
		cout << "Precio del articulo" << endl;
		cin >> p;
		p =p + (p * 0.16);
		cout << "Precio total con impuestos: " << p << endl;
		
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
	}

	case 2:
	{
		break;
	}

	case 3:
	{
		break;
	}

	case 4:
	{
		break;
	}
	case 5:
	{
		system("cls");
		return main();
		break;
	}

	case 6:
	{
		exit(1);
		break;
	}

	default:

	{
		cout << "Opcion invalida o no disponible " << endl;
		return main();
		break;
	}
	
	}



	 
   return 0;
}