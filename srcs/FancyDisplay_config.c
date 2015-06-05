#include "FancyDisplay.h"

bool	FancyConfig[2] = {FALSE, FALSE};

void	FancyDisplay_setConfig(FancyCfg conf, bool status)
{
	if (conf > AUTORM)
		return;
	if (status != FALSE)
		status = TRUE;
	FancyConfig[conf] = status;
}

bool	FancyDisplay_getConfig(FancyCfg conf)
{
	if (conf > AUTORM)
		return (FALSE);
	return (FancyConfig[conf]);
}
