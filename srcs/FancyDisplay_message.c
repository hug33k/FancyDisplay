#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "FancyDisplay.h"

FancyMsg	FancyDisplay_newMessage(char *msg, FancyClr clr, FancyType type)
{
	FancyMsg	new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->msg = strdup(msg);
	new->clr = clr;
	new->typ = type;
	return (new);
}

void	FancyDisplay_showMessage(FancyMsg msg)
{
	if (!msg)
		return;
	FancyDisplay_setColor(msg->clr, msg->typ);
	SHOW(msg->msg);
	FancyDisplay_resetColor();
	SHOW("\n");
	if (FancyDisplay_getConfig(AUTORM))
		FancyDisplay_deleteMessage(msg);
}

void	FancyDisplay_deleteMessage(FancyMsg msg)
{
	if (!msg)
		return;
	free(msg->msg);
	free(msg);
}