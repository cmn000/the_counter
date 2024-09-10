#include <stdio.h>
#include <stdlib.h>

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
        printf("%d %c��", channel, goods_type);
        for (int i = 0; i < quantity; i++) {
            printf("%c", goods_type);
        }
        printf(" %d\n", price);
    } else {
        printf("û�и�ͨ����\n");
    }
}

int check_int() {
    int num;
    if (scanf("%d", &num) != 1) {
        printf("������һ��������\n");
        while (getchar() != '\n'); // ��ջ�����
        return 0; // ʧ��
    }
    while (getchar() != '\n'); // ��ջ�����
    return num; // �ɹ�
}

int check_char() {
    char word;
    if (scanf(" %c", &word) != 1) {
        printf("������һ���ַ���\n");
        while (getchar() != '\n'); // ��ջ�����
        return 0; // ʧ��
    }
    return word; // �ɹ�
}

int main() {
    int channel, price, quantity;
    char goods_type;

    printf("�밴��������ͨ�����������ƣ������Ǯ������������\n");
    channel = check_int();
    goods_type = check_char();
    price = check_int();
    quantity = check_int();

    place_goods(channel, goods_type, price, quantity);
    return 0;
}


