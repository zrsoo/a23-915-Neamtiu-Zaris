#include <stdio.h>
#include "Console.h"
#include "Service.h"
#include "Repository.h"
#include "Test.h"

int main()
{
	runTests();

	Repository repo;
	repo = createRepository(10);

	UndoManager um;
	um = createUndoManager(10);

	Service s;
	s = createService(&repo, &um);

	Console c;
	c = createConsole(s);

	runConsole(c);
	DestroyDynamicArray(&repo.da);
	DestroyUndoManager(&um);

	return 0;
}