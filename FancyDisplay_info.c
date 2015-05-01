#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "FancyDisplay.h"

static int		FancyDisplay_getStatusBoxSize()
{
	int			max;
	FancyStatus	tmp;

	max = -1;
	if (!FancyStatusList)
		return (-1);
	tmp = FancyStatusList;
	while (tmp)
	{
		if (max < (int) strlen(tmp->name))
			max = strlen(tmp->name);
		tmp = tmp->next;
	}
	return (max);
}

static FancyStatus	FancyDisplay_getStatus(int value)
{
	FancyStatus		tmp;
	if (!FancyStatusList)
		return (NULL);
	tmp = FancyStatusList;
	while (tmp && tmp->value != value)
		tmp = tmp->next;
	return (tmp);
}

static void		FancyDisplay_showStatus(int value)
{
	int			size;
	int			pos;
	FancyStatus	status;

	if ((size = FancyDisplay_getStatusBoxSize()) == -1 ||
		(status = FancyDisplay_getStatus(value)) == NULL)
		return;
	SHOW(FancyStatusBoxOpen);
	size -= strlen(status->name);
	pos = 0;
	while (pos++ < (size / 2))
		SHOW(" ");
	FancyDisplay_setColor(status->clr, status->typ);
	SHOW(status->name);
	FancyDisplay_resetColor();
	while (pos++ <= size)
		SHOW(" ");
	SHOW(FancyStatusBoxClose);
	pos = 0;
	while (pos++ < FancyStatusBoxMargin)
		SHOW(" ");
}

FancyInfo		FancyDisplay_newInfo(char *msg, FancyClr clr, FancyType type, int value)
{
	FancyInfo	new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return (NULL);
	if ((new->msg = FancyDisplay_newMessage(msg, clr, type)) == NULL)
		return (NULL);
	new->value = value;
	return (new);
}

void	FancyDisplay_showInfo(FancyInfo info)
{
	FancyDisplay_showStatus(info->value);
	FancyDisplay_showMessage(info->msg);
}

void	FancyDisplay_deleteInfo(FancyInfo info)
{
	if (!info)
		return;
	FancyDisplay_deleteMessage(info->msg);
	free(info);
}