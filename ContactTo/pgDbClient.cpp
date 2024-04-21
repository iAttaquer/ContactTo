#include "pgDbClient.h"
#include <iostream>
#include <QtWidgets/QMessageBox>

void pgDbClient::createstring()
{
	//connection = "host=" + host + " dbname=" + dbname + " user=" + user + " password=" + password + " hostaddr=" + hostaddr + " port=" + port;
	connection = "host=localhost dbname=postgres user=postgres password=postgres hostaddr=127.0.0.1 port=5432";
}

pgDbClient::pgDbClient()
{
	host = "localhost";
	dbname = "postgres";
	user = "postgres";
	password = "postgres";
	hostaddr = "127.0.0.1";
	port = "5432";
}

int pgDbClient::Count()
{
	std::cerr << connection << std::endl;
	try{
		pqxx::connection pgConnection(connection);
		if (pgConnection.is_open())
		{
			pqxx::work pgTran(pgConnection);
			std::string query = "select count(*) from \"CONTACTS\"";
			pqxx::result res = pgTran.exec(query);
			int count = res[0][0].as<int>();
			pgTran.commit();
			pgConnection.close();
			return count;
		}
		else return -1;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return -2;
	}
	return 0;
}
