#include <stdlib.h>
#include <stdio.h>
#include <mysql.h>
#include <string>
#include <stack>
#include <iostream>
#include <cstring>
#include <conio.h>

#include "Exceptions.h"

using namespace std;

int qstate;

void addClients(MYSQL* conn) {
	const char* inputA = "\"INSERT into `deliveryTest`.`client` (`CliNam`,`CliAdd`, `CliPho`,`CliPayTyp`) VALUES ('";
	const char* inputB = "', '";
	const char* inputC = "', '";
	const char* inputD = "','";
	const char* inputE = "');\"";
	string CliNam, CliAdd, CliPho, CliPayTyp;
	system("CLS");
	cout << "\t\t\tIngreso de datos de un nuevo cliente: \n\n";
	cout << "\t\t\tIngrese el nombre del cliente: ";
	cin >> CliNam;

	cout << "\t\t\tIngrese la direccion del cliente: ";
	cin >> CliAdd;

	cout << "\t\t\tIngrese el numero de telefono del cliente: ";
	cin >> CliPho;

	cout << "\t\t\tIngrese el tipo de pago del cliente: ";
	cin >> CliPayTyp;

	string query = "INSERT into `client` (`CliNam`,`CliAdd`, `CliPho`,`CliPayTyp`) VALUES('" + CliNam + "', '" + CliAdd + "', '" + CliPho + "', '" + CliPayTyp + "')";

	const char* q = query.c_str();

	qstate = mysql_query(conn, q);

	if (!qstate) {
		cout << "\nDatos ingresados correctamente ..." << "\n";
		std::cout << "\n\t\t\tPulse una tecla para continuar...";
		_getch();
		system("CLS");
	}
	else
		cout << "Problemas en el ingreso del nuevo cliente ..." << mysql_error(conn);
}

void showClients(MYSQL* conn) {
	MYSQL_RES* res;
	MYSQL_ROW row;
	if (mysql_query(conn, "SELECT * FROM CLIENT")) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	res = mysql_use_result(conn);
	printf("Tabla clientes:\n");
	cout << "Codigo\tNombre\tDireccion\tTelefono\tTipo de pago" << "\n";
	while ((row = mysql_fetch_row(res)) != NULL)
		printf("%s \t %s \t %s \t %s \t %s \n", row[0], row[1], row[2], row[3], row[4], row[5]);
	mysql_free_result(res);
	std::cout << "\n\t\t\tPulse una tecla para continuar...";
	_getch();
	system("CLS");
}

int main() {
	system("color f0");
	MYSQL* conn;

	const char* server = "programacionsistemasproyectodelivery.mysql.database.azure.com";
	const char* user = "cmestas@programacionsistemasproyectodelivery";
	const char* password = "PS_123**";
	const char* database = "deliveryTest";

	conn = mysql_init(0);
	/*
	if (conn)
		cout << "Conexion realizada ..." << endl;
	else
		cout << "Problemas de conexion ..." << mysql_error(conn);
	*/

	conn = mysql_real_connect(conn, server, user, password, database, 0, NULL, 0);

	try {
		if(conn){
			do {
				cout << "\n\tMenu de opciones a realizar: " << "\n";
				cout << "\t\t1. Menu clientes ..." << "\n";
				cout << "\t\t7. Salir ..." << "\n";
				int option;
				cout << "\n\t\tIngrese la opcion: ";
				cin >> option;
				switch (option) {
				case 1:
					int option2;
					system("CLS");
					cout << "\tMenu de opciones de clientes: " << "\n";
					cout << "\t\t1. Agregar clientes ..." << "\n";
					cout << "\t\t2. Mostrar la lista de clientes ..." << "\n";
					cout << "\n\t\tIngrese la opcion: ";
					cin >> option2;
					switch (option2) {
					case 1:
						addClients(conn);
						break;
					case 2:
						showClients(conn);
						break;
					default:
						cout << "\nIngreso incorrectamente la opcion ... regresando al menu principal\n";
						std::cout << "\n\t\t\tPulse una tecla para continuar...";
						_getch();
						system("CLS");
						break;
					}
					break;
				case 7:
					cout << "\nConexion terminada ..." << endl;
					mysql_close(conn);
					printf("\033c");
					exit(0);
					break;
				default:
					cout << "\nIngrese una opcion correctamente ..." << "\n";
				}

			} while (true);
		}
		else {
			throw ConnectionMySQLException("No se pudo realizar la conexion a la base de datos ...");
		}
	}
	catch (ConnectionMySQLException e) {
		cerr << "\nError:	" << e.message;
	}
	return 0;
}



