#include <stdio.h>

#define CROSS 1
#define ZERO -1
#define NONE 0

char *x = "\\ / X / \\";
char *o = "0000 0000";

int field[3][3] = {
        {NONE, NONE, NONE},
        {NONE, NONE, NONE},
        {NONE, NONE, NONE}
};

char *matrix[3][3] = {
        {"    1    ", //1
                "    2    ", //2
                "    3    ",}, //3
        {"    4    ", //4
                "    5    ", //5
                "    6    ",}, //6
        {"    7    ",
                "    8    ",
                "    9    ",},//9
};

void draw();

int wincon(int pl);


int main() {
    int c, line, column, status = 0, win;
    printf("----- step %d ----\n", status);
    draw();
    while (status < 9 && (c = getchar()) != 'q') {
        if (c >= '1' && c <= '9') {
            int nc = c - '1';
            line = nc / 3;
            column = nc % 3;
            if (field[line][column] == 0) {
                field[line][column] = status % 2 != 0 ? ZERO : CROSS;
                printf("\e[1;1H\e[2J");
                printf("----- step %d ----\n", status + 1);
                draw();
                status++;
            } else {
                printf("incorrect input\n");
                continue;
            }
            if ((win = wincon(1)) != 0) {
                printf("\n1st player wins\n");
                status = 101;
            } else if ((win = wincon(2)) != 0) {
                printf("\n\t\t2nd player wins\n");
                status = 110;
            }
        }
    }
    if (status != 101 && status != 110) {
        printf("\n\tDraw\n");
    }
    return 0;
}


void draw() {
    // matrix updating
    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            if (field[line][column] == CROSS) {
                matrix[line][column] = x;
            } else if (field[line][column] == ZERO) {
                matrix[line][column] = o;
            }
        }
    }
    // matrix elements printing
    for (int line = 0; line < 3; line++) {
        for (int level = 0; level < 3; level++) {
            for (int column = 0; column < 3; column++) {
                printf(" ");
                for (int symb = level*3; symb < level*3 + 3; symb++) {
                    printf("%c", *(matrix[line][column] + symb));
                }
                if (column != 2) {
                    printf(" |");
                }
            }
            printf("\n");
        }
        if (line != 2) {
            printf("-----------------\n");
        }
    }
}


int wincon(int pl) {
    int target, line, column, eq, win = 0;

    target = pl == 1 ? CROSS : ZERO;

    // horizontal
    for (line = 0; line < 3; line++) {
        eq = 0;
        for (column = 0; column < 3; column++) {
            if (field[line][column] == target) {
                ++eq;
            }
        }
        if (eq == 3) {
            win = 1;
        }
    }
    // vertical
    for (column = 0; column < 3; column++) {
        eq = 0;
        for (line = 0; line < 3; line++) {
            if (field[line][column] == target) {
                ++eq;
            }
        }
        if (eq == 3) {
            win = 1;
        }
    }
    // diagonal R
    eq = 0;
    for (line = 0, column = 0; column < 3 && line < 3; column++, line++) {
        if (field[line][column] == target) {
            ++eq;
        }
        if (eq == 3) {
            win = 1;
        }
    }
    // diagonal L
    eq = 0;
    for (line = 0, column = 2; column >= 0 && line < 3; column--, line++) {
        if (field[line][column] == target) {
            ++eq;
        }
        if (eq == 3) {
            win = 1;
        }
    }
    return win;
}
