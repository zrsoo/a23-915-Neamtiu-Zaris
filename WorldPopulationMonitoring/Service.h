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