#include <string.h>
#include <unistd.h>
#include "FancyDisplay.h"

static void	FancyDisplay_setRegular(FancyClr clr)
{
	switch (clr)
	{
		case (FCLR_BLK):
			SHOW(CLR_BLK);
			break;
		case (FCLR_RED):
			SHOW(CLR_RED);
			break;
		case (FCLR_GRN):
			SHOW(CLR_GRN);
			break;
		case (FCLR_YLW):
			SHOW(CLR_YLW);
			break;
		case (FCLR_BLU):
			SHOW(CLR_BLU);
			break;
		case (FCLR_PPL):
			SHOW(CLR_PPL);
			break;
		case (FCLR_CYN):
			SHOW(CLR_CYN);
			break;
		case (FCLR_WHT):
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
		case (FCLR_BLK):
			SHOW(CLR_BLK_B);
			break;
		case (FCLR_RED):
			SHOW(CLR_RED_B);
			break;
		case (FCLR_GRN):
			SHOW(CLR_GRN_B);
			break;
		case (FCLR_YLW):
			SHOW(CLR_YLW_B);
			break;
		case (FCLR_BLU):
			SHOW(CLR_BLU_B);
			break;
		case (FCLR_PPL):
			SHOW(CLR_PPL_B);
			break;
		case (FCLR_CYN):
			SHOW(CLR_CYN_B);
			break;
		case (FCLR_WHT):
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
		case (FCLR_BLK):
			SHOW(CLR_BLK_U);
			break;
		case (FCLR_RED):
			SHOW(CLR_RED_U);
			break;
		case (FCLR_GRN):
			SHOW(CLR_GRN_U);
			break;
		case (FCLR_YLW):
			SHOW(CLR_YLW_U);
			break;
		case (FCLR_BLU):
			SHOW(CLR_BLU_U);
			break;
		case (FCLR_PPL):
			SHOW(CLR_PPL_U);
			break;
		case (FCLR_CYN):
			SHOW(CLR_CYN_U);
			break;
		case (FCLR_WHT):
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
		case (FCLR_BLK):
			SHOW(CLR_BLK_BK);
			break;
		case (FCLR_RED):
			SHOW(CLR_RED_BK);
			break;
		case (FCLR_GRN):
			SHOW(CLR_GRN_BK);
			break;
		case (FCLR_YLW):
			SHOW(CLR_YLW_BK);
			break;
		case (FCLR_BLU):
			SHOW(CLR_BLU_BK);
			break;
		case (FCLR_PPL):
			SHOW(CLR_PPL_BK);
			break;
		case (FCLR_CYN):
			SHOW(CLR_CYN_BK);
			break;
		case (FCLR_WHT):
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
		case (FTYP_NRM):
			FancyDisplay_setRegular(clr);
			break;
		case (FTYP_BLD):
			FancyDisplay_setBold(clr);
			break;
		case (FTYP_NDR):
			FancyDisplay_setUnderline(clr);
			break;
		case (FTYP_BKG):
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