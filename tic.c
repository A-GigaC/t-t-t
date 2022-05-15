#include <stdio.h>

char *field[3][3]= {
        {"\t1\t", //1
        "\t2\t", //2
        "\t3\t",}, //3
        {"\t4\t", //4
        "\t5\t", //5
        "\t6\t",}, //6
        {"\t7\t",
        "\t8\t",
        "\t9\t",},//9
};
char *x = "\\ /\n x \n/ \\\n";
char *o = "000\n0 0\n000\n";


//int wincon(int pl);

int main() {
    int c, counter = 0, line, column;
    // first drawing
    for (line=0; line < 3; line++) {
        printf("\n");
        for (column=0; column < 3; column++) {
            printf("%s", field[line][column]);   //field printing
        }
    }
    // game starts here
    while ((c = getchar()) != 'q' && counter <= 9) {
        if (c >= '1' && c <= '9') {// standart steps logic
            line = c / 3;
            column = c % 3;
            if (field[line][column] == c) {
                if (++counter % 2 != 0) {
                    field[line][column] = *x;
                } else {
                    field[line][column] = *o;
                }
                printf("----step %d----\n", counter);
                for (line=0; line < 3; line++) {
                    printf("\n");
                    for (column=0; column < 3; column++) {
                        printf("%s", field[line][column]);   //field printing
                    }
                }
//                if (wincon(1)) {                                            /*  WIN CONDITION */
//                    printf("player 1 has won\n");
//                    return 0;
//                } else if (wincon(2)) {                                         /*  WIN CONDITION */
//                    printf("player 2 has won\n");
//                    return 0;
//                }
            } else {
                printf("This field has a value yet\n");
            }
        } else {
            printf("incorrect field number\n");
        }
        }
    return 0;
}


//int wincon(int pl)
//{
//    int line, column, eq, win=0;
//    int target = 0;
//
//    if (pl == 1) {
//        target = *x;
//    } else {
//        target = *o;
//    }
//    // horizontal
//    for (line=0; line<3; line++) {
//        eq = 0;
//        for (column=0; column<3; column++) {
//            if (*field[line][column]==*target) {
//                ++eq;
//            }
//        }
//        if (eq == 3) {
//            win = 1;
//        }
//    }
//    // vertical
//    for (column=0; column<3; column++) {
//        eq = 0;
//        for (line=0; line<3; line++) {
//            if (*field[line][column]==*target) {
//                ++eq;
//            }
//        }
//        if (eq == 3) {
//            win = 1;
//        }
//    }
//    // diagonal R
//    for (line=0, column=0; column<3 && line<3; column++, line++) {
//        eq=0;
//        if (*field[line][column]==*target) {
//            ++eq;
//        }
//        if (eq == 3) {
//            win = 1;
//        }
//    }
//    // diagonal L
//    for (line=2, column=2; column>=0 && line>=0; column--, line--) {
//        eq=0;
//        if (*field[line][column]==*target) {
//            ++eq;
//        }
//        if (eq == 3) {
//            win = 1;
//        }
//    }
//    return win;
//}

