#pragma once
#include "Country.h"
#include "DynamicArray.h"

typedef struct {
	//int nr_countries;
	DynamicArray da;
	//Country countries[200];
} Repository;

Repository createRepository();
void addCountryRepo(Repository* repo, Country c);
void deleteCountryRepo(Repository* repo, char name[]);
void updateCountryRepo(Repository* repo, char old_name[], Country newC);
Country* getAllCountriesRepo(Repository* repo);
Country getCountryRepo(Repository* repo, int index);
int getNumberCountriesRepo(Repository* repo);
void DestroyDynamicArray(Repository* repo);