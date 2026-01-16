#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
    // Mensagem criptografada
    string encrypted[] = {
        "10010110", "11110111", "01010110", "00000001",
        "00010111", "00100110", "01010111", "00000001",
        "00010111", "01110110", "01010111", "00110110",
        "11110111", "11010111", "01010111", "00000011"
    };
    
    int size = 16;
    string decrypted = "";
    
    cout << "=== DESCRIPTOGRAFADOR INTELITRADER ===" << endl << endl;
    cout << "Mensagem criptografada:" << endl;
    for (int i = 0; i < size; i++) {
        cout << encrypted[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Processo de descriptografia:" << endl;
    cout << "----------------------------" << endl;
    
    for (int i = 0; i < size; i++) {
        string byte = encrypted[i];
        cout << "\nByte " << (i + 1) << ": " << byte << endl;
        
        // Passo 1: Inverter os 2 últimos bits (posições 6 e 7)
        byte[6] = (byte[6] == '0') ? '1' : '0';
        byte[7] = (byte[7] == '0') ? '1' : '0';
        cout << "Apos inverter ultimos 2 bits: " << byte << endl;
        
        // Passo 2: Trocar primeiros 4 bits com últimos 4 bits
        string firstHalf = byte.substr(0, 4);
        string secondHalf = byte.substr(4, 4);
        string swapped = secondHalf + firstHalf;
        cout << "Apos trocar grupos de 4 bits: " << swapped << endl;
        
        // Converter binário para decimal e depois para char
        int decimal = 0;
        for (int j = 0; j < 8; j++) {
            if (swapped[j] == '1') {
                decimal += (1 << (7 - j));
            }
        }
        
        char character = (char)decimal;
        cout << "Decimal: " << decimal << ", Caractere: '" << character << "'" << endl;
        
        decrypted += character;
    }
    
    cout << "\n================================" << endl;
    cout << "MENSAGEM DESCRIPTOGRAFADA:" << endl;
    cout << ">>> " << decrypted << " <<<" << endl;
    cout << "================================" << endl;
    
    return 0;
}#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
    // Mensagem criptografada
    string encrypted[] = {
        "10010110", "11110111", "01010110", "00000001",
        "00010111", "00100110", "01010111", "00000001",
        "00010111", "01110110", "01010111", "00110110",
        "11110111", "11010111", "01010111", "00000011"
    };
    
    int size = 16;
    string decrypted = "";
    
    cout << "=== DESCRIPTOGRAFADOR INTELITRADER ===" << endl << endl;
    cout << "Mensagem criptografada:" << endl;
    for (int i = 0; i < size; i++) {
        cout << encrypted[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Processo de descriptografia:" << endl;
    cout << "----------------------------" << endl;
    
    for (int i = 0; i < size; i++) {
        string byte = encrypted[i];
        cout << "\nByte " << (i + 1) << ": " << byte << endl;
        
        // Passo 1: Inverter os 2 últimos bits (posições 6 e 7)
        byte[6] = (byte[6] == '0') ? '1' : '0';
        byte[7] = (byte[7] == '0') ? '1' : '0';
        cout << "Apos inverter ultimos 2 bits: " << byte << endl;
        
        // Passo 2: Trocar primeiros 4 bits com últimos 4 bits
        string firstHalf = byte.substr(0, 4);
        string secondHalf = byte.substr(4, 4);
        string swapped = secondHalf + firstHalf;
        cout << "Apos trocar grupos de 4 bits: " << swapped << endl;
        
        // Converter binário para decimal e depois para char
        int decimal = 0;
        for (int j = 0; j < 8; j++) {
            if (swapped[j] == '1') {
                decimal += (1 << (7 - j));
            }
        }
        
        char character = (char)decimal;
        cout << "Decimal: " << decimal << ", Caractere: '" << character << "'" << endl;
        
        decrypted += character;
    }
    
    cout << "\n================================" << endl;
    cout << "MENSAGEM DESCRIPTOGRAFADA:" << endl;
    cout << ">>> " << decrypted << " <<<" << endl;
    cout << "================================" << endl;
    
    return 0;
}
