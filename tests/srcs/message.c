#include <string.h>
#include "FancyDisplay.h"

int	main()
{
	FancyMsg	msg;

	FancyDisplay_setConfig(AUTORM, TRUE);
	if (FancyDisplay_getConfig(AUTORM))
	{
		msg = FancyDisplay_newMessage("hello", GREEN, NORMAL);
		FancyDisplay_showMessage(msg);
	}
	else
	{
		msg = FancyDisplay_newMessage("world", BLUE, BOLD);
		FancyDisplay_showMessage(msg);
		FancyDisplay_deleteMessage(msg);
	}
	return (0);
}
