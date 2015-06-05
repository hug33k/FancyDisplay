# Usage

## FancyMsg

A FancyMsg is a colorful message.

````c
FancyMsg    msg;

/* Create the message
**
** FancyDisplay_newMessage(message, color, style)
*/
msg = FancyDisplay_newMessage("Your message", GREEN, UNDERLINE);

/* Display the message */
FancyDisplay_showMessage(msg);

/* Delete the message */
FancyDisplay_deleteMessage(msg);
````

## FancyInfo

A FancyInfo is a colorful information, based on FancyMsg with a status code.

Before using it, you have to set status informations.

````c
#define STATUS_INFO 42

/* Create a status
**
** FancyDisplay_addStatus(name, macro, color, style)
*/
FancyDisplay_addStatus("INFO", STATUS_INFO, CYAN, BOLD);

#define STATUS_BOX_PAGINATION 1

/* Set the status box
**
** FancyDisplay_setStatusBox(left, right, pagination between box and information)
*/
FancyDisplay_setStatusBox("[", "]", STATUS_BOX_PAGINATION);
````

Then you can use FancyInfo.

````c
FancyInfo    info;

/* Create the information
**
** FancyDisplay_newInfo(message, color, style, macro status)
*/
info = FancyDisplay_newInfo("Hello World", WHITE, NORMAL, 2);

/* Display the information */
FancyDisplay_showInfo(info);

/* Delete the information */
FancyDisplay_deleteInfo(info);
````

## FancyTable

A FancyTable is a colorful table, based on FancyMsg.

````c
FancyTable    table;

/* Create the table
**
** FancyDisplay_newTable(table name, color, style)
*/
table = FancyDisplay_newTable("my_table", BLUE, BOLD);

/* Add a cell
**
** FancyDisplay_newCell(table, messace, color, style, x, y)
*/
FancyDisplay_newCell(table, "value1", GREEN, NORMAL, 0, 0);

/* You can set cells anywhere */
FancyDisplay_newCell(table, "value2", GREEN, NORMAL, 42, 42);

/* Display the table */
FancyDisplay_showTable(table);

/* Display a single row */
FancyDisplay_showCellsRow(table->cells);

/* Display a single column */
FancyDisplay_showCellsColumn(table->cells);

FancyCell     cell;

/* Get a cell
**
** FancyDisplay_getCell(table, x, y)
*/
cell = FancyDisplay_getCell(table, 42, 42);

/* To move through table */
cell = cell->up;
cell = cell->down;
cell = cell->left;
cell = cell->right;
/* If a cell is not set, cell value is NULL */

/* Delete the table */
FancyDisplay_deleteTable(table);

/* Delete all the cells */
FancyDisplay_deleteCells(cell);
/* cell can be any cell from the table */

/* Delete a single cell */
FancyDisplay_deleteCell(cell);

/* Delete a row or a column */
FancyDisplay_deleteCellsRow(cell);
FancyDisplay_deleteCellsColumn(cell);

/* To change table borders
**
** FancyTableBox[0] for top and bottom
** FancyTableBox[1] for corners
** FancyTableBox[2] for left and right
*/
char    *FancyTableBox[3] = {"-", "+", "|"};
````

## FancyCfg

You can enable/disable configuration of FancyDisplay

````c
/* Get the state of a configuration
**
** FancyDisplay_getConfig(configuration)
*/
bool    state;

state = FancyDisplay_getConfig(AUTORM)

/* Set the state of a configuration
**
** FancyDisplay_setConfig(configuration, state)
*/
FancyDisplay_setConfig(AUTORM, TRUE);
````

The state is a boolean (TRUE or FALSE). You can't use "true" or "false", because I don't use stdbool.h (C99 only)

Avaliable configurations :
* AUTORM, to remove automatically a message/information after displayed
