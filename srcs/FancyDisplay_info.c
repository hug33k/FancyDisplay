#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "FancyDisplay.h"

static int		FancyDisplay_getStatusBoxSize()
{
	int			max;
	FancyStatus	tmp;

	max = -1;
	if (FancyStatusList)
	{
		tmp = FancyStatusList;
		while (tmp)
		{
			if (max < (int) strlen(tmp->name))
				max = strlen(tmp->name);
			tmp = tmp->next;
		}
	}
	return (max);
}

static FancyStatus	FancyDisplay_getInfoStatus(int value)
{
	FancyStatus		tmp;
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
		(status = FancyDisplay_getInfoStatus(value)) == NULL)
		return;
	SHOW(FancyStatusBoxOpen);
	size -= strlen(status->name);
	pos = (size / 2);
	SHOW_LOOP(" ", pos);
	FancyDisplay_setColor(status->clr, status->typ);
	SHOW(status->name);
	FancyDisplay_resetColor();
	pos = size - (size / 2);
	SHOW_LOOP(" ", pos);
	SHOW(FancyStatusBoxClose);
	pos = FancyStatusBoxMargin;
	SHOW_LOOP(" ", pos);
}

FancyInfo		FancyDisplay_newInfo(char *msg, FancyClr clr, FancyType type, int value)
{
	FancyInfo	new;

	if ((new = malloc(sizeof(*new))) == NULL ||
		(new->msg = FancyDisplay_newMessage(msg, clr, type)) == NULL)
		return (NULL);
	new->value = value;
	return (new);
}

void	FancyDisplay_showInfo(FancyInfo info)
{
	if (!info)
		return;
	FancyDisplay_showStatus(info->value);
	FancyDisplay_showMessage(info->msg);
	if (FancyDisplay_getConfig(AUTORM))
		FancyDisplay_deleteInfo(info);
}

void	FancyDisplay_deleteInfo(FancyInfo info)
{
	if (!info)
		return;
	FancyDisplay_deleteMessage(info->msg);
	free(info);
}