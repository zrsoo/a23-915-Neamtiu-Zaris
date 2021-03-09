#include "Service.h"

Service createService(Repository* repo)
{
	Service s;
	s.repo = repo;
	return  s;
}

void addCountry(Service s, Country c)
{
	addCountryRepo(s.repo, c);
}

void deleteCountry(Service s, char name[])
{
	deleteCountryRepo(s.repo, name);
}

void updateCountry(Service s, char old_name[], Country newC)
{
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
