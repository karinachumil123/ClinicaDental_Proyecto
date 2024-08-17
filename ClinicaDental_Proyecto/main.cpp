#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = (SHORT)x - 1;
	coord.Y = (SHORT)y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct medicamentos{
	string nombre;
	string marca;
	float precio;
	medicamentos* siguiente;
}medicina, *medicina_puntero = &medicina;

void menuPrincipal();
void subMenu();
//void pedirMedicamentos();
void agregarPilaMedicamento(medicamentos*& pila);
void mostrarPilaMedicamento(medicamentos*& pila);
void modificarPilaMedicamento(medicamentos*& pila);
void buscarmedicamento(medicamentos*& pila);
void eliminarmedicamento(medicamentos*& pila);

int main() {
	medicamentos* pila = NULL;
	int opc = 0;
	do{
		menuPrincipal();
		gotoxy(68, 20); cin >> opc;
		switch (opc){
		case 1: 
			do{
				system("cls");
				gotoxy(44, 7); cout << "________________________________";
				gotoxy(44, 8); cout << "||        MEDICAMENTOS        ||";
				gotoxy(44, 9); cout << "--------------------------------";
				subMenu();
				gotoxy(68, 21); cin >> opc;

				switch (opc){
				case 1: 
					char opc;
					do {
						system("cls");
						gotoxy(44, 9); cout << "________________________________";
						gotoxy(44, 10); cout << "||    AGREGAR MEDICAMENTOS    ||";
						gotoxy(44, 11); cout << "--------------------------------";

						gotoxy(35, 13); cout << "Digite el nombre: ";
						cin.ignore();
						gotoxy(53, 13); getline(cin, medicina_puntero->nombre);
						gotoxy(35, 15); cout << "Digite la marca: ";
						gotoxy(52, 15); getline(cin, medicina_puntero->marca);
						gotoxy(35, 17); cout << "Digite el precio: ";
						gotoxy(53, 17); cin >> medicina_puntero->precio;
						agregarPilaMedicamento(pila);
						gotoxy(43, 19); cout << "¿Quieres agregar otro medicamento?";
						gotoxy(36, 20); cout << "Digita la tecla S para SI o tecla N para NO [   ]";
						gotoxy(82, 20); cin >> opc;
					} while (opc == 'S' || opc == 's');
					break;
				case 2: 
					mostrarPilaMedicamento(pila);
					_getch();
					break;
				case 3:
					modificarPilaMedicamento(pila); // areglar 
					system("pause");
						break;
;				case 4: 
					buscarmedicamento(pila);
						break;
				case 5: 
					 eliminarmedicamento(pila);
					break;
				default:
					break;
				}
			} while (opc !=6);
			break;
		case 2: 
			do{
				system("cls");
				gotoxy(44, 7); cout << "________________________________";
				gotoxy(44, 8); cout << "||         PACIENTES          ||";
				gotoxy(44, 9); cout << "--------------------------------";
				subMenu();
				gotoxy(68, 21); cin >> opc;
			} while (opc != 6);
			break;
		default:
			break;
		}
	} while (opc != 3);

	return 0;
}

void menuPrincipal() {
	system("cls");
	gotoxy(44, 9); cout << "________________________________";
	gotoxy(44, 10); cout << "|| CLINICA DENTAL EL CHIMUELO ||";
	gotoxy(44, 11); cout << "--------------------------------";
	gotoxy(44,12); cout << "|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|";
	gotoxy(44, 13); cout << "|*|                           |*|";
	gotoxy(44, 14); cout << "|*|      1. Medicamentos      |*|";
	gotoxy(44, 15); cout << "|*|      2. Pacientes         |*|";
	gotoxy(44, 16); cout << "|*|      3. Salir             |*|";
	gotoxy(44, 17); cout << "|*|                           |*|";
	gotoxy(44, 18); cout << "|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|";
	gotoxy(50, 20); cout << "DIGITA LA OPCION[   ]";
}

void subMenu() {
	gotoxy(44, 10); cout << "|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|";
	gotoxy(44, 11); cout << "|*|                           |*|";
	gotoxy(44, 12); cout << "|*|      1. Agregar dato      |*|";
	gotoxy(44, 13); cout << "|*|      2. Mostrar dato      |*|";
	gotoxy(44, 14); cout << "|*|      3. Modificar dato    |*|";
	gotoxy(44, 15); cout << "|*|      4. Buscar dato       |*|";
	gotoxy(44, 16); cout << "|*|      5. Eliminar dato     |*|";
	gotoxy(44, 17); cout << "|*|      6. Regresar          |*|";      
	gotoxy(44, 18); cout << "|*|                           |*|";
	gotoxy(44, 19); cout << "|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|";
	gotoxy(50, 21); cout << "DIGITA LA OPCION[   ]";

}



