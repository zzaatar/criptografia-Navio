#include <iostream>
#include <string>
using namespace std;

int main() {
    string encrypted[] = {
        "10010110", "11110111", "01010110", "00000001",
        "00010111", "00100110", "01010111", "00000001",
        "00010111", "01110110", "01010111", "00110110",
        "11110111", "11010111", "01010111", "00000011"
    };
    
    string decrypted = "";
    
    for (int i = 0; i < 16; i++) {
        string byte = encrypted[i];
        
        byte[6] = (byte[6] == '0') ? '1' : '0';
        byte[7] = (byte[7] == '0') ? '1' : '0';
        
        string swapped = byte.substr(4, 4) + byte.substr(0, 4);
        
        int decimal = 0;
        for (int j = 0; j < 8; j++) {
            if (swapped[j] == '1') {
                decimal += (1 << (7 - j));
            }
        }
        
        decrypted += (char)decimal;
    }
    
    cout << decrypted << endl;
    
    return 0;
}
