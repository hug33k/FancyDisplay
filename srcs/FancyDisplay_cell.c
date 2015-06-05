#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "FancyDisplay.h"

char	*FancyTableBox[3] = {"-", "+", "|"};

static FancyCell	FancyDisplay_newEmptyCell(FancyTable, unsigned int, unsigned int);

static FancyCell	FancyDisplay_getHeadColumnCell(FancyCell cell)
{
	FancyCell	tmp;

	if (cell == NULL)
		return (NULL);
	tmp = cell;
	while (tmp != NULL && tmp->y != 0)
		tmp = tmp->up;
	return (tmp);
}

static FancyCell	FancyDisplay_getHeadRowCell(FancyCell cell)
{
	FancyCell	tmp;

	if (cell == NULL)
		return (NULL);
	tmp = cell;
	while (tmp != NULL && tmp->x != 0)
		tmp = tmp->left;
	return (tmp);
}

static FancyCell	FancyDisplay_getOriginCell(FancyCell cell)
{
	return (FancyDisplay_getHeadRowCell(FancyDisplay_getHeadColumnCell(cell)));
}

static void		FancyDisplay_patchCellsRow(FancyTable table, FancyCell cell)
{
	FancyCell	tmp;

	if (!table)
		return;
	tmp = cell;
	while (tmp && tmp->x != 0)
	{
		if (!tmp->left)
		{
			if ((tmp->left = FancyDisplay_getCell(table, tmp->x - 1, tmp->y)))
				tmp->left->right = tmp;
			else
				tmp->left = FancyDisplay_newEmptyCell(table, tmp->x - 1, tmp->y);
		}
		tmp = tmp->left;
	}
}

static void		FancyDisplay_patchCellsColumn(FancyTable table, FancyCell cell)
{
	FancyCell	tmp;

	if (!table)
		return;
	tmp = cell;
	while (tmp && tmp->y != 0)
	{
		if (!tmp->up)
		{
			if ((tmp->up = FancyDisplay_getCell(table, tmp->x, tmp->y - 1)))
				tmp->up->down = tmp;
			else
				tmp->up = FancyDisplay_newEmptyCell(table, tmp->x, tmp->y - 1);
		}
		tmp = tmp->up;
	}
}

static FancyCell	FancyDisplay_newEmptyCell(FancyTable table, unsigned int x, unsigned int y)
{
	FancyCell		cell;

	if (!table)
		return (NULL);
	if ((cell = FancyDisplay_getCell(table, x, y)) != NULL)
		return (cell);
	if ((cell = malloc(sizeof(*cell))) == NULL)
		return (NULL);
	cell->x = x;
	cell->y = y;
	if (x > 0 && y > 0)
		cell->type = CELL;
	else if (x > 0)
		cell->type = TTL_COL;
	else
		cell->type = TTL_ROW;
	cell->left = NULL;
	cell->right = NULL;
	cell->up = NULL;
	cell->down = NULL;
	cell->value = NULL;
	FancyDisplay_patchCellsRow(table, cell);
	FancyDisplay_patchCellsColumn(table, cell);
	if ((cell->left = FancyDisplay_getCell(table, x - 1, y)))
		cell->left->right = cell;
	if ((cell->right = FancyDisplay_getCell(table, x + 1, y)))
		cell->right->left = cell;
	if ((cell->up = FancyDisplay_getCell(table, x, y - 1)))
		cell->up->down = cell;
	if ((cell->down = FancyDisplay_getCell(table, x, y + 1)))
		cell->down->up = cell;
	if (x == 0 && y == 0)
		table->cells = cell;
	return (cell);
}

static unsigned int	FancyDisplay_getNbCellsInRow(FancyCell cell)
{
	FancyCell		tmp;
	unsigned int	nb;

	tmp = cell;
	nb = 0;
	while (tmp)
	{
		nb++;
		tmp = tmp->right;
	}
	return (nb);
}

static unsigned int	FancyDisplay_getNbCellsInAllRow(FancyCell cell)
{
	FancyCell		tmp;
	unsigned int	nb;
	unsigned int	nb_tmp;

	tmp = cell;
	nb = 0;
	while (tmp)
	{
		nb_tmp = FancyDisplay_getNbCellsInRow(tmp);
		if (nb_tmp > nb)
			nb = nb_tmp;
		tmp = tmp->down;
	}
	return (nb);
}

