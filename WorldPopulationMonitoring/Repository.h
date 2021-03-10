#pragma once
#include "Country.h"

typedef struct {
	int nr_countries;
	Country countries[200];
} Repository;

Repository createRepository();
void addCountryRepo(Repository* repo, Country c);
void deleteCountryRepo(Repository* repo, char name[]);
void updateCountryRepo(Repository* repo, char old_name[], Country newC);
Country* getAllCountriesRepo(Repository* repo);
int getNumberCountriesRepo(Repository* repo);