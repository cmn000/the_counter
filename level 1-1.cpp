#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Goods {
    char goods_type;
    int channel;
    int price;
    int quantity;
};

int channel_number[5] = {0, 0, 0, 0, 0};
struct Goods machine[5];

void place_goods(int channel, char goods_type, int price, int quantity) {
    if (channel >= 1 && channel <= 5) {
        channel_number[channel - 1] += quantity;
        machine[channel - 1] = (struct Goods){goods_type, channel, price, quantity};
        printf("%d %c：", channel, goods_type);
        for (int i = 0; i < quantity; i++) {
            printf("%c", goods_type);
        }
        printf(" %d\n", price);
    } else {
        printf("no such channel。\n");
    }
}

int check_int() {
    int num;
    if (scanf("%d", &num) != 1) {
        printf("enter an int：\n");
        while (getchar() != '\n'); // 清空缓冲区
        return 0; // 失败
    }
    while (getchar() != '\n'); // 清空缓冲区
    return num; // 成功
}

int check_char() {
    char word;
    if (scanf(" %c", &word) != 1) {
        printf("enter the name：\n");
        while (getchar() != '\n'); // 清空缓冲区
        return 0; // 失败
    }
    return word; // 成功
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8)
    int channel, price, quantity;
    char goods_type;

    printf("enter the channel,commodity name,price and number in turn：\n");
    channel = check_int();
    goods_type = check_char();
    price = check_int();
    quantity = check_int();

    place_goods(channel, goods_type, price, quantity);
    return 0;
}


