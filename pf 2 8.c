#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, last_digit;
    while (number > 0) {
        last_digit = number % 10;
        number = number / 10;
        decimal += last_digit * base;
        base = base * 2;
    }
    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        int last_digit = number % 2;
        number = number / 2;
        binary += last_digit * base;
        base = base * 10;
    }
    return binary;
}

void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0;
    while (number != 0) {
        int temp = number % 16;
        if (temp < 10) {
            hex[i] = temp + '0';
        } else {
            hex[i] = temp - 10 + 'A';
        }
        number /= 16;
        i++;
    }
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    int base = 1;
    int len = strlen(hexNumber);
    
    for (int i = len - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += (hexNumber[i] - '0') * base;
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            decimal += (hexNumber[i] - 'A' + 10) * base;
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        base *= 16;
    }
    printf("Decimal: %d\n", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexNumber[]) {
    int decimal = 0;
    int base = 1;
    int len = strlen(hexNumber);
    
    for (int i = len - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += (hexNumber[i] - '0') * base;
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            decimal += (hexNumber[i] - 'A' + 10) * base;
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        base *= 16;
    }

    printf("Binary: %d\n", DecimalToBinary(decimal));
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            break;
        }

        switch (choice) {
            case 1: {
                int binary;
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                printf("Decimal: %d\n", BinaryToDecimal(binary));
                break;
            }
            case 2: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Binary: %d\n", DecimalToBinary(decimal));
                break;
            }
            case 3: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                DecimalToHexadecimal(decimal);
                break;
            }
            case 4: {
                char hexNumber[20];
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;
            }
            case 5: {
                int binary;
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                BinaryToHexadecimal(binary);
                break;
            }
            case 6: {
                char hexNumber[20];
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}