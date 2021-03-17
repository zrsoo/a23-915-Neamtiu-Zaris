#include "Repository.h"
#include "DynamicArray.h">
#include <string.h>
#include <stdio.h>

Repository createRepository(int nrElements)
{
	Repository repo;

	repo.da = createDynamicArray(nrElements);

	return repo;
}

int getNumberCountriesRepo(Repository* repo)
{
	return repo->da.nrElem;
}

void addCountryRepo(Repository* repo, Country c)
{
	addToEnd(&repo->da, c);
}

Country* getAllCountriesRepo(Repository* repo)
{
	return repo->da.ptrarr;
}

Country getCountryRepo(Repository* repo, int index)
{
	return getElement(repo->da, index);
}

void deleteCountryRepo(Repository* repo, char name[])
{
	for (int i = 0; i < repo->da.nrElem; ++i)
		if (strcmp(repo->da.ptrarr[i].name, name) == 0)
		{
			/*
			// If the country to be removed is on the last position, simply decrement the number of countries
			// and the next time the user adds a country, the removed country will be overwritten.
			if (i == repo->nr_countries - 1)
			{
				repo->nr_countries -= 1;
				return;
			}

			// Otherwise, move all the countries located after the country to be removed one position to the "left".
			for (int j = i; j < repo->nr_countries - 1; ++j)
				repo->countries[j] = repo->countries[j + 1];
			*/
			deleteElem(&repo->da, i);
		}
}

void updateCountryRepo(Repository* repo, char old_name[], Country newC)
{
	for (int i = 0; i < repo->da.nrElem; ++i)
		if (strcmp(repo->da.ptrarr[i].name, old_name) == 0)
			updateElement(&repo->da, i, newC);
}

void DestroyDynamicArray(Repository* repo)
{
	Destroy(&repo->da);
}