void agregarPilaMedicamento(medicamentos*& pila) {
	medicamentos* nuevo_medicamento = new medicamentos();//new medicamentos();
	nuevo_medicamento->nombre = medicina_puntero->nombre;
	nuevo_medicamento->marca = medicina_puntero->marca;
	nuevo_medicamento->precio = medicina_puntero->precio;
	nuevo_medicamento->siguiente = pila;
	pila = nuevo_medicamento;
}

void mostrarPilaMedicamento(medicamentos*& pila) {
	medicamentos* aux = pila;
	if (aux == NULL) {
		system("cls");
		gotoxy(43,14); cout << "__________________________________";
		gotoxy(43, 15); cout << "|| NO EXISTE NINGUN MEDICAMENTO ||";
		gotoxy(43, 16); cout << "----------------------------------";
	}else {
		system("cls");
		int contador =0;
		while (aux != NULL) {
			
			gotoxy(43, 2); cout << "__________________________________";
			gotoxy(43, 3); cout << "||    LISTADO DE MEDICAMENTOS   ||";
			gotoxy(43, 4); cout << "----------------------------------";
			gotoxy(36, 6); cout << "NOMBRE                MARCA                PRECIO";
			
			gotoxy(20, 7 + contador); cout << contador + 1;
			gotoxy(36, 7 + contador ); cout << aux->nombre;
			gotoxy(58, 7 + contador ); cout << aux->marca;
			gotoxy(79, 7 + contador ); cout << aux->precio;
			
			aux = aux->siguiente;
			contador++;
		}
	}
	delete aux;
}


	void modificarPilaMedicamento(medicamentos * &pila) {
		int opcion, i = 0;
		medicamentos* actual = pila;

		system("cls");
		gotoxy(44, 7); cout << "________________________________";
		gotoxy(44, 8); cout << "||     MODIFICAR DATO        ||";
		gotoxy(44, 9); cout << "--------------------------------";

		mostrarPilaMedicamento(pila);
		gotoxy(35, 13 + i); cout << "Digite el numero del medicamento que desea modificar: ";
		cin >> opcion;

		// buscar el nodo a modificar
		while (i < opcion - 1 && actual != NULL) {
			actual = actual->siguiente;
			i++;
		}

		if (actual != NULL) {
			// modificar el nodo
			gotoxy(35, 15 + i); cout << "Digite el nuevo nombre: ";
			cin.ignore();
			getline(cin, actual->nombre);
			gotoxy(35, 16 + i); cout << "Digite la nueva marca: ";
			getline(cin, actual->marca);
			gotoxy(35, 17 + i); cout << "Digite el nuevo precio: ";
			cin >> actual->precio;
		}
		else {
			// el medicamento no se encontró en la pila
			gotoxy(35, 15); cout << "El medicamento no se encuentra en la lista";
		}
	}


	void buscarmedicamento(medicamentos*& pila) {

		string nombre;
		medicamentos* actual = pila;
		bool encontrado = false;
		system("cls");
		gotoxy(44, 7); cout << "________________________________";
		gotoxy(44, 8); cout << "||     BUSCAR MEDICAMENTO     ||";
		gotoxy(44, 9); cout << "--------------------------------";

		gotoxy(35, 12); cout << "Digite el nombre del medicamento a buscar: ";
		cin.ignore();
		getline(cin, nombre);

		while (actual != NULL) {
			if (actual->nombre == nombre) {
				encontrado = true;
				break;
			}
			actual = actual->siguiente;
		}

		if (encontrado) {
			gotoxy(35, 15); cout << "Nombre: " << actual->nombre;
			gotoxy(35, 16); cout << "Marca: " << actual->marca;
			gotoxy(35, 17); cout << "Precio: " << actual->precio;

			cout << ("endl");
			cout << ("endl");
		}
		else {
			gotoxy(35, 15); cout << "El medicamento no se encuentra en la pila";
		}
		
		system("pause");
	
	}

	void eliminarmedicamento(medicamentos*& pila) 
	{

		system("cls");
		medicamentos* aux = pila; 
		if (aux ==NULL)
		{
			cout << "La pila esta vacia...";
		}
		else {

			medicina_puntero = aux->siguiente;
			pila = aux->siguiente;
			delete aux;


			gotoxy(44, 7); cout << "_________________________________";
			gotoxy(44, 8); cout << "||   ELIMINANDO REGISTRO... ||";
			gotoxy(44, 9); cout << "---------------------------------"<<endl;
			system("pause");

			system("cls");
			gotoxy(44, 7); cout << "_________________________________";
			gotoxy(44, 8); cout << "||  REGISTRO ELEIMANDO CON EXITO||";
			gotoxy(44, 9); cout << "---------------------------------"<<endl;
		}
		
		system("pause");
	}







