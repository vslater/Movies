#pragma once

#include "stdafx.h"
#include "Database.h"
#include <iostream>


Database::Database(std::string dbFile)
{
	int sqlResult = sqlite3_open(dbFile.c_str(), &db);
	if (sqlResult != SQLITE_OK){
		throw _invalid_parameter;
	}
}


Database::~Database()
{
	sqlite3_close(db);
}

int Database::instruction(std::string _instruction){

	int sqlResult  = sqlite3_prepare_v2(db, _instruction.c_str(), -1, &statement, 0);
	if (sqlResult != SQLITE_OK){
		std::cout << "WRONG";
	}
	return sqlResult;
}

void Database::printResults(){

	std::cout << "\n";
	int cols = sqlite3_column_count(statement);
	int rowResult;
	while (true){

		rowResult = sqlite3_step(statement);
		if (rowResult == SQLITE_ROW){
			for (int col = 0; col < cols; col++){
				std::string s = (char*)sqlite3_column_text(statement, col);
				std::cout << s << std::endl;
			}
			std::cout << "\n";

		}
		else{
			break;
		}

	}
}
