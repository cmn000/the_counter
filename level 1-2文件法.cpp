#include <stdio.h>

int main() {
    FILE *fp;
    int totalcost, sum = 0, coin, change;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("�޴��ļ���\n");
        return 1;
    }

    fscanf(fp, "%d %d", &totalcost, &coin);
    sum+= coin;

    while (sum < totalcost) {
        fscanf(fp, "%d %d", &coin, &coin);
        sum += coin;
    }

    change = sum- totalcost;
    printf("������: %d Ԫ\n", change);
    fclose(fp);
    return 0;
}
