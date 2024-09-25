#include <stdio.h>
#include <string.h>

// 定义商品结构体
typedef struct Goods{
    char goods_type;  // 商品类型，用单个字符表示
    int channel;      // 商品所在的通道
    int price;        // 商品价格
    int quantity;     // 商品数量
} Goods;

//通过种类来找到机器的序号
int find_by_type(struct Goods machine[], char type) {
    for (int i = 0; i < 5; i++) {
        if (type == machine[i].goods_type) {
            return i;
        }
    }
    return -1;
}

Goods machine[5]; // 设置一个数组，里面包含五个通道的商品结构体

// 放置商品的函数
void place_goods(int channel, char goods_type, int price, int number) {
    if (channel >= 1 && channel <= 5) {
        // 检查该通道是否已经有商品以及商品是否相同
        if (machine[channel - 1].quantity == 0 || goods_type == machine[channel - 1].goods_type) {
            int new_quantity = machine[channel - 1].quantity + number; //新的数量
            //检查是否超过最大容量
            if(new_quantity<=50){
            machine[channel - 1] = (Goods){goods_type, channel, price, new_quantity};
            printf("%d %c：", channel, goods_type);
            for(int i = 0; i < new_quantity; i++) {
                printf("%c", goods_type);//打印goods_type个的商品名称
            }
            printf("  %d\n", price);
            }
            else{
            printf("the quantity is out of max");
            machine[channel-1].quantity=new_quantity-number;
            }
        } else {
            printf("通道 %d 已有其他商品，无法放置新商品。\n", channel);
        }
    } else {
        printf("没有该通道。\n");
    }
}

// 检查输入是否为整数而不是小数的函数
int check_int(float num) {//先转化为浮点数，之后再看是否相等
    do {scanf("%f",&num);
    if((int)num!=num){
        printf("please enter an integer");
    }
    }
    while((int)num!=num);
    
    
    return (int)num; // 成功
}

// 检查输入是否为单个字符的函数
char check_char() {
    char word[100];
    do {scanf(" %s", &word); 
    if(strlen(word)!=1){    
        printf("请输入一个字符：\n");
    }
    }
    while(strlen(word)!=1);
    return word[0]; // 成功
}

int mai() {
    int channel, price, number;
    char goods_type;

    printf("请按次序输入通道，货物名称，货物价钱，货物数量：\n");
    //检查输入是否正常
    channel = check_int(channel);
    goods_type = check_char();
    price = check_int(price);
    number = check_int(number);
    //判断是否两次东西一样但价钱不一样
    if(find_by_type(machine,goods_type)==-1||price==machine[find_by_type(machine,goods_type)].price){

    place_goods(channel, goods_type, price, number);}
    else{
        printf("两次价钱不一样");
    }
    return 0;
}