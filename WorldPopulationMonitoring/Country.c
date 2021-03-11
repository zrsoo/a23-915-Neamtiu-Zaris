#include "Country.h"
#include <stdio.h>
#include <string.h>

Country createCountry(char name[], char continent[], double population)
{
	Country c;
	strcpy_s(c.name, 30, name);
	strcpy_s(c.continent, 30, continent);
	c.population = population;

	return c;
}

char* getName(Country* c)
{
	return c->name;
}

char* getContinent(Country* c)
{
	return c->continent;
}

double getPopulation(Country* c)
{
	return c->population;
}

void toString(Country c)
{
	printf("%s, %s, %f", c.name, c.continent, c.population);
}