/*
static unsigned int	FancyDisplay_getNbCellsInColumn(FancyCell cell)
{
	FancyCell		tmp;
	unsigned int	nb;

	tmp = cell;
	nb = 0;
	while (tmp)
	{
		nb++;
		tmp = tmp->down;
	}
	return (nb);
}
*/
static void		FancyDisplay_showCellInline(FancyCell cell)
{
	if (!cell || !cell->value)
		return;
	FancyDisplay_setColor(cell->value->clr, cell->value->typ);
	SHOW(cell->value->msg);
	FancyDisplay_resetColor();
}

static unsigned int	FancyDisplay_getCellsMaxWidth(FancyCell cell)
{
	unsigned int	size;
	FancyCell		tmp;
	char			buffer[10];

	if (!cell)
		return (0);
	tmp = cell;
	sprintf(buffer, "COL %u", tmp->x);
	size = strlen(buffer);
	while (tmp)
	{
		if (tmp->value && size < strlen(tmp->value->msg))
			size = strlen(tmp->value->msg);
		tmp = tmp->down;
	}
	return (size);
}

static void			FancyDisplay_showCellsRowBorder(FancyCell cell, bool title, bool horizontal_align)
{
	char			buffer[10];
	int				loop;
	int				size;
	unsigned int	nb_columns;
	FancyCell		tmp;
	FancyCell		header;

	if (!cell)
		return;
	tmp = cell;
	sprintf(buffer, "ROW %u", tmp->y);
	loop = (title ? strlen(buffer) : 0);
	SHOW_LOOP(" ", loop);
	while (tmp)
	{
		SHOW(FancyTableBox[1]);
		if (horizontal_align)
		{
			header = FancyDisplay_getHeadColumnCell(tmp);
			loop = FancyDisplay_getCellsMaxWidth(header);
			if (!tmp->right)
				nb_columns = FancyDisplay_getNbCellsInAllRow(header);
		}
		else
			loop = (tmp->value ? strlen(tmp->value->msg) : 0);
		SHOW_LOOP(FancyTableBox[0], loop);
		tmp = tmp->right;
	}
	if (horizontal_align)
	{
		while (--nb_columns > 0)
		{
			SHOW(FancyTableBox[1]);
			size = FancyDisplay_getCellsMaxWidth(header);
			SHOW_LOOP(FancyTableBox[0], size);
		}
	}
	SHOW(FancyTableBox[1]);
	SHOW("\n");
}

static void			FancyDisplay_showCellsColumnTitle(FancyCell cell)
{
	unsigned int	size;
	char			buffer[10];

	if (!cell)
		return;
	size = FancyDisplay_getCellsMaxWidth(cell);
	sprintf(buffer, "COL %u", cell->x);
	size -= strlen(buffer);
	size = (size / 2) + (size % 2);
	SHOW_LOOP(" ", size);
	SHOW(buffer);
	SHOW("\n");
}

static void		FancyDisplay_showCellsRowRaw(FancyCell cell, bool title, bool second_border, bool fill_lines)
{
	FancyCell	tmp;
	FancyCell	header;
	char		buffer[10];
	int			size;
	int			nb_columns;

	if (!cell)
		return;
	tmp = FancyDisplay_getHeadRowCell(cell);
	FancyDisplay_showCellsRowBorder(tmp, title, fill_lines);
	sprintf(buffer, "ROW %u", tmp->y);
	if (title)
		SHOW(buffer);
	while (tmp)
	{
		header = FancyDisplay_getHeadColumnCell(tmp);
		SHOW(FancyTableBox[2]);
		FancyDisplay_showCellInline(tmp);
		if (fill_lines)
		{
			size = FancyDisplay_getCellsMaxWidth(header) - (tmp->value ? strlen(tmp->value->msg) : 0);
			SHOW_LOOP(" ", size);
			if (!tmp->right)
				nb_columns = FancyDisplay_getNbCellsInAllRow(header);
		}
		tmp = tmp->right;
	}
	if (fill_lines)
	{
		while (--nb_columns > 0)
		{
			SHOW(FancyTableBox[2]);
			size = FancyDisplay_getCellsMaxWidth(header);
			SHOW_LOOP(" ", size);
		}
	}
	SHOW(FancyTableBox[2]);
	SHOW("\n");
	if (second_border)
		FancyDisplay_showCellsRowBorder(FancyDisplay_getHeadRowCell(cell), title, fill_lines);
}

