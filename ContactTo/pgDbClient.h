#pragma once
#include <pqxx/pqxx>
#include <string>
#include <vector>

struct Contact {
	int id;
	std::string firstname;
	std::string lastname;
	std::string number;
};
struct FullContact : public Contact {
	std::string homenumber;
	std::string company;
	std::string position;
	std::string email;
	std::string nickname;
};

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
	std::vector<Contact> loadShortInfo();
	FullContact loadAllInfo(int id);
};