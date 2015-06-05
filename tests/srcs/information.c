#include <string.h>
#include "FancyDisplay.h"

int	main()
{
	FancyInfo	info;

	FancyDisplay_addStatus("  One ", 1, BLUE, NORMAL);
	FancyDisplay_addStatus("Two", 2, RED, NORMAL);
	FancyDisplay_setStatusBox(NULL, "<-", 2);
	info = FancyDisplay_newInfo("Info", WHITE, NORMAL, 2);
	FancyDisplay_showInfo(info);
	FancyDisplay_deleteInfo(info);
	info = FancyDisplay_newInfo("Info", WHITE, NORMAL, 1);
	FancyDisplay_showInfo(info);
	FancyDisplay_deleteInfo(info);
	info = FancyDisplay_newInfo("Info", WHITE, NORMAL, 1);
	FancyDisplay_showInfo(info);
	FancyDisplay_deleteInfo(info);
	info = FancyDisplay_newInfo("Info", WHITE, NORMAL, 2);
	FancyDisplay_showInfo(info);
	FancyDisplay_deleteInfo(info);
	FancyDisplay_deleteStatus();
	return (0);
}
