#include <iostream> 
#include <string>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
void alta();
void listas();
void archivos();
void eliminar();
void modificar();

int id;
string* np, * nt, * tdesc;
int* ep, * tcant, * h, * put, * precun, * total;

int main()
{

	int op, edad, c, h, preciounit, cant, preuni, total;
	string n, trata, descrip;
	int s = 1;


	do {

		cout << " --Citas para servicios medicos dentales-- \n" << endl;
		cout << "1.- Agendar cita" << endl;
		cout << "2.- Modificar cita" << endl;
		cout << "3.- Elminar cita" << endl;
		cout << "4.- Lista de citas vigentes" << endl;
		cout << "5.- Limpiar pantalla" << endl;
		cout << "6. - Salir" << endl;

		cout << "\n Ingrese la opcion que necesite: \n" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			alta();
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
			system("cls");
			return main();
			break;

		case 6:
			archivos();
			return 0;
			break;


		default:
			cout << "Por favor ingrese una opción valida \n" << endl;
		}
		if (op != 6)
		{
			cout << "Desea volver al menu?\n" << endl;
			cout << "1.- Si" << endl;
			cout << "2.- No" << endl;
			cin >> s;
		}
	} while (s == 1);

}

void alta()
{

	cout << "Porfavor, ingrese el numero de citas que desee dar de alta: ";
	cin >> id;
	np = new string[id];
	nt = new string[id];
	tdesc = new string[id];
	ep = new int[id];
	tcant = new int[id];
	h = new int[id];
	put = new int[id];
	precun = new int[id];
	total = new int[id];

	int T15 = 0;
	for (int i = 0; i < id; i++)
	{
		cout << "\nID de paciente: " << i + 1 << endl;
		while (getchar() != '\n');

		cout << "\nNombre del paciente:" << endl;
		getline(cin, np[i]);

		cout << "\nEdad del paciente:" << endl;
		cin >> ep[i];

		cout << "\nHora de tratamiento:" << endl;
		cin >> h[i];

		while (getchar() != '\n');
		cout << "\nNombre del tratamiento:" << endl;
		getline(cin, nt[i]);

		cout << "\nDescripcion sobre el tratamiento:" << endl;
		getline(cin, tdesc[i]);

		cout << "\nPrecio unitario del tratamiento:" << endl;
		cin >> put[i];

		cout << "\nCantidad necesaria del tratamiento:" << endl;
		cin >> tcant[i];

		cout << "\nPrecio unitario: " << endl;
		cin >> precun[i];

		total[i] = ((precun[i] + put[i] * tcant[i]));
		T15 = ((precun[i] + put[i]) * tcant[i]) * .16;
		total[i] = total[i] + T15;
		cout << total[i];
	}
}

void modificar()
{
	cout << "Ingrese la cita que desee modificar: \n" << endl;
	int xy;
	int T15 = 0;
	cin >> xy;
	xy = xy - 1;


	for (int i = xy; i <= xy; i++) {
		cout << "\nID de paciente: " << i + 1 << endl;
		while (getchar() != '\n');

		cout << "\nNombre del paciente:" << endl;
		getline(cin, np[i]);

		cout << "\nEdad del paciente:" << endl;
		cin >> ep[i];

		cout << "\nHora de tratamiento:" << endl;
		cin >> h[i];

		while (getchar() != '\n');
		cout << "\nNombre del tratamiento:" << endl;
		getline(cin, nt[i]);

		cout << "\nDescripcion sobre el tratamiento:" << endl;
		getline(cin, tdesc[i]);

		cout << "\nPrecio unitario del tratamiento:" << endl;
		cin >> put[i];

		cout << "\nCantidad necesaria del tratamiento:" << endl;
		cin >> tcant[i];

		cout << "\nPrecio unitario: " << endl;
		cin >> precun[i];

		total[i] = ((precun[i] + put[i] * tcant[i]));
		T15 = ((precun[i] + put[i]) * tcant[i]) * .16;
		total[i] = total[i] + T15;
		cout << total[i];
	}
}

void listas()
{
	for (int i = 0; i < id; i++) {
		cout << "Nombre del paciente: " << np[i] << endl;
		cout << "Edad del paciente: " << ep[i] << endl;
		cout << "Hora: " << h[i] << endl;
		cout << "Nombre del tratamiento: " << nt[i] << endl;
		cout << "Descripcion del tratamiento: " << tdesc[i] << endl;
		cout << "Precio unitario del tratamiento: " << put[i] << endl;
		cout << "Cantidad necesaria del tratamiento: " << tcant[i] << endl;
		cout << "Precio unitario: " << precun[i] << endl;
		cout << "total: " << total[i] << endl;
	}
}

void eliminar()
{
	cout << "Ingrese la cita que desee eliminar: \n" << endl;
	int b;
	cin >> b;
	b = b - 1;
	for (int i = b; i <= b; i++) {

		cout << "Eliminando registro: " << b + 1 << endl;

		np[i] = " ";
		ep[i] = 0;
		h[i] = 0;
		nt[i] = " ";
		tdesc[i] = " ";
		put[i] = 0;
		tcant[i] = 0;
		precun[i] = 0;
		total[i] = 0;
	}
}

void archivos()
{

	ofstream archivo;
	string narchivo;
	int texto1;
	string texto2;

	narchivo = "archivo";

	archivo.open(narchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	for (int i = 0; i < id; i++)
	{

		texto1 = ep[i];
		archivo << "Edad paciente" << texto1 << "\n";
		texto1 = tcant[i];
		archivo << "Cantidad del tratamiento" << texto1 << "\n";
		texto1 = put[i];
		archivo << "Precio unitario tratamiento" << texto1 << "\n";
		texto1 = h[i];
		archivo << "Hora" << texto1 << "\n";
		texto1 = total[i];
		archivo << "Total" << texto1 << "\n";
		texto1 = precun[i];
		archivo << "Precio unitarior" << texto1 << "\n";
		texto2 = np[i];
		archivo << "Nombre paciente: " << texto2 << "\n";
		texto2 = nt[i];
		archivo << "Nombre tratamiento: " << texto2 << "\n";
		texto2 = tdesc[i];
		archivo << "Descripcion del tratamiento: " << texto2 << "\n";

	}
	archivo.close();
}
