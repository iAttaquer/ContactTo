#include "pgDbClient.h"
#include <iostream>
#include <QtWidgets/QMessageBox>

void pgDbClient::createstring()
{
	connection = "host=" + host + " dbname=" + dbname + " user=" + user + " password=" + password + " hostaddr=" + hostaddr + " port=" + port;
}

pgDbClient::pgDbClient()
{
	host = "localhost";
	dbname = "postgres";
	user = "postgres";
	password = "postgres";
	hostaddr = "127.0.0.1";
	port = "5432";
	createstring();
}

int pgDbClient::Count()
{
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
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

std::vector<Contact> pgDbClient::loadShortInfo()
{
	std::vector<Contact> contacts;
	try {
		pqxx::connection pgConnection(connection);
		if (pgConnection.is_open())
		{
			pqxx::work pgTran(pgConnection);
			std::string query = "select \"ID\", \"IMIE\", \"NAZWISKO\", \"TELEFON\" from \"CONTACTS\"";
			pqxx::result res = pgTran.exec(query);
			
			for (auto row : res) {
				Contact c;
				c.id = row[0].as<int>();
				c.firstname = row[1].as<std::string>();
				c.lastname = row[2].as<std::string>();
				c.number = row[3].as<std::string>();
				contacts.push_back(c);
			}
			pgTran.commit();
			pgConnection.close();
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return contacts;
}

FullContact pgDbClient::loadAllInfo(int id)
{
	FullContact contact;
	try {
		pqxx::connection pgConnection(connection);
		if (pgConnection.is_open())
		{
			pqxx::work pgTran(pgConnection);
			std::string query = "select * from \"CONTACTS\" where \"ID\" = "+ std::to_string(id);
			pqxx::result res = pgTran.exec(query);
			contact.id = res[0][0].as<int>();
			if(!res[0][1].is_null())
				contact.firstname = res[0][1].as<std::string>();
			if(!res[0][2].is_null())
				contact.lastname = res[0][2].as<std::string>();
			if(!res[0][3].is_null())
				contact.number = res[0][3].as<std::string>();
			if(!res[0][4].is_null())
				contact.homenumber = res[0][4].as<std::string>();
			if(!res[0][5].is_null())
				contact.company = res[0][5].as<std::string>();
			if(!res[0][6].is_null())
				contact.position = res[0][6].as<std::string>();
			if(!res[0][7].is_null())
				contact.email = res[0][7].as<std::string>();
			if(!res[0][8].is_null())
				contact.nickname = res[0][8].as<std::string>();
			pgTran.commit();
			pgConnection.close();
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return contact;
}
