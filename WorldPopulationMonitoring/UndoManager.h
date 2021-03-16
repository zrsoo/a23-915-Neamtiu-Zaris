#pragma once
#include "Repository.h"

// Structure for implementing freeze state undo/redo

typedef struct {
	// Holds 2 dynamically allocated arrays, each of them
	// keeping states of the repository.

	int nrElemUndo;
	int capUndo;
	Repository* reposUndo;

	int nrElemRedo;
	int capRedo;
	Repository* reposRedo;
} UndoManager;

UndoManager createUndoManager(int cap);
void recordUndo(UndoManager* us, Repository repo);
void recordRedo(UndoManager* us, Repository repo);
Repository undo(UndoManager* us, Repository repoCurrent);
Repository redo(UndoManager* us, Repository repoCurrent);
int undoStackFull(UndoManager um);
int redoStackFull(UndoManager um);
void resizeUndoStack(UndoManager* um);
void resizeRedoStack(UndoManager* um);
void DestroyUndoManager(UndoManager* um);