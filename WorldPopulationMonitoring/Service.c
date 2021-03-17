#include "Service.h"
#include <string.h>

Service createService(Repository* repo, UndoManager* um)
{
	Service s;
	s.repo = repo;
	s.um = um;
	return s;
}

void addCountry(Service s, Country c)
{
	recordUndo(s.um, *s.repo);
	addCountryRepo(s.repo, c);
}

void deleteCountry(Service s, char name[])
{
	recordUndo(s.um, *s.repo);
	deleteCountryRepo(s.repo, name);
}

void updateCountry(Service s, char old_name[], Country newC)
{
	recordUndo(s.um, *s.repo);
	updateCountryRepo(s.repo, old_name, newC);
}

Country* getAllCountries(Service s)
{
	return getAllCountriesRepo(s.repo);
}

int getNumberCountries(Service s)
{
	return getNumberCountriesRepo(s.repo);
}

void add10Countries(Service s)
{
	Country c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;

	c1 = createCountry("Japan", "Asia", 126.3);
	c2 = createCountry("Brazil", "America", 211);
	c3 = createCountry("North Korea", "Asia", 25.67);
	c4 = createCountry("Italy", "Europe", 60.36);
	c5 = createCountry("Sri Lanka", "Asia", 21.8);
	c6 = createCountry("Canada", "America", 37.59);
	c7 = createCountry("Denmark", "Europe", 5.806);
	c8 = createCountry("Nigeria", "Africa", 201);
	c9 = createCountry("Argentina", "America", 44.94);
	c10 = createCountry("Sweden", "Europe", 10.23);

	addCountry(s, c1);
	addCountry(s, c2);
	addCountry(s, c3);
	addCountry(s, c4);
	addCountry(s, c5);
	addCountry(s, c6);
	addCountry(s, c7);
	addCountry(s, c8);
	addCountry(s, c9);
	addCountry(s, c10);
}

int filterByContinent(Service s, char continent[], Country* pcf)
{
	// Populates an array with the countries situated on a specified continent
	int nr_countries = getNumberCountries(s);
	Country* pc = getAllCountries(s);

	int ind = 0;

	// If a continent was specified, return the countries on that continent.
	if (strcmp(continent, "\0") != 0)
	{
		for (int i = 0; i < nr_countries; ++i)
			if (strcmp(pc[i].continent, continent) == 0)
				pcf[ind++] = pc[i];
	}
	// Else, return them all.
	else
	{
		for (int i = 0; i < nr_countries; ++i)
			pcf[ind++] = pc[i];
	}

	sortAscendingPopulation(ind, pcf);
	return ind;
}

void sortAscendingName(int nrCountries, Country* pc)
{
	Country caux;

	for(int i = 0; i < nrCountries - 1; ++i)
		for(int j = i + 1; j < nrCountries; ++j)
			if (strcmp(pc[i].name, pc[j].name) > 0)
			{
				caux = pc[i];
				pc[i] = pc[j];
				pc[j] = caux;
			}
}

int migrate(Service s, char name1[], char name2[], double population)
{
	recordUndo(s.um, *s.repo);
	// Simulates the migration of "population" number of people from a country (1) to another (2)

	int nrCountries = getNumberCountries(s);
	Country* pc = getAllCountries(s);

	for (int i = 0; i < nrCountries; ++i)
	{
		// When finding the country that the people migrate AWAY FROM, update it 
		// with a correspondingly modified population number.
		if (strcmp(pc[i].name, name1) == 0)
		{
			if (pc[i].population < population)
			{
				return 0;
			}
			else
				pc[i].population = pc[i].population - population;
		}
	}

	for(int i = 0; i < nrCountries; ++i)
	{
		// When finding the country that the people migrate TO, update it 
		// with a correspondingly modified population number.
		if (strcmp(pc[i].name, name2) == 0)
		{
			pc[i].population = pc[i].population + population;
		}
	}

	return 1;
}

void sortAscendingPopulation(int nrCountries, Country* pc)
{
	Country caux;

	for (int i = 0; i < nrCountries - 1; ++i)
		for (int j = i + 1; j < nrCountries; ++j)
			if (pc[i].population > pc[j].population)
			{
				caux = pc[i];
				pc[i] = pc[j];
				pc[j] = caux;
			}
}

int filterByCountry(Service s, char country[], Country* pcf)
{
	// Populates an array with the countries whose names contain a certain string.
	int nr_countries = getNumberCountries(s);
	Country* pc = getAllCountries(s);

	int ind = 0;

	// If a string was specified, return the countries whose names contain the specified string.
	if (strcmp(country, "\0") != 0)
	{
		for (int i = 0; i < nr_countries; ++i)
			if (strstr(pc[i].name, country) != NULL)
				pcf[ind++] = pc[i];
	}
	// Else, return them all.
	else
	{
		for (int i = 0; i < nr_countries; ++i)
			pcf[ind++] = pc[i];
	}

	return ind;
}

int filterByContinentPopulation(Service s, char continent[], double population, Country* pcf)
{
	// Populates an array with the countries situated on a specified continent
	int nr_countries = getNumberCountries(s);
	Country* pc = getAllCountries(s);

	int ind = 0;

	// If a continent was specified, return the countries on that continent.
	if (strcmp(continent, "\0") != 0)
	{
		for (int i = 0; i < nr_countries; ++i)
			if (strcmp(pc[i].continent, continent) == 0 && pc[i].population > population)
				pcf[ind++] = pc[i];
	}
	// Else, return them all.
	else
	{
		for (int i = 0; i < nr_countries; ++i)
			if (pc[i].population > population)
				pcf[ind++] = pc[i];
	}
	sortAscendingPopulation(ind, pcf);
	return ind;
}

void undoService(Service s)
{
	*s.repo = undo(s.um, *s.repo);
}

void redoService(Service s)
{
	*s.repo = redo(s.um, *s.repo);
}

Country getCountry(Service s, int index)
{
	return getCountryRepo(s.repo, index);
}