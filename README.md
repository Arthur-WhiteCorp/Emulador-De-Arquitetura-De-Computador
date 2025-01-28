# Emulador de Arquitetura RISC

## Visão Geral

Emulador para a arquitetura **RISC** (Reduced Instruction Set Computing), desenvolvido para testar e validar o **Compilador MiniC**. O emulador executa o código assembly gerado pelo compilador MiniC, proporcionando um ambiente para verificar e depurar a saída do compilador em um ambiente simulado de arquitetura RISC.

## Autor

**Arthur Silva Matias**

## Linguagens e Ferramentas Utilizadas:
- **Linguagem de Programação**: C++
- **Sistema de Build**: CMake

## Descrição

O **Emulador de Arquitetura RISC** é uma ferramenta criada para emular uma arquitetura RISC (Computação com Conjunto de Instruções Reduzido). Seu objetivo é ajudar a testar o código compilado pelo **Compilador MiniC** e montado pelo **Assembler**  executando-o em um ambiente controlado que simula o funcionamento de uma máquina baseada em RISC. O emulador foi projetado para verificar a correção e o desempenho do código gerado.

### Principais Funcionalidades:
- **Simulação do Conjunto de Instruções RISC**: Emula uma arquitetura RISC simplificada com um conjunto reduzido de instruções.
- **Integração com o Compilador MiniC**: Valida o código gerado pelo **Compilador MiniC**, executando-o em um ambiente simulado.
- **Depuração e Validação**: Ajuda a identificar erros ou problemas na geração de código do compilador MiniC.

## Repositório do Compilador MiniC

O emulador funciona em conjunto com o **Compilador MiniC**, cujo repositório pode ser acessado no link abaixo:

[Repositório do Compilador MiniC](https://github.com/Arthur-WhiteCorp/Compilador-MiniC)

Para instruções detalhadas sobre como utilizar o compilador MiniC, consulte o repositório correspondente.

## Repositório do Assembler

O emulador recebe código montado pelo  **Assembler**, cujo repositório pode ser acessado no link abaixo:

[Repositório do Assembler MiniC](https://github.com/Arthur-WhiteCorp/Assembler)

Para instruções detalhadas sobre como utilizar o Assembler, consulte o repositório correspondente.


## Execução

Para utilizar o Emulador de Arquitetura RISC, siga os passos abaixo:

1. **Clone este repositório:**
   ```bash
   git clone https://github.com/Arthur-WhiteCorp/Emulador-De-Arquitetura-De-Computador.git
   ```
2. **Compile o programa:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. **Execute**
   ```bash
   ./project
   ```
## Regras de Nomenclatura e Documentação

Para mais informações sobre as regras de nomenclatura e documentação utilizadas no desenvolvimento do Compilador, Assembler e Emulador, consulte a [documentação oficial](https://arthur-7.gitbook.io/doccompiler).

---
