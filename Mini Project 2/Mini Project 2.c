#include <stdio.h>
#include <stdlib.h>

int main() {
    char secretWord[] = "youcode", guess, *guessedWord;

    int length = 7, attemptsLeft = 6, lettersFound = 0, i, correct, gotcount = 3;

    guessedWord = malloc(length + 1);

    for (i = 0; i < length; i++) {
        guessedWord[i] = '_';
    }


    gotoxy(1, 1);     printf("+-----------------------------------+-----+");
    gotoxy(1, 2);     printf("|   Welcome to the Guessing Game!   |     |");
    gotoxy(1, 3);     printf("+-----------------------------------+     |");
    gotoxy(1, 4);     printf("|                                   |     |");
    gotoxy(1, 5);     printf("+-----------------------------------+-----+");
    gotoxy(1, 6);     printf("|                                   |");
    gotoxy(1, 7);     printf("+-----------------------------------+");
    gotoxy(1, 8);     printf("|                                   |");
    gotoxy(1, 9);     printf("+-----------------------------------+");

    while (attemptsLeft > 0 && lettersFound < length) {
        gotoxy(3, gotcount + 1);printf("Word : ");
        for (i = 0; i < length; i++) {
            printf("%c ", guessedWord[i]);
        }

        gotoxy(3, gotcount + 3);printf("Enter a letter : ");
        scanf(" %c", &guess);

        correct = 0;
        for (i = 0; i < length; i++) {
            if (secretWord[i] == guess && guessedWord[i] == '_') {
                guessedWord[i] = guess;
                lettersFound++;
                correct = 1;
            }
        }

        if (correct == 1) {
            gotoxy(3, gotcount + 5);printf("Correct!                    ");
        } else {
            attemptsLeft--;
            gotcount+3;
            gotoxy(3, gotcount + 5);printf("Wrong! Attempts left: %d   ", attemptsLeft);

            switch (attemptsLeft) {
                case 5:
                    gotoxy(40, 2); printf("O");
                    break;
                case 4:
                    gotoxy(40, 3); printf("|");
                    break;
                case 3:
                    gotoxy(39, 3); printf("/");
                    break;
                case 2:
                    gotoxy(41, 3); printf("\\");
                    break;
                case 1:
                    gotoxy(39, 4); printf("/");
                    break;
                case 0:
                    gotoxy(41, 4); printf("\\");
                    break;
            }
        }
    }

    if (lettersFound == length) {
        gotoxy(3, gotcount + 5);printf("You won! The word was: %s\n", secretWord);
    } else {
        gotoxy(3, gotcount + 5);printf("Game Over! The word was: %s\n", secretWord);
    }

    free(guessedWord);
    return 0;
}
