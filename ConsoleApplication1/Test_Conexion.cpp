#include <stdlib.h>
#include <stdio.h>
#include <mysql.h>
/*
int main() {
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
	const char* server = "programacionsistemasproyectodelivery.mysql.database.azure.com";
	const char* user = "cmestas@programacionsistemasproyectodelivery";
	const char* password = "PS_123**";
	const char* database = "delivery";
	conn = mysql_init(NULL);
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	if (mysql_query(conn, "select * from Cliente")) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	res = mysql_use_result(conn);
	printf("Tabla clientes:\n");
	while ((row = mysql_fetch_row(res)) != NULL) 
		printf("%s \t %s \t %s \n", row[0], row[1], row[2]);
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}
*/