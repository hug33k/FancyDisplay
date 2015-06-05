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
	TABINDX,
}				t_FancyCfg;

typedef enum	e_FancyCellType
{
	TTL_COL,
	TTL_ROW,
	CELL,
}				t_FancyCellType;

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

typedef struct			s_FancyCell
{
	t_FancyMsg			*value;
	t_FancyCellType		type;
	unsigned int		x;
	unsigned int		y;
	struct s_FancyCell	*left;
	struct s_FancyCell	*right;
	struct s_FancyCell	*up;
	struct s_FancyCell	*down;
}						t_FancyCell;

typedef struct		s_FancyTable
{
	t_FancyMsg		*title;
	t_FancyCell		*cells;
	unsigned int	x;
	unsigned int	y;
}					t_FancyTable;

/*
** Typedefs
*/

typedef t_FancyMsg*		FancyMsg;
typedef t_FancyClr		FancyClr;
typedef t_FancyType		FancyType;
typedef t_FancyStatus*	FancyStatus;
typedef t_FancyInfo*	FancyInfo;
typedef t_FancyCfg		FancyCfg;
typedef t_FancyCell*	FancyCell;
typedef t_FancyTable*	FancyTable;
typedef int				bool;

/*
** Macros
*/

# define SHOW(clr)			write(1, clr, strlen(clr))
# define SHOW_LOOP(c, n)	while(n--)SHOW(c);

# define TRUE				1
# define FALSE				!TRUE

/*
** Global variables
*/
extern FancyStatus	FancyStatusList;
extern char*		FancyStatusBoxOpen;
extern char*		FancyStatusBoxClose;
extern char			*FancyTableBox[3];
extern int			FancyStatusBoxMargin;
extern bool			FancyConfig[2];

/*
** Functions
*/

/* _message.c */
FancyMsg			FancyDisplay_newMessage(char*, FancyClr, FancyType);
void				FancyDisplay_showMessage(FancyMsg);
void				FancyDisplay_deleteMessage(FancyMsg);

/* _status.c */
void				FancyDisplay_addStatus(char*, int, FancyClr, FancyType);
void				FancyDisplay_deleteStatus(void);
void				FancyDisplay_setStatusBox(char*, char*, int);

/*  _info.c */
FancyInfo			FancyDisplay_newInfo(char*, FancyClr, FancyType, int);
void				FancyDisplay_showInfo(FancyInfo);
void				FancyDisplay_deleteInfo(FancyInfo);

/* _cell.c */
FancyCell			FancyDisplay_newCell(FancyTable, char*, FancyClr, FancyType, unsigned int, unsigned int);
FancyCell			FancyDisplay_getCell(FancyTable, unsigned int, unsigned int);
void				FancyDisplay_showCell(FancyCell);
void				FancyDisplay_showCells(FancyCell);
void				FancyDisplay_showCellsRow(FancyCell);
void				FancyDisplay_showCellsColumn(FancyCell);
void				FancyDisplay_deleteCell(FancyCell);
void				FancyDisplay_deleteCells(FancyCell);
void				FancyDisplay_deleteCellsRow(FancyCell);
void				FancyDisplay_deleteCellsColumn(FancyCell);

/* _table.c */
FancyTable			FancyDisplay_newTable(char *, FancyClr, FancyType);
void				FancyDisplay_showTable(FancyTable);
void				FancyDisplay_deleteTable(FancyTable);

/* _color.c */
void				FancyDisplay_setColor(FancyClr, FancyType);
void				FancyDisplay_resetColor(void);

/* _config.c */
void				FancyDisplay_setConfig(FancyCfg, bool);
bool				FancyDisplay_getConfig(FancyCfg);

#endif /* !FANCY_DISPLAY_H_ */
