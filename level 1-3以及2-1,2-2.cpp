#include <stdio.h>
#include "1-1.h"
#include "1-2.h"
#define MAX_HISTORY 3

typedef struct {
    char type;
    int channel_sequence;
    int number;
} History;//������ʷ 

History history[MAX_HISTORY];
int history_index = -1; // ���ڸ���ջ��λ��

// ����һ���ҵ���Ʒ��Ӧ���ܵĺ��� 
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
    char type; // ���� type ����
    int number;
    printf("enter the number you buy:");
    scanf("%d", &number);
    channel_number[channel_sequence] -= number;
    *sum = number * machine[channel_sequence].price;
    *sum = charge_coin(*sum); // ���� charge_coin �������ص������� 
    printf("��������: %dԪ\n", *sum); // ��ӡ���������� 
    // ��¼������ʷ
    if (history_index < MAX_HISTORY - 1) {
        history[++history_index] = (History){type, channel_sequence, number}; // �˴�����
    }
}

int main() {
    State state = START;
    int number, sum, channel_sequence;
    char type, buy_or_store;
    struct Goods machine[5];  // ���������Ѿ���ʼ������Ʒ��Ϣ
    int channel_number[5] = {0, 0, 0, 0, 0};  // ��ʼ������0

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
                    // ��������
                    History h = history[history_index--];
                    type = h.type; 
                    channel_sequence = h.channel_sequence;
                    number = h.number;
                    channel_number[channel_sequence] += number; // ��������
                    printf("�����ѳ���\n");
                    if (history_index == -1) {
                        printf("�޷���һ������\n");
                    }
                } else {
                    printf("û�пɻ��˵Ĳ���\n");
                }
                state = START; // ���س�ʼ״̬
                break;
            case STORE:
                mai(); // ���� mai ��������1-1�� 
            case CONTINUE_STORE:
                printf("�Ƿ�������룿(y/n): ");
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
                    printf("�޸���Ʒ\n");
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
                printf("����Ʒ���������Ƿ��������������Ʒ��(y/n): ");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y') {
                    state = START;
                } else {
                    state = END;
                }
                break;
            case CONTINUE_BUY:
                printf("�Ƿ��������(y/n): ");
                char buy_or_not;
                scanf(" %c", &buy_or_not);
                if (buy_or_not == 'y') {
                    state = BUY;
                } else {
                    state = END;
                }
                break;
            case END:
                printf("���׽�����\n");
                break;
        }
        
    }

    return 0;
}
