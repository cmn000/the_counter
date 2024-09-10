#include <stdio.h>

int main() {
    FILE *fp;
    int totalcost, sum = 0, coin, change;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("无此文件。\n");
        return 1;
    }

    fscanf(fp, "%d %d", &totalcost, &coin);
    sum+= coin;

    while (sum < totalcost) {
        fscanf(fp, "%d %d", &coin, &coin);
        sum += coin;
    }

    change = sum- totalcost;
    printf("找零金额: %d 元\n", change);
    fclose(fp);
    return 0;
}
