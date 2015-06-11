// Movies.cpp : Defines the entry point for the console application.
//

#pragma once

#include "stdafx.h"
#include <iostream>
#include "Gui.h"
#include "Database.h"



int _tmain(int argc, _TCHAR* argv[])
{
	
	
	Database myDb("C:\\SQLite\\Movies.db");
	Gui gui(myDb);
	//myDb.instruction("Select  * from Actors where Actors.id > 4");
	//(Films.Name == 'Good Will Hunting') and
	//myDb.instruction("Select Actors.name from Actors, Films, Actor_Film_Mapping where (Films.Name == 'Good Will Hunting') and (Films.FilmID == Actor_Film_Mapping.FilmID) and (Actors.id == Actor_Film_Mapping.ActorID)");
	//myDb.printResults();

	std::cin.get();
	return 0;
}

