#include <stdio.h>
#include <windows.h>

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
    printf("return change: %d元\n", change);
    return change; // 返回找零金额
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int total, remain;

    printf("enter the sum money :");
    scanf(" %d", &total); // 使用 & 来获取用户输入的地址
    remain = charge_coin(total); // 接收 charge_coin 函数返回的找零金额

    printf("final change: %d元\n", remain); // 打印最终找零金额

    return 0;
}

