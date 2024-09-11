#include <stdio.h>

int charge_coin(int totalcost) {
    int sum = 0, coin, change;

    while (sum < totalcost) {
        printf("请输入投币金额（1, 2, 5元）: ");
        scanf("%d", &coin);
        if (coin != 1 && coin != 2 && coin != 5) {
            printf("无效投币金额。\n");
            continue;
        }
        sum += coin;
    }

    change = sum - totalcost;
    printf("找零: %d元\n", change);
    return change; // 返回找零金额
}; 

int ma () {
    int total, remain;

    printf("请输入总金额: ");
    scanf(" %d", &total); // 
    remain = charge_coin(total); // 接收 charge_coin 函数返回的找零金额

    printf("最终找零: %d元\n", remain); // 打印最终找零金额

    return 0;
}
