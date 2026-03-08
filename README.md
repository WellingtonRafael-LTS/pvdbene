# Trabalho de PDV em C

[![C Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Project Status](https://img.shields.io/badge/Status-Complete-green.svg)]()

> Primeiro trabalho mensal 2026 - Analise e Desenvolvimento de Sistema - UniAmérica.

---

### Demonstração do Sistema

Aqui você vê o sistema em ação, desde o menu principal até a finalização do pagamento com desconto.

![GIF Demonstrativo do Funcionamento do SisBene]([LINK_DO_SEU_GIF_AQUI])

*(Caso o GIF não carregue, você pode assistir à gravação completa clicando [aqui]([LINK_OPCIONAL_DO_YOUTUBE_AQUI])).*

### Features

* **Interface:** menus organizados em caixas ASCII art e `system("cls || clear")` para uma experiência limpa e profissional.
* **Menu Principal Procedural:** Navegação estruturada por switch-cases entre Padaria, Limpeza, Alimentos e Pagamento.
* **Tratamento de Erro:** Implementação de loops do-while e limpeza estruturada de buffer de `lixo_de_memoria` para validação de quantidade e códigos.
* **Descontos Progressivos:** Sistema inteligente de pagamento que calcula o desconto baseado no `valor_total` final da compra.

---

### Como Executar

Este é um projeto **Console Procedural** que não requer bibliotecas externas, apenas a biblioteca padrão do compilador C.

**Requisitos:** Compilador C (GCC) instalado.

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/WellingtonRafael-LTS/pvdbene.git](https://github.com/WellingtonRafael-LTS/pvdbene.git)
    cd pvdbene
    ```
2.  **Compile o código:**
    ```bash
    gcc sistema.c -o sisbene
    ```
3.  **Execute o programa:**
    * No Windows: `sisbene.exe`
    * No Linux/macOS: `./sisbene`

---

## Referências e Créditos

Este projeto foi desenvolvido aplicando os conceitos e ferramentas das seguintes fontes de estudo:

**Bibliografia**
* **Livro:** KERNIGHAN, Brian W.; RITCHIE, Dennis M. *C: A Linguagem de Programação*.
* **Livro:** BACKES, André. *Linguagem C: Completa e Descomplicada*.
* **Curso em Vídeo:** [Linguagem C - Começando do absoluto zero](https://www.youtube.com/watch?v=2w8GYzBjNj8&list=PLpaKFn4Q4GMOBAeqC1S5_Fna_Y5XaOQS2) Curso online.
* **Apoio Teórico:** [Curso de Programação em C - UFSC](http://mtm.ufsc.br/~azeredo/cursoC/) - Material acadêmico.

**Códigos de Apoio**
* **Repositório de Exercícios:** [GitHub misaelrezende/Exercicios-do-Livro-Linguagem-C](https://github.com/misaelrezende/Exercicios-do-Livro-Linguagem-C-Completa-e-Descomplicada).
* **C:** [Documentação da Linguagem C](https://en.cppreference.com/w/c).

**Ferramentas**
* **Tipografia do Terminal:** [Patorjk's ASCII Art Generator](https://patorjk.com/software/taag/#p=display&f=Big+Money-nw&t=MERCADINHO+SHOP&x=none&v=4&h=4&w=80&we=false)
* **Badges do Repositório:** [Shields.io](https://shields.io/).
