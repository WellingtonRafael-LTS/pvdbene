# Trabalho de PDV em C

[![C Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Project Status](https://img.shields.io/badge/Status-Complete-green.svg)]()

> Uma solução leve e robusta para automatizar e blindar o registro de vendas em pequenos estabelecimentos.

---

### 📹 Demonstração do Sistema

Aqui você vê o sistema em ação, desde o menu principal até a finalização do pagamento com desconto.

![GIF Demonstrativo do Funcionamento do SisBene]([LINK_DO_SEU_GIF_AQUI])

*(Caso o GIF não carregue, você pode assistir à gravação completa clicando [aqui]([LINK_OPCIONAL_DO_YOUTUBE_AQUI])).*

---

### 📝 Resumo do Sistema

O SisBene é um simulador de Terminal de Frente de Caixa (PDV - Ponto de Venda) desenvolvido em linguagem C para rodar diretamente no terminal. Ele permite que o operador gerencie um carrinho de compras em tempo real, organizando produtos por categorias (Padaria, Alimentos, Limpeza), aplicando descontos automáticos de forma inteligente e finalizando pagamentos em diferentes modalidades.

---

### 🎯 O Problema (A Dor) que Resolve

Pequenos negócios costumam sofrer com duas dores principais ao realizar o registro manual ou o controle simplista de caixa:

1.  **Erros Lógicos e de Cálculo:** O cálculo manual de subtotais, totais e descontos progressivos é propenso a falhas, gerando prejuízos no fechamento de caixa ou cobrando valores errados do cliente.
2.  **Robustez de Sistema (A principal dor técnica):** Sistemas de terminal simples costumam "travar" ou quebrar se o operador digitar uma letra no lugar de um número. Isso causa lentidão na fila e exige o reinício do sistema, gerando frustração.

---

### A Solução

O SisBene resolve esses problemas através de Engenharia de Software focada na **robustez do input** e na **automação lógica**:

* **Automação do Fluxo de Caixa:** O sistema gerencia acumuladores precisos para categorias de produtos e para o total geral, aplicando descontos escalonados automaticamente (ex: 5%, 10% ou 18% baseados no valor final) apenas quando aplicável, eliminando o erro humano no cálculo.
* **Blidagem contra Input Inválido (Blidagem de Buffer):** Esta é a "feature de ouro". O sistema foi desenhado para **nunca quebrar**. Se o operador digitar letras em um campo numérico (como quantidade), o sistema intercepta o erro, limpa o buffer de memória (`stdin`) e pede o dado novamente, sem falhar.
* **Centralização de Preços:** Utiliza constantes (`#define`) para centralizar os preços no topo do código, facilitando a manutenção e a alteração de preços pelo administrador em questão de segundos.

---

### Principais Features

* **Interface TUI (Text User Interface):** menus organizados em caixas ASCII art e `system("cls || clear")` para uma experiência limpa e profissional.
* **Menu Principal Procedural:** Navegação estruturada por switch-cases entre Padaria, Limpeza, Alimentos e Pagamento.
* **Robustez de Teclado:** Implementação de loops do-while e limpeza estruturada de buffer de `lixo_de_memoria` para validação de quantidade e códigos.
* **Descontos Progressivos:** Sistema inteligente de pagamento que calcula tiered discounts baseado no `valor_total` final da compra.

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
Desenvolvido com foco na robustez por Wellington Rafael.
