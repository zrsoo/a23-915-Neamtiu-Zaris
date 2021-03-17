#include "Test.h"
#include <string.h>

Test createTest(Repository* repo, UndoManager* um)
{
	Test t;
	
	Service s = createService(repo, um);
	add10Countries(s);

	t.service = s;
	t.nrCountries = getNumberCountries(s);
	t.pc = getAllCountries(s);

	return t;
}

void testAdd(Test t)
{
	// Tests the add functionality.

	assert(t.nrCountries == 10);

	// Create a new country to be added.
	Country c;
	c = createCountry("Romania", "Europe", 18.6);

	// Add the country.
	addCountry(t.service, c);

	// Update the number of countries.
	t.nrCountries = getNumberCountries(t.service);

	// Check if the country was added.
	assert(t.nrCountries == 11);

	Country check = getCountry(t.service, 10);

	// Check if the country was added correctly.
	assert(strcmp(check.name, "Romania") == 0);
	assert(strcmp(check.continent, "Europe") == 0);
	assert(check.population == 18.6);
}

void testDelete(Test t)
{
	// Tests the delete functionality
	
	t.nrCountries = getNumberCountries(t.service);

	assert(t.nrCountries == 11);

	assert(strcmp(getCountry(t.service, t.nrCountries - 1).name, "Romania") == 0);
	assert(strcmp(getCountry(t.service, t.nrCountries - 1).continent, "Europe") == 0);
	assert(getCountry(t.service, t.nrCountries - 1).population == 18.6);

	// Deleting last country.
	deleteCountry(t.service, "Romania");

	t.nrCountries = getNumberCountries(t.service);

	// Checking if the country was deleted.
	assert(t.nrCountries == 10);

	assert(strcmp(getCountry(t.service, t.nrCountries - 1).name, "Sweden") == 0);
	assert(strcmp(getCountry(t.service, t.nrCountries - 1).continent, "Europe") == 0);
	assert(getCountry(t.service, t.nrCountries - 1).population == 10.23);
}

void testUpdate(Test t)
{
	// Tests the update functionality.

	// Check if now the last country is Sweden.
	assert(strcmp(getCountry(t.service, t.nrCountries - 1).name, "Sweden") == 0);
	assert(strcmp(getCountry(t.service, t.nrCountries - 1).continent, "Europe") == 0);
	assert(getCountry(t.service, t.nrCountries - 1).population == 10.23);

	// Update the last country to Romania.
	Country cUpdate = createCountry("Romania", "Europe", 18.6);
	updateCountry(t.service, "Sweden", cUpdate);

	// Check if last country is now Romania.
	assert(strcmp(getCountry(t.service, t.nrCountries - 1).name, "Romania") == 0);
	assert(strcmp(getCountry(t.service, t.nrCountries - 1).continent, "Europe") == 0);
	assert(getCountry(t.service, t.nrCountries - 1).population == 18.6);
}

void testFilterByContinent(Test t)
{
	// Checks the filter by continent functionality.

	Country filteredCountries[30];
	int length = filterByContinent(t.service, "", &filteredCountries);

	// Checking if filter by null continent retrieves all countries.
	assert(length == 10);

	// Checking if the countries are sorted ascendingly by population.
	for (int i = 0; i < length - 1; ++i)
		assert(filteredCountries[i].population < filteredCountries[i + 1].population);

	// Checking if filter by non-null continent retrieves the corresponding countries.
	length = filterByContinent(t.service, "Europe", &filteredCountries);
	for (int i = 0; i < length; ++i)
		assert(strcmp(filteredCountries[i].continent, "Europe") == 0);

	// Checking if filter by unknown continent returns void array.
	length = filterByContinent(t.service, "alandala", &filteredCountries);
	assert(length == 0);
}

void testFilterByName(Test t)
{
	// Tests the filter by name functionality.

	Country filteredCountries[30];
	int length = filterByCountry(t.service, "", &filteredCountries);

	// Checking if filter by null value returns all the countries.
	assert(length == 10);

	// Checking if filter by non-null value returns the corresponding countries.
	length = filterByCountry(t.service, "den", &filteredCountries);
	for (int i = 0; i < length; ++i)
		assert(strstr(filteredCountries[i].name, "den") != NULL);

	// Checking if filter by non-null unknown value returns void array.
	length = filterByCountry(t.service, "/", &filteredCountries);
	assert(length == 0);
}

void testMigration(Test t)
{
	// Checks the migration simulation functionality.

	// Checking if migration impossible works correctly.
	int result = migrate(t.service, "Romania", "Japan", 100.0);

	assert(result == 0);

	// Checking if migration works correctly.
	Country cSweden = getCountry(t.service, 9);
	Country cJapan = getCountry(t.service, 0);

	double oldPopSwed = cSweden.population;
	double oldPopJap = cJapan.population;

	result = migrate(t.service, "Japan", "Romania", 100.0);

	assert(result == 1);

	// Updating population values.
	Country cSweden1 = getCountry(t.service, 9);
	Country cJapan1 = getCountry(t.service, 0);

	double newPopSwed = cSweden1.population;
	double newPopJap = cJapan1.population;

	assert(oldPopJap - newPopJap == 100);
	assert(newPopSwed - oldPopSwed == 100);
}

void testFilterByContinentAsc(Test t)
{
	// Checks the filter by continent functionality.

	Country filteredCountries[30];

	int length = filterByContinentPopulation(t.service, "", 10, &filteredCountries);

	// Checking if the countries are sorted ascendingly by population.
	for (int i = 0; i < length - 1; ++i)
	{
		assert(filteredCountries[i].population < filteredCountries[i + 1].population);
		assert(filteredCountries[i].population > 10);
	}

	// Checking if filter by non-null continent retrieves the corresponding countries.
	length = filterByContinentPopulation(t.service, "Europe", 10, &filteredCountries);
	for (int i = 0; i < length; ++i)
		assert(strcmp(filteredCountries[i].continent, "Europe") == 0);

	// Checking if filter by unknown continent returns void array.
	length = filterByContinentPopulation(t.service, "alandala", 10, &filteredCountries);
	assert(length == 0);
}

void runTests()
{
	Repository repo;
	repo = createRepository(10);

	UndoManager um;
	um = createUndoManager(10);

	Test t = createTest(&repo, &um);
	
	testAdd(t);
	testDelete(t);
	testUpdate(t);
	testFilterByContinent(t);
	testFilterByName(t);
	testFilterByContinentAsc(t);
	testMigration(t);
}