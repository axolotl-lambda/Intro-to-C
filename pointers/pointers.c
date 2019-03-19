#include <stdio.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    while (*x != '\0')
    {
        *y = *x;
        x++;
        y++;
    }
    *y = '\n';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    char *address = NULL;
    while (*str != '\0')
    {
        if (*str == c)
        {
            address = str;
            break;
        }
        str++;
    }
    return address;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    char *address = NULL;
    char *seeker = NULL;
    int match = 0;
    while (*haystack != '\0')
    {
        if ((!match && *haystack == *needle) || (match))
        {
            if (!match)
            {
                address = haystack;
                seeker = needle;
                match = 1;
            }
            if (*(seeker + 1) == '\0')
            {
                return address;
            }
            if (*haystack != *seeker)
            {
                match = 0;
            }
            seeker++;
            haystack++;
        }
        else
        {
            if (match)
            {
                match = 0;
            }
            else
            {
                address = NULL;
                haystack++;
            }
        }
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    // char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    // printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
