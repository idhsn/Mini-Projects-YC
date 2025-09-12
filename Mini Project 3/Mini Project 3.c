#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trig.h"

#define MAX_HISTORY 7
#define MAX_LINE 256

int st_cmp(char *s1, char *s2);
int str_len(char *str);
char *str_copy(char *src, char *dest);
int ft_strstr(char *str, char *to_find);

void draw_box();

int st_cmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

int str_len(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *str_copy(char *src, char *dest)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int ft_strstr(char *str, char *to_find)
{
    int i = 0;
    int j;
    while (str[i])
    {
        j = 0;
        while (str[i + j] && str[i + j] == to_find[j])
        {
            if (to_find[j + 1] == '\0')
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

void draw_box()
{
    int i;
    for (i = 2; i <= 89; i++)
    {
        gotoxy(i, 1);   printf("%c", 205);  // top
        gotoxy(i, 3);   printf("%c", 205);  // middle top
        gotoxy(i, 18);  printf("%c", 205);  // middle bottom
        gotoxy(i, 20);  printf("%c", 205);  // bottom
    }

    for (i = 2; i <= 20; i++)
    {
        gotoxy(1, i);   printf("%c", 186);   // left
        gotoxy(90, i);  printf("%c", 186);   // right
    }

    gotoxy(1, 1);    printf("%c", 201);     // top left
    gotoxy(90, 1);   printf("%c", 187);     // top right
    gotoxy(1, 3);    printf("%c", 204);     // middle top left
    gotoxy(90, 3);   printf("%c", 185);     // middle top right
    gotoxy(1, 18);   printf("%c", 204);     // middle bottom left
    gotoxy(90, 18);  printf("%c", 185);     // middle bottom right
    gotoxy(1, 20);   printf("%c", 200);     // bottom left
    gotoxy(90, 20);  printf("%c", 188);     // bottom right

    for (i = 2; i <= 89; i++)
    {
        gotoxy(i, 2); printf("%c", 219);   // bold line
    }

    gotoxy(34, 2);  printf(" CHAT BOT GRIII3AAA ");
}

int main()
{
    int i, shifting = 4, linecount = 0, f, matched, random_index;
    char Name[25], question[256], stock_ex[256], reply[256];
    char *ex = "exit";
    char *trig[20] = {"sad", "sympathy", "angry", "frustration", "happy", "joy", "confused", "uncertainty", "fear", "anxiety", "gratitude", "appreciation", "curiosity", "interest", "love", "affection", "humor", "playfulness", "hi","hello"};

    char human_history[MAX_HISTORY][MAX_LINE];
    char bot_history[MAX_HISTORY][MAX_LINE];
    int human_count = 0, bot_count = 0;

    srand(time(NULL));

    printf("Type in your name : ");
    scanf("%24s", Name);
    getchar();

Draw:

    system("cls");
    draw_box();

    while (1)
    {
        gotoxy(88, 19);  printf("%c", 175);
        gotoxy(4, 19); printf("Ask a question :                                                                   ");
        gotoxy(21, 19);
        fgets(question, sizeof(question), stdin);
c bz-*
        question[strcspn(question, "\n")] = '\0';


        str_copy(question, stock_ex);

        if (st_cmp(stock_ex, ex) == 0)
        {
            gotoxy(4, 19); printf("GOOD BYE                                                                        ");
            break;
        }

        if (st_cmp(stock_ex, "history") == 0)
        {
            system("cls");
            draw_box();
            for (i = 0; i < human_count; i++)
            {
                gotoxy(4, 4 + i * 2); printf("%s : %s", Name, human_history[i]);
                gotoxy(4, 5 + i * 2); printf("Gri3a : %s", bot_history[i]);
            }
            gotoxy(4, 19); printf("Press Enter to continue...");
            getchar();
            system("cls");
            shifting = 4;
            linecount = 0;
            goto Draw;
        }

        gotoxy(4, shifting);
        printf("%s : %s\n", Name, stock_ex);
        shifting++;
        linecount++;

        if (human_count < MAX_HISTORY)
        {
            str_copy(stock_ex, human_history[human_count]);
            human_count++;
        }

        f = 0;
        matched = 0;
        random_index = rand() % 3;

        while (f < 20)
        {
            if (ft_strstr(stock_ex, trig[f]) == 1)
            {
                sprintf(reply, "%s%s", all_answers[f][random_index], all_questions[f][random_index]);
                gotoxy(4, shifting);
                printf("Gri3a : %s", reply);

                if (bot_count < MAX_HISTORY)
                {
                    str_copy(reply, bot_history[bot_count]);
                    bot_count++;
                }

                shifting++;
                linecount++;
                matched = 1;
                break;
            }
            f++;
        }

        if (!matched)
        {
            sprintf(reply, "I didn't understand, could you please clarify?");
            gotoxy(4, shifting);
            printf("Gri3a : %s", reply);

            if (bot_count < MAX_HISTORY)
            {
                str_copy(reply, bot_history[bot_count]);
                bot_count++;
            }

            shifting++;
            linecount++;
        }

        if (linecount >= 14)
        {
            gotoxy(4, 19);
            printf("Press Enter to clear screen...");
            getchar();
            system("cls");
            linecount = 0;
            shifting = 4;
            goto Draw;
        }
    }

    gotoxy(1, 23);
    return 0;
}
