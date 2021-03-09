#pragma once
#include "Service.h"

typedef struct {
	Service s;
} Console;

Console createConsole(Service s);
void runConsole(Console c);
void printMenu();
int getCommandInput();