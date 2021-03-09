#pragma once

typedef struct {
	char name[31];
	char continent[31];
	double population;
} Country;


Country createCountry(char name[], char continent[], double population);
char* getName(Country* c);
char* getContinent(Country* c);
int getPopulation(Country* c);
void toString(Country c);