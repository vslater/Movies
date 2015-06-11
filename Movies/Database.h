#pragma once

#include "sqlite3.h"
#include <string>

class Database
{
public:
	Database(std::string dbFile);
	~Database();

	void printResults();
	void listFilmsByActor(std::string actor);
	int instruction(std::string _instruction);



private:
	sqlite3 *db;
	sqlite3_stmt *statement;
};

