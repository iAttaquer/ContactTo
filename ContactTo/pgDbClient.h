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
class FullContact : public Contact {
public:
	std::string homenumber;
	std::string company;
	std::string position;
	std::string email;
	std::string nickname;
	FullContact(std::string f = "", std::string l = "", std::string nu = "", std::string hn = "",
		std::string c = "", std::string p = "", std::string e = "", std::string n = "");
	bool operator==(FullContact f) const;
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
	bool Is(FullContact c);
	bool Add(FullContact c);
};