# Desafio de Descriptografia - Intelitrader

## Descrição do Problema

A Intelitrader interceptou uma mensagem criptografada. A criptografia aplicada tem duas operações:

1. A cada 4 bits, os 4 bits foram trocados com os próximos 4 bits
2. A cada 8 bits, os dois últimos bits foram invertidos

### Mensagem Criptografada
```
10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 
00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011
```

## Solução

Para descriptografar, precisamos reverter as operações na ordem inversa:

1. Primeiro: Inverter os 2 últimos bits
2. Segundo: Trocar os grupos de 4 bits de volta

## Exemplo Passo a Passo

Vamos descriptografar o primeiro byte: `10010110`

### Passo 1: Inverter os 2 últimos bits

Posições dos bits: 0 1 2 3 4 5 6 7

```
Original:     1 0 0 1 0 1 1 0
              ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑
Posições:     0 1 2 3 4 5 6 7
```

Invertemos os bits nas posições 6 e 7:
- Bit 6: 1 vira 0
- Bit 7: 0 vira 1

```
Resultado:    1 0 0 1 0 1 0 1
```

### Passo 2: Trocar grupos de 4 bits

Pegamos os primeiros 4 bits e os últimos 4 bits e trocamos de lugar:

```
Antes:        1001 | 0101
              ↓ ↓    ↓ ↓
Depois:       0101 | 1001
```

Resultado final: `01010001`

### Passo 3: Converter para ASCII

Convertemos o binário `01010001` para decimal:

```
01010001 (binário) = 64 + 16 + 1 = 81 (decimal)
```

O caractere ASCII 81 é: **R**

## Resultado Completo

Aplicando esse processo para todos os 16 bytes da mensagem:

```
Byte 1:  10010110 → 01010010 → 82 → 'R'
Byte 2:  11110111 → 01000101 → 69 → 'E'
Byte 3:  01010110 → 01010110 → 86 → 'V'
Byte 4:  00000001 → 01000101 → 69 → 'E'
Byte 5:  00010111 → 01010010 → 82 → 'R'
Byte 6:  00100110 → 01010011 → 83 → 'S'
Byte 7:  01010111 → 01000101 → 69 → 'E'
Byte 8:  00000001 → 00100000 → 32 → ' '
Byte 9:  00010111 → 01000001 → 65 → 'A'
Byte 10: 01110110 → 01001110 → 78 → 'N'
Byte 11: 01010111 → 01000100 → 68 → 'D'
Byte 12: 00110110 → 00100000 → 32 → ' '
Byte 13: 11110111 → 01010011 → 83 → 'S'
Byte 14: 11010111 → 01010111 → 87 → 'W'
Byte 15: 01010111 → 01000001 → 65 → 'A'
Byte 16: 00000011 → 01010000 → 80 → 'P'
```

### Mensagem Descriptografada
```
REVERSE AND SWAP
```

## Como Executar o Código C++

1. Acesse um compilador online:
   - https://www.onlinegdb.com/online_c++_compiler
   - https://www.programiz.com/cpp-programming/online-compiler/

2. Cole o código fornecido

3. Clique em "Run" ou "Executar"

4. O programa mostrará o processo completo de descriptografia

## Explicação do Código

### Estrutura Principal

```cpp
string encrypted[] = { /* bytes criptografados */ };
```

Array com os 16 bytes da mensagem criptografada.

### Loop de Descriptografia

Para cada byte:

```cpp
// Inverter bits 6 e 7
byte[6] = (byte[6] == '0') ? '1' : '0';
byte[7] = (byte[7] == '0') ? '1' : '0';
```

Inverte os dois últimos bits usando operador ternário.

```cpp
// Trocar grupos de 4 bits
string firstHalf = byte.substr(0, 4);
string secondHalf = byte.substr(4, 4);
string swapped = secondHalf + firstHalf;
```

Separa o byte em duas metades e troca a ordem.

```cpp
// Converter para decimal
int decimal = 0;
for (int j = 0; j < 8; j++) {
    if (swapped[j] == '1') {
        decimal += (1 << (7 - j));
    }
}
```

Converte o binário para decimal usando operador de shift.

```cpp
// Converter para caractere
char character = (char)decimal;
```

Converte o valor decimal para caractere ASCII.

## Conceitos Utilizados

- Manipulação de strings em C++
- Operações bit a bit
- Conversão binário para decimal
- Tabela ASCII
- Operador ternário
- Operador de shift (<<)
