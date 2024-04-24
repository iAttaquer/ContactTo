#include "pgDbClient.h"
#include <iostream>

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
			std::string query = "SELECT COUNT(*) FROM \"CONTACTS\"";
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
			std::string query = "SELECT \"ID\", \"IMIE\", \"NAZWISKO\", \"TELEFON\" FROM \"CONTACTS\"";
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
			std::string query = "SELECT * FROM \"CONTACTS\" WHERE \"ID\" = " + std::to_string(id);
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

bool pgDbClient::Is(FullContact c)
{
	try {
		pqxx::connection pgConnection(connection);
		if(pgConnection.is_open())
		{
			pqxx::work pgTran(pgConnection);
			std::string query = "SELECT \"ID\" FROM \"CONTACTS\" WHERE \"TELEFON\" = \'" + c.number + "\'";
			pqxx::result res = pgTran.exec(query);
			if (res.size() != 0)
				return true;
			pgTran.commit();
			pgConnection.close();
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return false;
}

bool pgDbClient::Add(FullContact c)
{
	{
		try {
			pqxx::connection pgConnection(connection);
			if(pgConnection.is_open())
			{
				pqxx::work pgTran(pgConnection);
				std::string query = "INSERT INTO \"CONTACTS\" (\"IMIE\", \"NAZWISKO\", \"TELEFON\", \"TEL_DOM\", \
					\"FIRMA\", \"STANOWISKO\", \"EMAIL\", \"PSEUDONIM\") VALUES ($1, $2, $3, $4, $5, $6, $7, $8);";
				pqxx::result res = pgTran.exec_params(query, c.firstname, c.lastname, c.number, c.homenumber,
					c.company, c.position, c.email, c.nickname);
				pgTran.commit();
				pgConnection.close();
				return true;
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		return false;
	}
	return false;
}

FullContact::FullContact(std::string f, std::string l, std::string nu, std::string hn, std::string c, std::string p, std::string e, std::string n)
{
	firstname = f;
	lastname = l;
	number = nu;
	homenumber = hn;
	company = c;
	position = p;
	email = e;
	nickname = n;
}

bool FullContact::operator==(FullContact f) const
{
	return this->firstname == f.firstname && this->lastname == f.lastname && this->number == f.number
		&& this->homenumber == f.homenumber && this->company == f.company && this->position == f.position
		&& this->email == f.email && this->nickname == f.nickname;
}
