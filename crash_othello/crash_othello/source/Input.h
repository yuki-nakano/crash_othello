#ifndef INPUT_H
#define INPUT_H

//毎フレーム呼び出す
void UpdateKeyStatus();

//押した瞬間
bool IsKeyHeld(int key);

//押している
bool IsKeyPushed(int key);

//離した
bool IsKeyRelesed(int key);

#endif // !INPUT_H
