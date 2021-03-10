#pragma once
#include "Repository.h"

typedef struct {
	Repository* repo;
} Service;

Service createService(Repository* repo);
void addCountry(Service s, Country c);
void deleteCountry(Service s, char name[]);
void updateCountry(Service s, char old_name[], Country newC);
Country* getAllCountries(Service s);
int getNumberCountries(Service s);
void add10Countries(Service s);
int filterByContinent(Service s, char continent[], Country* pcf);
void sortAscendingName(int nrCountries, Country* pc);
void migrate(Service s, char name1[], char name2[], double population);