static void			FancyDisplay_showCellsColumnRaw(FancyCell cell)
{
	FancyCell		tmp;
	unsigned int	width;
	unsigned int	pos;

	if (!cell)
		return;
	tmp = FancyDisplay_getHeadColumnCell(cell);
	width = FancyDisplay_getCellsMaxWidth(tmp);
	while (tmp)
	{
		SHOW(FancyTableBox[1]);
		pos = width;
		SHOW_LOOP(FancyTableBox[0], pos);
		SHOW(FancyTableBox[1]);
		SHOW("\n");
		SHOW(FancyTableBox[2]);
		FancyDisplay_showCellInline(tmp);
		pos = width - (tmp->value ? strlen(tmp->value->msg) : 0);
		SHOW_LOOP(" ", pos);
		SHOW(FancyTableBox[2]);
		SHOW("\n");
		tmp = tmp->down;
	}
	SHOW(FancyTableBox[1]);
	pos = width;
	SHOW_LOOP(FancyTableBox[0], pos);
	SHOW(FancyTableBox[1]);
	SHOW("\n");
}

static void		FancyDisplay_showCellRaw(FancyCell cell, bool title)
{
	char	buffer[15];

	if (!cell)
		return;
	sprintf(buffer, "(%u;%u)", cell->x, cell->y);
	if (title)
		SHOW(buffer);
	FancyDisplay_showCellInline(cell);
	SHOW("\n");
}

FancyCell		FancyDisplay_newCell(FancyTable table, char* value, FancyClr color, FancyType type, unsigned int x, unsigned int y)
{
	FancyCell	cell;

	if (!table || (cell = FancyDisplay_newEmptyCell(table, x, y)) == NULL)
		return (NULL);
	cell->value = FancyDisplay_newMessage(value, color, type);
	return (cell);
}

FancyCell		FancyDisplay_getCell(FancyTable table, unsigned int x, unsigned int y)
{
	FancyCell	tmp;

	if (!table)
		return (NULL);
	tmp = table->cells;
	while (tmp && tmp->x < x)
		tmp = tmp->right;
	while (tmp && tmp->y < y)
		tmp = tmp->down;
	return (tmp);
}

void		FancyDisplay_showCell(FancyCell cell)
{
	if (cell)
		FancyDisplay_showCellRaw(cell, TRUE);
}

void			FancyDisplay_showCellsRow(FancyCell cell)
{
	if (cell)
		FancyDisplay_showCellsRowRaw(cell, TRUE, TRUE, FALSE);
}

void			FancyDisplay_showCellsColumn(FancyCell cell)
{
	FancyCell		tmp;

	if (!cell)
		return;
	tmp = FancyDisplay_getHeadColumnCell(cell);
	FancyDisplay_showCellsColumnTitle(tmp);
	FancyDisplay_showCellsColumnRaw(tmp);
}

void			FancyDisplay_showCells(FancyCell cell)
{
	FancyCell	tmp;

	tmp = cell;
	while (tmp)
	{
		if (tmp->down)
			FancyDisplay_showCellsRowRaw(tmp, FALSE, FALSE, TRUE);
		else
			FancyDisplay_showCellsRowRaw(tmp, FALSE, TRUE, TRUE);
		tmp = tmp->down;
	}
}

void		FancyDisplay_deleteCell(FancyCell cell)
{
	if (!cell)
		return;
	FancyDisplay_deleteMessage(cell->value);
	if (cell->left)
		cell->left->right = NULL;
	if (cell->right)
		cell->right->left = NULL;
	if (cell->up)
		cell->up->down = NULL;
	if (cell->down)
		cell->down->up = NULL;
	free(cell);
}

void			FancyDisplay_deleteCells(FancyCell cell)
{
	FancyCell	origin;
	FancyCell	tmp;

	if (!cell)
		return;
	origin = FancyDisplay_getOriginCell(cell);
	tmp = origin;
	while (tmp)
	{
		origin = origin->right;
		FancyDisplay_deleteCellsColumn(tmp);
		tmp = origin;
	}
}

void			FancyDisplay_deleteCellsRow(FancyCell cell)
{
	FancyCell	origin;
	FancyCell	tmp;

	if (!cell)
		return;
	origin = FancyDisplay_getHeadRowCell(cell);
	tmp = origin;
	while (tmp)
	{
		origin = origin->right;
		FancyDisplay_deleteCell(tmp);
		tmp = origin;
	}
}

void		FancyDisplay_deleteCellsColumn(FancyCell cell)
{
	FancyCell	origin;
	FancyCell	tmp;

	if (!cell)
		return;
	origin = FancyDisplay_getHeadColumnCell(cell);
	tmp = origin;
	while (tmp)
	{
		origin = origin->down;
		FancyDisplay_deleteCell(tmp);
		tmp = origin;
	}
}
