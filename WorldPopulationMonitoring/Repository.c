#include "Repository.h"
#include <string.h>
#include <stdio.h>

Repository createRepository()
{
	Repository repo;

	repo.nr_countries = 0;

	return repo;
}

int getNumberCountriesRepo(Repository* repo)
{
	return repo->nr_countries;
}

void addCountryRepo(Repository* repo, Country c)
{
	repo->countries[repo->nr_countries] = c;
	repo->nr_countries++;
}

Country* getAllCountriesRepo(Repository* repo)
{
	return repo->countries;
}

void deleteCountryRepo(Repository* repo, char name[])
{
	for (int i = 0; i < repo->nr_countries; ++i)
		if (strcmp(repo->countries[i].name, name) == 0)
		{
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
		}
}

void updateCountryRepo(Repository* repo, char old_name[], Country newC)
{
	for (int i = 0; i < repo->nr_countries; ++i)
		if (strcmp(repo->countries[i].name, old_name) == 0)
			repo->countries[i] = newC;
}
