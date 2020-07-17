#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <cstring>	
#include <iostream>
// Clase para la exepcion
class	MyException {
public:
	// Almacenara el mensaje de error
	char msg[40];
	MyException() {
		*msg = 0;
	}
	MyException(const char* msg2) {
		strcpy(this->msg, msg2);
	}
};

class MySQLExceptions {
public:
	char message[50];
};

class ConnectionMySQLException : public MySQLExceptions {
public:
	ConnectionMySQLException(const char* msg2) {
		strcpy(this->message, msg2);
	}
};


#endif
