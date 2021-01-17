#include "../inc/output.h"

void print_list(ll_polynome_t *polynome, int flag)
{
    node_t *temp = polynome->head;
    if (flag == derivative)
    {
        while (temp)
        {
            if (temp->pow != -1)
                printf("%d %d ", temp->coeff, temp->pow);
            temp = temp->next;
        }
        printf("L\n");
    }
    else if (flag == just_print)
    {
        while (temp)
        {
            printf("%d %d ", temp->coeff, temp->pow);
            temp = temp->next;
        }
        printf("L\n");
    }
    else if (flag == sum_print)
    {
        while (temp)
        {
            if (temp->coeff != 0)
                printf("%d %d ", temp->coeff, temp->pow);
            temp = temp->next;
        }
        printf("L\n");
    }
}