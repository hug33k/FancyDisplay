#ifndef FANCY_DISPLAY_H_
# define FANCY_DISPLAY_H_

/*
** Colors
*/

# define CLR_RST	"\e[0m"

/* Regular */
# define CLR_BLK	"\e[0;30m"
# define CLR_RED	"\e[0;31m"
# define CLR_GRN	"\e[0;32m"
# define CLR_YLW	"\e[0;33m"
# define CLR_BLU	"\e[0;34m"
# define CLR_PPL	"\e[0;35m"
# define CLR_CYN	"\e[0;36m"
# define CLR_WHT	"\e[0;37m"

/* Bold */
# define CLR_BLK_B	"\e[1;30m"
# define CLR_RED_B	"\e[1;31m"
# define CLR_GRN_B	"\e[1;32m"
# define CLR_YLW_B	"\e[1;33m"
# define CLR_BLU_B	"\e[1;34m"
# define CLR_PPL_B	"\e[1;35m"
# define CLR_CYN_B	"\e[1;36m"
# define CLR_WHT_B	"\e[1;37m"

/* Underline */
# define CLR_BLK_U	"\e[4;30m"
# define CLR_RED_U	"\e[4;31m"
# define CLR_GRN_U	"\e[4;32m"
# define CLR_YLW_U	"\e[4;33m"
# define CLR_BLU_U	"\e[4;34m"
# define CLR_PPL_U	"\e[4;35m"
# define CLR_CYN_U	"\e[4;36m"
# define CLR_WHT_U	"\e[4;37m"

/* Background */
# define CLR_BLK_BK	"\e[40m"
# define CLR_RED_BK	"\e[41m"
# define CLR_GRN_BK	"\e[42m"
# define CLR_YLW_BK	"\e[43m"
# define CLR_BLU_BK	"\e[44m"
# define CLR_PPL_BK	"\e[45m"
# define CLR_CYN_BK	"\e[46m"
# define CLR_WHT_BK	"\e[47m"

/*
** Types
*/

typedef enum	e_FancyClr
{
	FCLR_BLK,
	FCLR_RED,
	FCLR_GRN,
	FCLR_YLW,
	FCLR_BLU,
	FCLR_PPL,
	FCLR_CYN,
	FCLR_WHT,
}				t_FancyClr;

typedef enum	e_FancyType
{
	FTYP_NRM,
	FTYP_BLD,
	FTYP_NDR,
	FTYP_BKG,
}				t_FancyType;

/*
** Structures
*/

typedef	struct			s_FancyMsg
{
	char				*msg;
	t_FancyClr			clr;
	t_FancyType			typ;
}						t_FancyMsg;

/*
** Typedefs
*/

typedef t_FancyMsg*		FancyMsg;
typedef t_FancyClr		FancyClr;
typedef t_FancyType		FancyType;

/*
** Macros
*/

# define SHOW(clr)	write(1, clr, strlen(clr))

/*
** Functions
*/

/* _base.c */
FancyMsg	FancyDisplay_newMessage(char*, FancyClr, FancyType);
void		FancyDisplay_show(FancyMsg);

/* _colors.c */
void		FancyDisplay_setColor(FancyClr, FancyType);
void		FancyDisplay_resetColor(void);

#endif /* !FANCY_DISPLAY_H_ */
