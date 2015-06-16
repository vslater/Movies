#pragma once

#include "stdafx.h"
#include "Gui.h"
#include <iostream>
#include <string>
#include "Database.h"


Gui::Gui(Database db) : myDb(db)
{
	askStartingQuestion();
}


Gui::~Gui()
{
}

void Gui::askStartingQuestion()
{
	std::cout << "What do you want to do?\n";
	std::cout << "0 - List films by actor\n";
	std::cout << "1 - List director and actors by film\n";
	std::cout << "2 - Add new film\n";
	std::cout << "3 - Exit\n";
	int answer = std::cin.get() - 48;
	std::cout << "\n";
	switch (answer){
	case 0:
		listFilmsByActor();
		break;
	case 1:
		listFilmInfo();
		break;
	case 2:
		addNewFilm();
		break;
	case 3:
		std::cout << "\nGoodbye";
		break;
	dafault:
		std::cout << "Try again";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//Database Gui::myDb = Database("C:\\SQLite\\Movies.db");

void Gui::listFilmsByActor(){
	std::cout << "Which actor's films would you like listed?\n";
	std::string actor;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, actor);
	std::string start = "Select Films.name from Actors, Films, Actor_Film_Mapping where (Actors.Name == '";
	std::string end = "') and (Films.FilmID == Actor_Film_Mapping.FilmID) and (Actors.id == Actor_Film_Mapping.ActorID)";
	std::string finalInstruction = start + actor + end;
	myDb.instruction(finalInstruction);
	myDb.printResults();
	askStartingQuestion();
}

void Gui::listFilmInfo(){
	std::cout << "Which film's information would you like listed?\n";

	std::string film;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, film);

	std::string finalInstruction = "select Directors.Name from Films, Directors where (Films.Name == '" + film + "' and (Films.DirectorID == Directors.DirectorID))";
	myDb.instruction(finalInstruction);
	std::cout << "Director:";
	myDb.printResults();
	askStartingQuestion();

}

void Gui::addNewFilm(){
	std::cout << "What is the name of the film\n?";
}