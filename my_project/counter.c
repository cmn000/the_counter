#include <stdio.h>
#include "1-1.h"
#include "1-2.h"
#include <windows.h>
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
    printf("finnel change: %dyuan\n", *sum); // 打印最终找零金额 
    // 记录操作历史
    if (history_index < MAX_HISTORY - 1) {
        history[++history_index] = (History){type, channel_sequence, number};
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    State state = START;
    int number, sum, channel_sequence;
    char type, buy_or_store;
    struct Goods machine[5];  // 假设这里已经初始化了商品信息
    int channel_number[5] = {0, 0, 0, 0, 0};  // 初始化都是0

    while (state != END) {
        switch (state) {
            case START:
                printf("enter buy, store, or back(b/s/k):");
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
                    printf("execution has been canceled\n");
                    if (history_index == -1) {
                        printf("unable to return\n");
                    }
                } else {
                    printf("do not have an execution to return\n");
                }
                state = START; // 返回初始状态
                break;
            case STORE:
                mai(); // 调用 mai 函数，在1-1中 
            case CONTINUE_STORE:
                printf("store or not？(y/n): ");
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
                    printf("no such commodity\n");
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
                printf("the commodity is out of stock,countinue buy or not？(y/n): ");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y') {
                    state = BUY;
                } else {
                    state = END;
                }
                break;
            case CONTINUE_BUY:
                printf("countinue by or not？(y/n): ");
                char buy_or_not;
                scanf(" %c", &buy_or_not);
                if (buy_or_not == 'y') {
                    state = BUY;
                } else {
                    state = END;
                }
                break;
            case END:
                printf("transaction is completed。\n");
                break;
        }
        
    }

    return 0;
}
