#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Windowsの場合は#include <windows.h>を使う

// スロットマシンの記号
char *symbols[] = {"🍎", "🍌", "🍒", "🍇", "🍉", "🍍", "🍓"};

// ランダムに記号を選ぶ関数
char* getRandomSymbol() {
    int index = rand() % 7; // 0から6までのランダムな整数を生成
    return symbols[index];
}

// スロットの結果を表示する関数
void displaySlot(char* slot[3]) {
    printf("+-----+-----+-----+\n");
    printf("| %s | %s | %s |\n", slot[0], slot[1], slot[2]);
    printf("+-----+-----+-----+\n");
}

int main() {
    // 乱数の種を現在の時間で初期化
    srand(time(NULL));

    // スロットマシンの結果を格納する配列
    char* slot[3];

    // スロットマシンの演出
    for (int i = 0; i < 10; i++) { // 10回リールを回す演出
        for (int j = 0; j < 3; j++) {
            slot[j] = getRandomSymbol();
        }
        displaySlot(slot);
        usleep(100000); // 0.1秒待機 (Windowsの場合は Sleep(100) を使用)
        printf("\033[2J\033[H"); // 画面クリア (Windowsの場合は system("cls") を使用)
    }

    // 最終結果を表示
    printf("最終結果:\n");
    displaySlot(slot);

    return 0;
}
