#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    FILE *fp;
    int totalcost, sum = 0, coin, change;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("do not have such commodity\n");
        return 1;
    }

    fscanf(fp, "%d %d", &totalcost, &coin);
    sum+= coin;

    while (sum < totalcost) {
        fscanf(fp, "%d %d", &coin, &coin);
        sum += coin;
    }

    change = sum- totalcost;
    printf("return change%d\n", change);
    fclose(fp);
    return 0;
}
