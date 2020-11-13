#include "./inc/main.h"

int main()
{    
    int rc = ok;
    string_t *choice;
    choice = get_line();
    if (!choice)
        rc = error;
    else
    {
        if (strcmp(choice->string, POLYNOM_VALUE) == ok)
            rc = polynom_value();
        else if (strcmp(choice->string, POLYNOM_DERIVATIVE) == ok)
            rc = polynom_derivative();
        else if (strcmp(choice->string, POLYNOM_ADDITION) == ok)
            rc = polynom_sum();
        else if (strcmp(choice->string, POLYNOM_DIVISION) == ok)
            rc = polynom_devision();
        else
            rc = error;
        free_string(choice);
    }
    return rc;
}