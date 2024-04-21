#pragma once
#include <pqxx/pqxx>
#include <string>

class pgDbClient
{
private:
	std::string host;
	std::string dbname;
	std::string user;
	std::string	password;
	std::string hostaddr;
	std::string port;
	std::string connection;
	void createstring();

public:
	pgDbClient();
	int Count();
	std::string con() { return connection; }
};