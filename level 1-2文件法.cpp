#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    FILE *fp;
    int totalcost, sum = 0, coin, change;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("无该商品\n");
        return 1;
    }

    fscanf(fp, "%d %d", &totalcost, &coin);
    sum+= coin;

    while (sum < totalcost) {
        fscanf(fp, "%d %d", &coin, &coin);
        sum += coin;
    }

    change = sum- totalcost;
    printf("找零%d\n", change);
    fclose(fp);
    return 0;
}
