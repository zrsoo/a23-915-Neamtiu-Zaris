#include "UndoManager.h"

UndoManager createUndoManager(int cap)
{
	UndoManager us;

	us.nrElemUndo = 0;
	us.reposUndo = (Repository*)malloc(cap * sizeof(Repository));

	us.nrElemRedo = 0;
	us.reposRedo = (Repository*)malloc(cap * sizeof(Repository));

	return us;
}

void recordUndo(UndoManager* us, Repository repo)
{
	// Records the state of the repository before a certain operation is performed.

	// If the undo stack is full, resize it.
	if (undoStackFull(*us) == 1)
		resizeUndoStack(us);

	// Then, record operation.
	us->reposUndo[us->nrElemUndo] = repo;
	us->nrElemUndo++;
}

void recordRedo(UndoManager* us, Repository repo)
{
	// Records the state of the repository before a certain operation is undone.

	// If the redo stack is full, resize it.
	if (redoStackFull(*us) == 1)
		resizeRedoStack(us);

	// Then, record operation.
	us->reposRedo[us->nrElemRedo] = repo;
	us->nrElemRedo++;
}

Repository undo(UndoManager* us)
{
	// Returns the repository in a previous state.
	Repository repo = us->reposUndo[us->nrElemUndo];

	// Append the undone repository to the redo stack.
	recordRedo(us, repo);

	// Pop the repository from the undo stack
	us->nrElemUndo--;

	return repo;
}

Repository redo(UndoManager* us)
{
	// Returns the repository in a previously undone state.
	Repository repo = us->reposRedo[us->nrElemRedo];

	// Append the undone repository to the undo stack.
	recordUndo(us, repo);

	// Pop the repository from the redo stack
	us->nrElemRedo--;

	return repo;
}

int undoStackFull(UndoManager um)
{
	// Returns 1 if the undo stack is full, 0 otherwise.
	if (um.nrElemUndo == um.capUndo)
		return 1;

	return 0;
}

int redoStackFull(UndoManager um)
{
	// Returns 1 if the redo stack is full, 0 otherwise.
	if (um.nrElemRedo == um.capRedo)
		return 1;

	return 0;
}

void resizeUndoStack(UndoManager* um)
{
	// Resizes the undo stack, doubling its capacity.
	um->capUndo = um->capUndo * 2;

	// Reallocating memory.
	Repository* newptr = realloc(um->reposUndo, um->capUndo * sizeof(Repository));

	// Pointing to bigger array.
	um->reposUndo = newptr;
}

void resizeRedoStack(UndoManager* um)
{
	// Resizes the redo stack, doubling its capacity.
	um->capRedo = um->capRedo * 2;

	// Reallocating memory.
	Repository* newptr = realloc(um->reposRedo, um->capRedo * sizeof(Repository));

	// Pointing to bigger array.
	um->reposRedo = newptr;
}

void DestroyUndoManager(UndoManager* um)
{
	// Frees up the memory.
	free(um->reposUndo);
	free(um->reposRedo);
}
