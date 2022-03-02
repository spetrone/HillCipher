#include <iostream>
#include <math.h>


using namespace std;

int enc[3][1], dec[3][1], msg[3][1], key[3][3];
char msgStr[3];
char keyStr[9];

//get information from user

//message to be encrypted
void getMessage() {
    cout << "\nPlease enter a 3-letter message to encrypt" << endl;
    cin >> msgStr;

    for (int i = 0; i < 3; i++) {
        msg[i][0] = msgStr[i];
    }
}

//get key 
void getKey() {

    cout << "\nPlease enter a 9-letter key: " << endl;
    cin >> keyStr;
    int l = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            key[i][j] = keyStr[l];
            l++;
        }
    }
}


void encrypt() {
    //matrix-vector multiplication of key times message

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            enc[i][0] += msg[i][0] * key[i][j];
        }
    }
}

int main() {

    getMessage();
    getKey();
    encrypt();

    //print enc
    cout << "\nEncrypted Message: ";
    for (int i = 0; i < 3; i++) {
        cout << enc[i][0];
    }
}