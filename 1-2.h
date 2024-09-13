
#include <stdio.h>

int charge_coin(int totalcost) {
    int sum = 0, coin, change;

    while (sum < totalcost) {
        printf("enter the change number（1, 2, 5yuan）: ");
        scanf("%d", &coin);
        if (coin != 1 && coin != 2 && coin != 5) {
            printf("do not have such change。\n");
            continue;
        }
        sum += coin;
    }

    change = sum - totalcost;
    printf("return change: %dyuan\n", change);
    return change; // 返回找零金额
}; 

int ma () {
    int total, remain;

    printf("enter the sum cost: ");
    scanf(" %d", &total); // 
    remain = charge_coin(total); // 接收 charge_coin 函数返回的找零金额

    printf("finnel change: %dyuan\n", remain); // 打印最终找零金额

    return 0;
}
