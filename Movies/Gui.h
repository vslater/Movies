#pragma once

#include "Database.h";

class Gui
{
public:
	Gui(Database db);
	~Gui();
private:
	Database myDb;
	void listFilmsByActor();
	void listFilmInfo();
	void addNewFilm();
	void askStartingQuestion();
};

