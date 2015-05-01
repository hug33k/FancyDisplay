# FancyDisplay

FancyDisplay is an easy way to have a colorful display in your terminal.
You can choose your color, your style and write your message with only few lines.

## Usage

````c
FancyMsg    msg;

msg = FancyDisplay_newMessage("Your message", CYAN, BOLD);
FancyDisplay_show(msg);
````

usage.c is comming soon...

## TODO

* FancyDisplay_printf(char *, ...)
    * Modified printf with %FD flag
* FancyTable
    * Colorful table

## Informations

* Available modes
    * FancyMsg
    * FancyInfo (Works with FancyStatus)

* Available colors
    * Black
    * Red
    * Green
    * Yellow
    * Blue
    * Purple
    * Cyan
    * White

* Available types
    * Normal
    * Bold
    * Underline
    * Background

* Used functions
    * write
    * malloc/free
    * strdup
    * strlen

* Used includes
    * unistd.h
    * stdlib.h
    * string.h
