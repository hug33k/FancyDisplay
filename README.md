# FancyDisplay

FancyDisplay is an easy way to have a colorful display in your terminal.
You can choose your color, your style and write your message with only few lines.

## Usage

````c
FancyMsg    msg;

msg = FancyDisplay_newMessage("Your message", CYAN, BOLD);
FancyDisplay_showMessage(msg);
````

You can see more [here](https://github.com/hug33k/FancyDisplay/blob/master/USAGE.md)

## Tests

You can find code examples in tests folder.

````bash
make test
./tests/bins/[TEST NAME]
````

## Informations

* Available modes
    * FancyMsg
    * FancyInfo (Works with FancyStatus)
    * FancyTable

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

## TODO

* FancyDisplay_printf(char *, ...)
    * Modified printf with %FD flag
