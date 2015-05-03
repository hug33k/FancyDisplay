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
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
}				t_FancyClr;

typedef enum	e_FancyType
{
	NORMAL,
	BOLD,
	UNDERLINE,
	BACKGROUND,
}				t_FancyType;

typedef enum	e_FancyCfg
{
	AUTORM = 0,
}				t_FancyCfg;

/*
** Structures
*/

typedef	struct		s_FancyMsg
{
	char			*msg;
	t_FancyClr		clr;
	t_FancyType		typ;
}					t_FancyMsg;

typedef struct			s_FancyStatus
{
	char					*name;
	int						value;
	t_FancyClr				clr;
	t_FancyType				typ;
	struct s_FancyStatus	*next;
}							t_FancyStatus;

typedef struct		s_FancyInfo
{
	t_FancyMsg*		msg;
	int				value;
}					t_FancyInfo;

/*
** Typedefs
*/

typedef t_FancyMsg*		FancyMsg;
typedef t_FancyClr		FancyClr;
typedef t_FancyType		FancyType;
typedef t_FancyStatus*	FancyStatus;
typedef t_FancyInfo*	FancyInfo;
typedef t_FancyCfg		FancyCfg;
typedef int				bool;

/*
** Macros
*/

# define SHOW(clr)			write(1, clr, strlen(clr))

# define TRUE				1
# define FALSE				!TRUE

/*
** Global variables
*/
extern FancyStatus	FancyStatusList;
extern char*		FancyStatusBoxOpen;
extern char*		FancyStatusBoxClose;
extern int			FancyStatusBoxMargin;
extern bool			FancyConfig[1];

/*
** Functions
*/

/* _message.c */
FancyMsg	FancyDisplay_newMessage(char*, FancyClr, FancyType);
void		FancyDisplay_showMessage(FancyMsg);
void		FancyDisplay_deleteMessage(FancyMsg);

/* _color.c */
void		FancyDisplay_setColor(FancyClr, FancyType);
void		FancyDisplay_resetColor(void);

/* _status.c */
void		FancyDisplay_addStatus(char*, int, FancyClr, FancyType);
void		FancyDisplay_deleteStatus(void);
void		FancyDisplay_setStatusBox(char*, char*, int);

/*  _info.c */
FancyInfo	FancyDisplay_newInfo(char*, FancyClr, FancyType, int);
void		FancyDisplay_showInfo(FancyInfo);
void		FancyDisplay_deleteInfo(FancyInfo);

/* _config.c */
void		FancyDisplay_setConfig(FancyCfg, bool);
bool		FancyDisplay_getConfig(FancyCfg);

#endif /* !FANCY_DISPLAY_H_ */
