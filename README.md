# FancyDisplay

FancyDisplay is an easy way to have a colorful display in your terminal.
You can choose your color, your style and write your message with only few lines.

## Usage

````c
FancyMsg    msg;

msg = FancyDisplay_newMessage("Your message", CYAN, BOLD);
FancyDisplay_show(msg);
````

## TODO

* FancyDisplay_printf(char *, ...)
    * Modified printf with %FD flag
* FancyTable
    * Colorful table
* FancyInfo (FancyMsg with status code)
    * Colorful information message

## Informations

* Available colors
    * Black
    * Red
    * Green
    * Yellow
    * Blue
    * Purple
    * Cyan
    * White

* Available modes
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
