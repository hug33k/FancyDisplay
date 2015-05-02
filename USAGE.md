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
** FancyDisplay_setStatusBox(left, right, pagination)
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