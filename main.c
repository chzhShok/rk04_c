#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "list.h"

int main(void)
{
    node_t *head = NULL;

    int line_count = 0;
    FILE *f = fopen("in.txt", "r");
    if (!f)
        return IO_ERROR;

    char *line = NULL;
    size_t linecap = 0;
    while (getline(&line, &linecap, f) > 0)
    {
        line[strcspn(line, "\n")] = '\0';
        if (push_back(&head, line))
            return PUSH_ERROR;
        line_count++;
    }
    free(line);
    fclose(f);

    for (int i = 0; i < line_count; i++)
    {
        char *data = pop_front(&head);

        if (strchr(data, ' '))
        {
            char *sep = " ";
            char *word = NULL;
            word = strtok(data, sep);
            while (word)
            {
                if (push_back(&head, word))
                    return PUSH_ERROR;
                word = strtok(NULL, sep);
            }
        }
        else
        {
            for (char *p = data; *p != '\0'; p++)
            {
                char *word = malloc(2 * sizeof(char));

                word[0] = *p;
                word[1] = '\0';

                if (push_back(&head, word))
                {
                    free(word);
                    return PUSH_ERROR;
                }

                free(word);
            }
        }
    }


    f = fopen("out.txt", "w");
    if (!f)
        return IO_ERROR;
    print_list(head, f);
    fclose(f);

    free_list(&head);
    return OK;
}
