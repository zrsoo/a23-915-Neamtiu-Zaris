#include "Console.h"
#include <stdio.h>
#include <string.h>

Console createConsole(Service s)
{
	Console c;
	c.s = s;
	return c;
}

void runConsole(Console c)
{
	int command;
	add10Countries(c.s);
	while (1)
	{
		printMenu();
		command = getCommandInput();

		if (command == 1)
		{
			char name[31];
			char continent[31];
			double population;

			printf("\nCountry's name: ");
			scanf_s("%s", name, 30);
			printf("Country's continent: ");
			scanf_s("%s", continent, 30);
			printf("Country's population: ");
			scanf_s("%lf", &population);

			Country country;
			country = createCountry(name, continent, population);

			addCountry(c.s, country);
		}
		else if (command == 2)
		{
			char name[31];
			printf("\nCountry's name: ");
			scanf_s("%s", name, 30);

			deleteCountry(c.s, name);
		}
		else if (command == 3)
		{
			char old_name[31];
			char name[31];
			char continent[31];
			double population;

			printf("\nName of the country that you want to update: ");
			scanf_s("%s", old_name, 31);
			printf("Updated name of the country: ");
			scanf_s("%s", name, 31);
			printf("Updated continent of the country: ");
			scanf_s("%s", continent, 31);
			printf("Updated population of the country: ");
			scanf_s("%lf", &population);

			Country country;
			country = createCountry(name, continent, population);

			updateCountry(c.s, old_name, country);
		}
		else if (command == 4)
		{
			int nr_countries = getNumberCountries(c.s);
			Country* pc = getAllCountries(c.s);

			printf("\nThere are a total of %d countries: \n", nr_countries);
			for (int i = 0; i < nr_countries; ++i)
			{
				printf("%d.) ", i + 1);
				printf(pc[i].name);
				printf(", ");
				printf(pc[i].continent);
				printf(", %lf million\n", pc[i].population);
			}
			printf("\n");
		}
		else if (command == 5)
		{
			Country filteredCountries[100];
			char continent[30];

			printf("\nThe continent you want to filter by: ");
			//scanf_s(" %s", continent, 30);

			char ltr = getchar();
			gets(continent);
			continent[strcspn(continent, "\n")] = 0;

			int nrFilteredCountries = filterByContinent(c.s, continent, &filteredCountries);
			sortAscendingPopulation(nrFilteredCountries, &filteredCountries);

			for (int i = 0; i < nrFilteredCountries; ++i)
			{
				printf("%d.) ", i + 1);
				printf(filteredCountries[i].name);
				printf(", ");
				printf(filteredCountries[i].continent);
				printf(", %lf million\n", filteredCountries[i].population);
			}
			printf("\n");
		}
		else if (command == 6)
		{
			Country filteredCountries[100];
			char country[30];

			printf("\nThe name you want to filter by: ");
			//scanf_s(" %s", continent, 30);

			char ltr = getchar();
			gets(country);
			country[strcspn(country, "\n")] = 0;

			int nrFilteredCountries = filterByCountry(c.s, country, &filteredCountries);
			sortAscendingPopulation(nrFilteredCountries, &filteredCountries);

			for (int i = 0; i < nrFilteredCountries; ++i)
			{
				printf("%d.) ", i + 1);
				printf(filteredCountries[i].name);
				printf(", ");
				printf(filteredCountries[i].continent);
				printf(", %lf million\n", filteredCountries[i].population);
			}
			printf("\n");
		}
		else if (command == 7)
		{
			char name1[30], name2[30];
			double population;

			printf("\nThe country that the people migrate away from: ");
			scanf_s("%s", name1, 30);
			printf("The country that the people migrate to: ");
			scanf_s("%s", name2, 30);
			printf("Number of people migrating: ");
			scanf_s("%lf", &population);

			migrate(c.s, name1, name2, population);
		}
		else if (command == 8)
		{
			Country filteredCountries[100];
			char continent[30];

			printf("\nThe continent you want to filter by: ");
			//scanf_s(" %s", continent, 30);

			char ltr = getchar();
			gets(continent);
			continent[strcspn(continent, "\n")] = 0;

			printf("The minimum population of the countries: ");

			double population;
			scanf_s("%lf", &population);

			int nrFilteredCountries = filterByContinentPopulation(c.s, continent, population, &filteredCountries);
			sortAscendingPopulation(nrFilteredCountries, &filteredCountries);

			for (int i = 0; i < nrFilteredCountries; ++i)
			{
				printf("%d.) ", i + 1);
				printf(filteredCountries[i].name);
				printf(", ");
				printf(filteredCountries[i].continent);
				printf(", %lf million\n", filteredCountries[i].population);
			}
			printf("\n");
		}
		else if (command == 9)
		{
			return;
		}
		else
		{
			printf("Incorrect command.\n");
		}

	}
}

void printMenu()
{
	printf("1. Add a country.\n2. Delete a country.\n3. Update a country.\n4. Display all countries.\n5. Filter countries by continent."
		"\n6. Filter by name (partial string matching).\n7. Simulate migration.\n8. Display all countries on a given continent (if the continent is empty, all countries will be considered),\n"
		"whose populations are greater than a given value, sorted ascending by population.\n"
		"9. Exit\n");
}

int getCommandInput()
{
	int command;
	printf("Command: ");
	scanf_s("%d", &command);
	return command;
}
