#include <stdio.h>
#include <stdlib.h>

int main() {
    int Math, Fr, Eng, Ar, Ph;
    int TN, MG;
    int max, min;

    printf("==============================================\n");
    printf("=       Give Me The Notes Of Each One.       =\n");
    printf("==============================================\n");
    printf("| Note 1 | Note 2 | Note 3 | Note 4 | Note 5 |\n");
    printf("==============================================\n");
    printf("|        |        |        |        |        |");

    gotoxy(5,6);scanf("%d", &Math);
    gotoxy(14,6);scanf("%d", &Fr);
    gotoxy(23,6);scanf("%d", &Eng);
    gotoxy(32,6);scanf("%d", &Ar);
    gotoxy(41,6);scanf("%d", &Ph);

    TN = Math + Fr + Eng + Ar + Ph;
    MG = TN / 5;

    max = min = Math;
    if (Fr > max) max = Fr;
    if (Eng > max) max = Eng;
    if (Ar > max) max = Ar;
    if (Ph > max) max = Ph;

    if (Fr < min) min = Fr;
    if (Eng < min) min = Eng;
    if (Ar < min) min = Ar;
    if (Ph < min) min = Ph;

    printf("==============================================\n");
    printf("|               Final Report                 |\n");
    printf("==============================================\n");
    printf("| Total:          %-27d|\n", TN);
    printf("| Average:        %-27d|\n", MG);
    printf("| Highest Note:   %-27d|\n", max);
    printf("| Lowest Note:    %-27d|\n", min);

    printf("| Mention:        ");
    if (MG >= 90) {
        printf("A : Excellent              |\n");
    } else if (MG >= 80) {
        printf("B : Very good              |\n");
    } else if (MG >= 70) {
        printf("C : Good                   |\n");
    } else if (MG >= 50) {
        printf("D : Fine                   |\n");
    } else {
        printf("F : Failed                 |\n");
    }

    printf("| Result:         ");
    if (MG >= 50) {
        printf("Passed                     |\n");
    } else {
        printf("Failed                     |\n");
    }

    printf("==============================================\n");

    return 0;
}
