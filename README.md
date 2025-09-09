# Projeto Super Trunfo (Cadastro e Comparação) em C 🃏

Oi de novo! 👋

Este é o segundo desafio sobre Super Trunfo que fiz para a faculdade. O objetivo aqui era um pouco diferente do primeiro jogo: o foco era no **cadastro completo dos dados** das cartas e depois em fazer uma **análise automática**, comparando todos os atributos de uma vez só.

---

### O que o Programa Faz?

O programa é bem direto e linear, sem menus. Ele segue estes passos:

1.  Pede pra você digitar os 4 atributos da **Carta 1** (População, Área, etc.).
2.  Pede pra você digitar os 4 atributos da **Carta 2**.
3.  Depois disso, ele mostra um **resumo completo** de cada carta na tela, já calculando na hora a *Densidade Populacional* e o *PIB per Capita*.
4.  Em seguida, ele exibe uma **tabela de comparação**, dizendo quem vence em cada atributo (mostrando `1` se a Carta 1 venceu, ou `0` se a Carta 2 venceu ou empatou).
5.  Por fim, ele calcula um **"Super Poder"** para cada carta (uma soma maluca de todos os atributos) e mostra quem vence nessa disputa final.

---

### Principal Desafio do Projeto

Uma regra interessante do desafio era que o cadastro das cartas deveria ser feito **sem usar laços de repetição (for/while)**.

É por isso que, ao olhar o código, você vai ver que a parte de pedir os dados da Carta 1 é basicamente copiada e colada para a Carta 2. Foi um jeito de seguir a regra do exercício e focar apenas nas variáveis e cálculos.

---

### O que eu Pratiquei com esse Código?

* Manipulação de diferentes tipos de variáveis (como `unsigned long int` para a população, que pode ser um número bem grande).
* Cálculos matemáticos, incluindo a conversão de tipos (`casting`) para a soma do Super Poder não dar erro de precisão.
* Uso do **operador ternário ( `? :` )**, que foi um jeito bem legal e compacto de fazer a lógica de comparação e mostrar o `1` ou `0`.

---

### Como Rodar o Código

Você vai precisar de um compilador C (como o GCC).

1.  Abra o terminal na pasta onde está o arquivo do projeto.
2.  Compile o código com o comando:
    ```bash
    gcc nome_do_arquivo.c -o programa.exe
    ```
    *(Lembre-se de trocar `nome_do_arquivo.c` pelo nome certo)*
3.  Agora é só rodar!
    ```bash
    ./programa.exe
    ```

---
Feito por Rômulo.
