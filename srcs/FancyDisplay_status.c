#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "FancyDisplay.h"

FancyStatus	FancyStatusList = NULL;
char*		FancyStatusBoxOpen = NULL;
char*		FancyStatusBoxClose = NULL;
int			FancyStatusBoxMargin = 0;

static void		FancyDisplay_linkStatus(FancyStatus new)
{
	FancyStatus	tmp;

	if (FancyStatusList == NULL)
		FancyStatusList = new;
	else
	{
		tmp = FancyStatusList;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	FancyDisplay_addStatus(char *name, int define, FancyClr clr, FancyType type)
{
	FancyStatus	new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return;
	new->name = strdup(name);
	new->value = define;
	new->clr = clr;
	new->typ = type;
	new->next = NULL;
	FancyDisplay_linkStatus(new);
}

static void	FancyDisplay_removeStatus(FancyStatus status)
{
	if (status)
	{
		if (status->next)
			FancyDisplay_removeStatus(status->next);
		free(status->name);
		free(status);
	}
}

void	FancyDisplay_deleteStatus()
{
	FancyDisplay_removeStatus(FancyStatusList);
	if (FancyStatusBoxOpen)
		free(FancyStatusBoxOpen);
	if (FancyStatusBoxClose)
		free(FancyStatusBoxClose);
}

void	FancyDisplay_setStatusBox(char *open, char *close, int margin)
{
	if (FancyStatusBoxOpen)
		free(FancyStatusBoxOpen);
	if (open)
		FancyStatusBoxOpen = strdup(open);
	if (FancyStatusBoxClose)
		free(FancyStatusBoxClose);
	if (close)
		FancyStatusBoxClose = strdup(close);
	FancyStatusBoxMargin = margin;
}


