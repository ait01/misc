/* Draw horizontal and vertical bar charts of non-blank character
 * frequencies and word length frequencies in the input.
 * ASCII only. The input need not end with a newline.
 */
#include <iostream>
#define MAXC 128 /* Maximum number of different characters. */
#define MAXW 100 /* Maximum word length. */
#define MAXH 50 /* Horizontal bar chart maximum value. */
#define MAXV 100 /* Vertical bar chart maximum value. */
#define STEPV 4 /* Vertical bar chart step. */

int main()
{
    int i, j = 0;
    int most = 0; /* Highest character or word length frequency. */
    int c[MAXC] = {0}; /* Character frequencies array. */
    int w[MAXW+1] = {0}; /* Word length frequencies array. */

    do {
        if ((i = std::getchar()) == ' ' || i == '\t' || i == '\n' || i == EOF) ++w[j], j = 0;
        else if (i < MAXC) ++c[i], ++j;
        else { std::puts("Not ASCII."); return 1; }
    } while (i != EOF);
    /* Find the highest frequency of a character. */
    for (i = 0; i < MAXC; ++i) if (c[i] > most) most = c[i];
    std::puts("\nCharacter Statistics:");
    /* Draw the horizontal bar chart. */
    std::puts("\nHorizontal Bar Chart:");
    for (i = 0; i < MAXC; ++i) {
        if (c[i]) std::printf("\n%3i %c ", i, i);
        if (c[i] && c[i]*MAXH/most < 1) std::putchar('-');
        else for (j = 1; j <= c[i]*MAXH/most; ++j) std::putchar('=');
    }
    /* Draw the vertical bar chart with the capital and small letters separately. */
    std::puts("\n\nVertical Bar Chart (Capital and Small Letters Separately):");
    for (i = MAXV; i > 0; i -= STEPV) {
        std::printf("\n%3i ", i);
        for (j = 0; j < MAXC; ++j) {
            if (c[j]*MAXV/most >= i) std::putchar(':');
            else if (c[j] > 0 && i == STEPV) std::putchar('.');
            else if (c[j]) std::putchar(' ');
        }
    }
    std::printf("\n\n    ");
    for (i = 0; i < MAXC; ++i) if (c[i]) std::printf("%c", i);
    /* Add the frequencies of each capital letter and its small letter counterpart
       and set the small letter frequency to zero. */
    for (i = 0; i < MAXC; ++i) if (i >= 'A' && i <= 'Z') c[i] = c[i] + c[i+'a'-'A'], c[i+'a'-'A'] = 0;
    /* Find the highest frequency of a character again. */
    for (i = 0; i < MAXC; ++i) if (c[i] > most) most = c[i];
    /* Draw the vertical bar chart with the capital and small letters together. */
    std::puts("\n\nVertical Bar Chart (Capital and Small Letters Together):");
    for (i = MAXV; i > 0; i -= STEPV) {
        std::printf("\n%3i ", i);
        for (j = 0; j < MAXC; ++j) {
            if (c[j]*MAXV/most >= i) std::putchar('|');
            else if (c[j] > 0 && i == STEPV) std::putchar(':');
            else if (c[j]) std::putchar(' ');
        }
    }
    std::printf("\n\n    ");
    for (i = 0; i < MAXC; ++i) if (c[i]) std::printf("%c", i);
    /* Find the highest frequency of a word length. */
    most = 0;
    for (i = 1; i <= MAXW; ++i) if (w[i] > most) most = w[i];
    /* Print the word length statistics. */
    std::puts("\n\nWord Length Statistics:\n");
    for (i = 1; i <= MAXW; ++i) if (w[i]) std::printf("%3i word%s of length %i\n", w[i], w[i] == 1 ? " " : "s", i);
    std::printf("\nMost words of a given length: %i.\n", most);
    /* Draw the horizontal bar chart of the word lengths. */
    std::puts("\nHorizontal Bar Chart:");
    for (i = 1; i <= MAXW; ++i) {
        if (w[i]) std::printf("\n%3i ", i);
        if (w[i] && w[i]*MAXH/most < 1) std::putchar('-');
        else for (j = 1; j <= w[i]*MAXH/most; ++j) std::putchar('=');
    }
    /* Draw the vertictal bar chart of the word lengths. */
    std::puts("\n\nVertical Bar Chart:");
    for (i = MAXV; i > 0; i -= STEPV) {
        std::printf("\n%3i ", i);
        for (j = 1; j <= MAXW; ++j) {
            if (w[j]*MAXV/most >= i) std::printf("  =");
            else if (w[j] > 0 && i == STEPV) std::printf("  -");
            else if (w[j]) std::printf("   ");
        }
    }
    std::printf("\n\n    ");
    for (i = 1; i <= MAXW; ++i) if (w[i]) std::printf("%3i", i);
    std::puts("\n\nEnd of Statistics.\n");
    return 0;
}
