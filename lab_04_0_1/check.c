#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * usr_strpbrk(const char *str_1, const char *str_2)
{
    if (!str_1 || !str_2)
        return NULL;
    
    int i = 0, j = 0;

    while (str_1[i])
    {
        while (str_2[j])
        {
            if (str_2[j] == str_1[i])
                return (char *)&str_1[i];
            j++;
        }
        j = 0;
        i++;
    }
    return NULL;
}

int usr_strssspn(const char *str_1, const char *str_2)
{
    if (!str_1 || !str_2)
        return 0;
    
    int i = 0, j = 0, k = 0;
    while (str_2[i])
    {
        for (; str_1[j]; j++)
        {
            if (str_2[i] == str_1[j])
            {
                k++;
            }
        }
        j = 0;
        i++;
    }
    return k;
}

int usr_strspn(const char *str_1, const char *str_2)
{
    if (!str_1 || !str_2)
        return 0;

    int i = 0, j = 0;

    while (str_1[i])
    {
        int is_in_str2 = 0;

        while (str_2[j])
        {
            if (str_2[j] == str_1[i])
            {
                is_in_str2 = 1;
                break;
            }
            j++;
        }
        if (is_in_str2 == 0)
            return i;
        else
        {
            j = 0;
            i++;
        }
    }
    return i;
}

int main ()
{
  int i;
  char strtext[] = "time to get it get it tyga";
  char cset[] = "tyga";

  i = usr_strspn (strtext,cset);
  printf ("The initial number has %d digits.\n",i);
  return 0;
}