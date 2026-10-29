# Jogo 21

Jogo de cartas 21 desenvolvido em linguagem C no terminal, como exercício prático de programação.

## Sobre o jogo

Versão simplificada do clássico jogo de cartas "21" (Blackjack): o jogador recebe cartas iniciais e pode pedir mais cartas para se aproximar do valor 21 sem o ultrapassar. O computador joga como adversário com pontuação gerada automaticamente.

## Funcionalidades

- Distribuição automática de 3 cartas iniciais
- Opção de pedir mais cartas ou parar
- Verificação automática de vitória, derrota ou empate
- Sistema de placar que regista vitórias, empates e derrotas
- Opção de jogar várias rondas seguidas

## Conceitos de programação praticados

- Funções com parâmetros e valores de retorno
- Ciclos de repetição (`while`, `do-while`)
- Estruturas de decisão (`if` / `else`)
- Geração de números aleatórios com `rand()` e `srand()`
- Entrada e validação de dados do utilizador

## Como compilar e executar

```bash
gcc jogo21.c -o jogo21
./jogo21
