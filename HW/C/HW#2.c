#include <stdio.h>

int main() {
    int year;
    float weight;

    // 提示用户输入汽车的年份和重量
    printf("Enter the model year of the automobile: ");
    scanf("%d", &year);
    printf("Enter the weight of the automobile (in pounds): ");
    scanf("%f", &weight);

    // 根据年份和重量确定重量类别和注册费用
    if (year <= 1970) {
        if (weight < 2700) {
            printf("Weight Class: 1\nRegistration Fee: $16.50\n");
        } else if (weight >= 2700 && weight <= 3800) {
            printf("Weight Class: 2\nRegistration Fee: $25.50\n");
        } else {
            printf("Weight Class: 3\nRegistration Fee: $46.50\n");
        }
    } else if (year >= 1971 && year <= 1979) {
        if (weight < 2700) {
            printf("Weight Class: 4\nRegistration Fee: $27.00\n");
        } else if (weight >= 2700 && weight <= 3800) {
            printf("Weight Class: 5\nRegistration Fee: $30.50\n");
        } else {
            printf("Weight Class: 6\nRegistration Fee: $52.50\n");
        }
    } else { // year >= 1980
        if (weight < 3500) {
            printf("Weight Class: 7\nRegistration Fee: $35.50\n");
        } else {
            printf("Weight Class: 8\nRegistration Fee: $65.50\n");
        }
    }

    return 0;
}