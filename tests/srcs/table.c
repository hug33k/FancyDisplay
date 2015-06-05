#include <string.h>
#include "FancyDisplay.h"

int	main()
{
	FancyTable	table;

	table = FancyDisplay_newTable("my_table", BLUE, BOLD);
	FancyDisplay_showCell(table->cells);
	FancyDisplay_newCell(table, "value1", GREEN, NORMAL, 0, 0);
	FancyDisplay_newCell(table, "value2", GREEN, NORMAL, 0, 1);
	FancyDisplay_newCell(table, "value3", GREEN, NORMAL, 1, 0);
	FancyDisplay_newCell(table, "value4", GREEN, NORMAL, 2, 0);
	FancyDisplay_showTable(table);
	FancyDisplay_showCellsRow(table->cells->down);
	FancyDisplay_showCellsColumn(table->cells);
	FancyDisplay_deleteTable(table);
	return (0);
}
