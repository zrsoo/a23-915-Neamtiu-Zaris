#pragma once
#include "Repository.h"
#include "UndoManager.h"

typedef struct {
	Repository* repo;
	UndoManager* um;
} Service;

Service createService(Repository* repo, UndoManager* um);
void addCountry(Service s, Country c);
void deleteCountry(Service s, char name[]);
void updateCountry(Service s, char old_name[], Country newC);
Country* getAllCountries(Service s);
Country getCountry(Service s, int index);
int getNumberCountries(Service s);
void add10Countries(Service s);
int filterByContinent(Service s, char continent[], Country* pcf);
void sortAscendingName(int nrCountries, Country* pc);
void sortAscendingPopulation(int nrCountries, Country* pc);
int migrate(Service s, char name1[], char name2[], double population);
int filterByCountry(Service s, char country[], Country* pcf);
int filterByContinentPopulation(Service s, char continent[], double population, Country* pcf);
void undoService(Service s);
void redoService(Service s);