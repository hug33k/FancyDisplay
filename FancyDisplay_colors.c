#include <string.h>
#include <unistd.h>
#include "FancyDisplay.h"

static void	FancyDisplay_setRegular(FancyClr clr)
{
	switch (clr)
	{
		case (BLACK):
			SHOW(CLR_BLK);
			break;
		case (RED):
			SHOW(CLR_RED);
			break;
		case (GREEN):
			SHOW(CLR_GRN);
			break;
		case (YELLOW):
			SHOW(CLR_YLW);
			break;
		case (BLUE):
			SHOW(CLR_BLU);
			break;
		case (PURPLE):
			SHOW(CLR_PPL);
			break;
		case (CYAN):
			SHOW(CLR_CYN);
			break;
		case (WHITE):
			SHOW(CLR_WHT);
			break;
		default:
			SHOW(CLR_RST);
	}
}

static void	FancyDisplay_setBold(FancyClr clr)
{
	switch (clr)
	{
		case (BLACK):
			SHOW(CLR_BLK_B);
			break;
		case (RED):
			SHOW(CLR_RED_B);
			break;
		case (GREEN):
			SHOW(CLR_GRN_B);
			break;
		case (YELLOW):
			SHOW(CLR_YLW_B);
			break;
		case (BLUE):
			SHOW(CLR_BLU_B);
			break;
		case (PURPLE):
			SHOW(CLR_PPL_B);
			break;
		case (CYAN):
			SHOW(CLR_CYN_B);
			break;
		case (WHITE):
			SHOW(CLR_WHT_B);
			break;
		default:
			SHOW(CLR_RST);
	}
}

static void	FancyDisplay_setUnderline(FancyClr clr)
{
	switch (clr)
	{
		case (BLACK):
			SHOW(CLR_BLK_U);
			break;
		case (RED):
			SHOW(CLR_RED_U);
			break;
		case (GREEN):
			SHOW(CLR_GRN_U);
			break;
		case (YELLOW):
			SHOW(CLR_YLW_U);
			break;
		case (BLUE):
			SHOW(CLR_BLU_U);
			break;
		case (PURPLE):
			SHOW(CLR_PPL_U);
			break;
		case (CYAN):
			SHOW(CLR_CYN_U);
			break;
		case (WHITE):
			SHOW(CLR_WHT_U);
			break;
		default:
			SHOW(CLR_RST);
	}
}


static void	FancyDisplay_setBackground(FancyClr clr)
{
	switch (clr)
	{
		case (BLACK):
			SHOW(CLR_BLK_BK);
			break;
		case (RED):
			SHOW(CLR_RED_BK);
			break;
		case (GREEN):
			SHOW(CLR_GRN_BK);
			break;
		case (YELLOW):
			SHOW(CLR_YLW_BK);
			break;
		case (BLUE):
			SHOW(CLR_BLU_BK);
			break;
		case (PURPLE):
			SHOW(CLR_PPL_BK);
			break;
		case (CYAN):
			SHOW(CLR_CYN_BK);
			break;
		case (WHITE):
			SHOW(CLR_WHT_BK);
			break;
		default:
			SHOW(CLR_RST);
	}
}

void	FancyDisplay_setColor(FancyClr clr, FancyType type)
{
	switch (type)
	{
		case (NORMAL):
			FancyDisplay_setRegular(clr);
			break;
		case (BOLD):
			FancyDisplay_setBold(clr);
			break;
		case (UNDERLINE):
			FancyDisplay_setUnderline(clr);
			break;
		case (BACKGROUND):
			FancyDisplay_setBackground(clr);
			break;
		default:
			FancyDisplay_setRegular(clr);
	}
}

void	FancyDisplay_resetColor()
{
	SHOW(CLR_RST);
}