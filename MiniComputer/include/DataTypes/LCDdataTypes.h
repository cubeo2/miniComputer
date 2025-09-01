#pragma once
#include <Config.h>

/*
This file contains data types used for the LCD menu system in the Mini Computer project.
*/

// LCD Menu Option Structure. It holds the position of the cursor and the text to be displayed for that option.
struct Option
{
    byte cursorPos[2];
    char word[16];

    Option(byte posx = 0, byte posy = 0, const char *text = "")
    {
        cursorPos[0] = posx;
        cursorPos[1] = posy;
        strncpy(word, text, sizeof(word));
        word[sizeof(word) - 1] = '\0';
    }
};

// Menu Structure. It contains an array of options, the count of those options, and the currently selected option.
struct Menu
{
    Option *options;
    byte optionCount;
    byte currentOption;

    Menu(Option *opts)
    {
        options = opts;
        optionCount = sizeof(opts) / sizeof(opts[0]);
        currentOption = 0;
    }

    void nextOption()
    {
        if (currentOption < optionCount - 1)
        {
            currentOption++;
        }
    }
    void previousOption()
    {
        if (currentOption > 0)
        {
            currentOption--;
        }
    }
    byte* getCursorPos() {
        return options[currentOption].cursorPos;
    }
};
