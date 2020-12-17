#include "main.h"

int main()
{
    linked_list *list = create_ll();
    char *name, *sub_name;
    int x, choice;
    if (list)
    {
        do
        {
            printf("1 : Add node\n2 : Delete last node\n3 : display elements\n4 : Exit\n");
            if (fscanf(stdin, "%d", &choice) == 1 && (choice < 1 || choice > 4))
            {
                puts("incorect choice: try again");
                break;
            }
            if (choice == 4)
            {
                break;
            }
            clear_stream();
            switch (choice)
            {
            case 1:
            {
                puts("Enter Name and age:");
                if ((name = get_str()) != NULL && fscanf(stdin, "%d", &x) == 1)
                {
                    if (push_back(list, create_ll_node(name, x, NULL)) == error)
                    {
                        puts("memeory allocation error: try again");
                    }
                    else 
                    {
                        linked_list *temp = create_ll();
                        if (temp)
                        {
                            puts("Enter the number of subject: ");
                            int num_of_subs;
                            if (fscanf(stdin, "%d", &num_of_subs) == 1 && num_of_subs > 0)
                            {
                                clear_stream();
                                for (int i = 0; i < num_of_subs; i++)
                                {
                                    printf("Sub no[%d]: name and mark\n", i + 1);
                                    // clear_stream();
                                    if ((sub_name = get_str()) != NULL && fscanf(stdin, "%d", &x) == 1)
                                    {
                                        if (push_back(temp, create_ll_node(sub_name, x, NULL)) == error)
                                        {
                                            puts("memeory allocation error: try again");
                                        }
                                        free(sub_name);
                                    }
                                    else
                                    {
                                        puts("Memory alloc error!");
                                        break;
                                    }
                                    clear_stream();
                                }
                            }
                            else if (num_of_subs != 0)
                            {
                                puts("incorrect input!");
                            }
                            list->end->mark = temp->head;
                            free(temp);
                        }
                        else
                        {
                            puts("memoy alloc error!");
                        }
                    }
                    free(name);
                }
                else
                {
                    puts("Incorrect input or memeory Error");
                }
                break;
            }
            case 2:
            {
                pop_back(list);
                break;
            }
            case 3:
            {
                display(list);
                break;
            }
            }
        } while (choice);
        free_ll(list);
    }
}

char *get_str(void)
{
    size_t len;
    char *temp = NULL;
    ssize_t read = getline(&temp, &len, stdin);
    if (read > 0)
    {
        temp[read - 1] = '\0';
    }
    return temp;
}

void clear_stream(void)
{
    int x;
    while ((x = getchar()) != '\n' && x != EOF)
    {
    }
}