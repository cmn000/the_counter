#include <stdio.h>

int charge_coin(int totalcost) {
    int sum = 0, coin, change;

    while (sum < totalcost) {
        printf("������Ͷ�ҽ�1, 2, 5Ԫ��: ");
        scanf("%d", &coin);
        if (coin != 1 && coin != 2 && coin != 5) {
            printf("��ЧͶ�ҽ�\n");
            continue;
        }
        sum += coin;
    }

    change = sum - totalcost;
    printf("����: %dԪ\n", change);
    return change; // ����������
}

int main() {
    int total, remain;

    printf("�������ܽ��: ");
    scanf(" %d", &total); // ʹ�� & ����ȡ�û�����ĵ�ַ
    remain = charge_coin(total); // ���� charge_coin �������ص�������

    printf("��������: %dԪ\n", remain); // ��ӡ����������

    return 0;
}

