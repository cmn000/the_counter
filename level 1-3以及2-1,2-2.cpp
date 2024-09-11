#include <stdio.h>
#include "1-1.h"
#include "1-2.h"
#define MAX_HISTORY 3

typedef struct {
    char type;
    int channel_sequence;
    int number;
} History;//操作历史 

History history[MAX_HISTORY];
int history_index = -1; // 用于跟踪栈顶位置

// 定义一个找到商品对应货架的函数 
int find_by_type(struct Goods machine[], char type) {
    for (int i = 0; i < 5; i++) {
        if (type == machine[i].goods_type) {
            return i;
        }
    }
    return -1;
}

typedef enum {
    START,
    STORE,
    BUY,
    CONTINUE_STORE,
    OUT_OF_STOCK,
    CONTINUE_BUY,
    BACK,
    END
} State;

void process_buy(struct Goods machine[], int channel_number[], int channel_sequence, int *sum) {
    char type; // 声明 type 变量
    int number;
    printf("enter the number you buy:");
    scanf("%d", &number);
    channel_number[channel_sequence] -= number;
    *sum = number * machine[channel_sequence].price;
    *sum = charge_coin(*sum); // 接收 charge_coin 函数返回的找零金额 
    printf("最终找零: %d元\n", *sum); // 打印最终找零金额 
    // 记录操作历史
    if (history_index < MAX_HISTORY - 1) {
        history[++history_index] = (History){type, channel_sequence, number}; 
    }
}

int main() {
    State state = START;
    int number, sum, channel_sequence;
    char type, buy_or_store;
    struct Goods machine[5];  
    int channel_number[5] = {0, 0, 0, 0, 0};  // 初始化都是0

    while (state != END) {
        switch (state) {
            case START:
                printf("enter buy, store, or back(b/s/back):");
                scanf(" %c", &buy_or_store);
                if (buy_or_store == 'b') {
                    state = BUY;
                } else if (buy_or_store == 's') {
                    state = STORE;
                } else if (buy_or_store == 'k') {
                    state = BACK;
                } else {
                    state = END;
                }
                break;
            case BACK:
                if (history_index >= 0) {
                    // 撤销操作
                    History h = history[history_index--];
                    type = h.type; 
                    channel_sequence = h.channel_sequence;
                    number = h.number;
                    channel_number[channel_sequence] += number; // 撤销购买
                    printf("操作已撤销\n");
                    if (history_index == -1) {
                        printf("无法进一步回退\n");
                    }
                } else {
                    printf("没有可回退的操作\n");
                }
                state = START; // 返回初始状态
                break;
            case STORE:
                mai(); // 调用 mai 函数，在1-1中 
            case CONTINUE_STORE:
                printf("是否继续存入？(y/n): ");
                char store_or_not;
                scanf(" %c", &store_or_not);
                if (store_or_not == 'y') {
                    state = STORE;
                } else {
                    state = END;
                }
                break;
            case BUY:
                printf("enter the type:");
                scanf(" %c", &type);
                channel_sequence = find_by_type(machine, type);
                if (channel_sequence == -1) {
                    printf("无该商品\n");
                    state = END;
                } else {
                    process_buy(machine, channel_number, channel_sequence, &sum); 
                    if (channel_number[channel_sequence] > 0) {
                        state = CONTINUE_BUY;
                    } else {
                        state = OUT_OF_STOCK;
                    }
                }
                break;
            case OUT_OF_STOCK:
                printf("该商品已售罄，是否继续购买其他商品？(y/n): ");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y') {
                    state = START;
                } else {
                    state = END;
                }
                break;
            case CONTINUE_BUY:
                printf("是否继续购买？(y/n): ");
                char buy_or_not;
                scanf(" %c", &buy_or_not);
                if (buy_or_not == 'y') {
                    state = BUY;
                } else {
                    state = END;
                }
                break;
            case END:
                printf("交易结束。\n");
                break;
        }
        
    }

    return 0;
}
