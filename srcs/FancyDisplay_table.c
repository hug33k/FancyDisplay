#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "FancyDisplay.h"

FancyTable		FancyDisplay_newTable(char *name, FancyClr color, FancyType type)
{
	FancyTable	table;

	if ((table = malloc(sizeof(*table))) == NULL)
		return (NULL);
	table->title = FancyDisplay_newMessage(name, color, type);
	table->cells = NULL;
	table->x = 0;
	table->y = 0;
	return (table);
}

void	FancyDisplay_showTable(FancyTable table)
{
	if (!table || !table->title)
		return;
	FancyDisplay_setColor(table->title->clr, table->title->typ);
	SHOW(table->title->msg);
	FancyDisplay_resetColor();
	SHOW("\n");
	if (table->cells)
		FancyDisplay_showCells(table->cells);
}

void	FancyDisplay_deleteTable(FancyTable table)
{
	if (!table)
		return;
	FancyDisplay_deleteCells(table->cells);
	FancyDisplay_deleteMessage(table->title);
	free(table);
}
