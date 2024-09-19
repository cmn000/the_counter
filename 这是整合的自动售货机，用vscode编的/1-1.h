#include <stdio.h>
#include <stdlib.h>

// 定义商品结构体
typedef struct Goods{
    char goods_type;  // 商品类型，用单个字符表示
    int channel;      // 商品所在的通道
    int price;        // 商品价格
    int quantity;     // 商品数量
} Goods;

Goods machine[5]; // 假设有5个通道

// 放置商品的函数
void place_goods(int channel, char goods_type, int price, int number) {
    if (channel >= 1 && channel <= 5) {
        // 检查该通道是否已经有商品以及商品是否相同
        if (machine[channel - 1].quantity == 0 || goods_type == machine[channel - 1].goods_type) {
            int new_quantity = machine[channel - 1].quantity + number; 
            machine[channel - 1] = (Goods){goods_type, channel, price, new_quantity};
            printf("%d %c：", channel, goods_type);
            for(int i = 0; i < new_quantity; i++) {
                printf("%c", goods_type);
            }
            printf("%d\n", price);
        } else {
            printf("通道 %d 已有其他商品，无法放置新商品。\n", channel);
        }
    } else {
        printf("没有该通道。\n");
    }
}

// 检查输入是否为整数的函数
int check_int() {
    int num;
    if (scanf("%d", &num) != 1) {
        printf("请输入一个整数：\n");
        while (getchar() != '\n'); // 清空缓冲区
        return 0; // 失败
    }
    while (getchar() != '\n'); // 清空缓冲区
    return num; // 成功
}

// 检查输入是否为字符的函数
char check_char() {
    char word;
    if (scanf(" %c", &word) != 1) {
        printf("请输入一个字符：\n");
        while (getchar() != '\n'); // 清空缓冲区
        return 0; // 失败
    }
    return word; // 成功
}

int mai() {
    int channel, price, number;
    char goods_type;

    printf("请按次序输入通道，货物名称，货物价钱，货物数量：\n");
    channel = check_int();
    goods_type = check_char();
    price = check_int();
    number = check_int();

    place_goods(channel, goods_type, price, number);
    return 0;
}