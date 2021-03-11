#include <stdio.h>
#include "Console.h"
#include "Service.h"
#include "DynamicArray.h"

int main()
{
	/*
	Country c;
	c = createCountry("Congo", "Africa", 86.79);

	Repository repo;
	repo = createRepository();

	printf("%d", repo.nr_countries);

	addCountry(&repo, c);

	printf("%d", repo.nr_countries);

	Country* pc = getAllCountries(&repo);

	Country c2;
	c2 = createCountry("Romania", "Europe", 20);

	updateCountry(&repo, "Congo", c2);

	printf(pc[0].name);
	*/

	/*Country c1;
	c1 = createCountry("Romania", "Europe", 21.2);

	Country c2;
	c2 = createCountry("Angola", "Europe", 25.2);

	Country c3;
	c3 = createCountry("Bulgaria", "Europe", 11.2);

	addCountry(s, c1);
	addCountry(s, c2);
	addCountry(s, c3);

	Country* pc = getAllCountries(s);

	printf(pc[0].name);
	printf(pc[1].name);
	printf(pc[2].name);*/

	Repository repo;
	repo = createRepository();

	Service s;
	s = createService(&repo);

	Console c;
	c = createConsole(s);

	runConsole(c);
	

	/*Country c1;
	c1 = createCountry("Romania", "Europe", 21.2);

	DynamicArray da = createDynamicArray(1);
	addToEnd(&da, c1);

	Country cget = getElement(da, 0);

	toString(cget);

	int size = getSize(da);

	printf("\nInitial size: %d", size);

	resizeArray(&da);

	int size2 = getSize(da);

	printf("\nAfter resize: %d", size2);

	Country c2;
	c2 = createCountry("asd", "asd", 21.2);

	addToEnd(&da, c2);

	cget = getElement(da, 1);

	toString(cget);*/

	return 0;
}