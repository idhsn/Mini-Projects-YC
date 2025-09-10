#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trig[19] = {
    "sad", "sympathy", "angry", "frustration", "happy", "joy", "confused", "uncertainty",
    "fear", "anxiety", "gratitude", "appreciation", "curiosity", "interest",
    "love", "affection", "humor", "playfulness", "hello"
};

char *answers[19] = {
    "Im really sorry youre feeling this way. Do you want to talk about it?",
    "Its okay to feel sad sometimes. Im here to listen.",
    "It sounds like something really upset you. Want to vent or talk about it?",
    "I understand how frustrating that can be. What happened?",
    "Thats awesome to hear! Whats making you so happy?",
    "I love it when you share good news!",
    "Im here to help! What part is confusing you?",
    "Lets figure this out together.",
    "Its okay to feel anxious sometimes. Do you want to share whats worng?",
    "Lets try some deep breaths together.",
    "Youre very welcome! Im glad I could help.",
    "I appreciate your kind words!",
    "Great question! Heres what I know...",
    "Lets explore that topic together.",
    "Thats very sweet of you!",
    "Im here for you.",
    "Haha, good one!",
    "Want to hear a joke?",
    "hi how can i help you?"
};

#define MAX_HISTORY_LINES 10
#define MAX_LINE_LEN 256

char history[MAX_HISTORY_LINES][MAX_LINE_LEN];
int history_count = 0;

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


// ---------------------- Main
int main()
{
    int i, shifting = 4, linecount = 0, len, f, matched;
    char Name[25], question[256];
    char stock_ex[256];
    char *ex = "exit";

    printf("Type in your name : ");
    scanf("%24s", Name);
    getchar(); // clear buffer

Draw:

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

    gotoxy(34, 2);  printf(" CHAT BOT GRIII3AAA "); // Bot name

    while (1)
    {
        gotoxy(88, 19);  printf("%c", 175); // send symbol
        gotoxy(4, 19); printf("Ask a question :                                                                   ");
        gotoxy(21, 19);
        fgets(question, sizeof(question), stdin);

        len = str_len(question);
        if (len > 0 && question[len - 1] == '\n')
            question[len - 1] = '\0';

        str_copy(question, stock_ex);

        // Exit check
        if (st_cmp(stock_ex, ex) == 0)
        {
            gotoxy(4, 19);printf("GOOD BYE                                                                        ");
            break;
        }

        if (st_cmp(stock_ex, "history") == 0)
        {
            system("cls");
            draw_box();
            for (i = 0; i < history_count; i++)
            {
                gotoxy(4,4 + i);printf("%s\n", history[i]);
            }
            gotoxy(4, 19);printf("Press Enter to continue...");
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

        // Save user message to history
        if (history_count < MAX_HISTORY_LINES)
            snprintf(history[history_count++], MAX_LINE_LEN, "%s : %s", Name, stock_ex);

        f = 0;
        matched = 0;
        while (f < 18)
        {
            if (ft_strstr(stock_ex, trig[f]) == 1)
            {
                gotoxy(4, shifting);
                printf("Bot : %s\n", answers[f]);

                // Save bot answer to history
                if (history_count < MAX_HISTORY_LINES)
                    printf(history[history_count++], MAX_LINE_LEN, "Bot : %s", answers[f]);

                shifting++;
                linecount++;
                matched = 1;
                break;
            }
            f++;
        }

        if (!matched)
        {
            gotoxy(4, shifting);
            printf("Bot : Sorry, I don't understand that feeling.\n");

            // Save default bot answer to history
            if (history_count < MAX_HISTORY_LINES)
                snprintf(history[history_count++], MAX_LINE_LEN, "Bot : Sorry, I don't understand that feeling.");

            shifting++;
            linecount++;
        }

        if (linecount == 14)
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
