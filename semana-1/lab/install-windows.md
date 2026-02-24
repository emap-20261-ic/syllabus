Tutorial para preparar o ambiente no windows para o curso:

1. Instalar o WSL: [https://learn.microsoft.com/pt-br/windows/wsl/install](url) <br>
Possível problema que pode ocorrer e sua solução:
![error](https://github.com/emap-ic-20241/syllabus/assets/99206764/5756e096-ff9c-4302-9a97-c6dc3f159123)

Após reiniciar o windows, se aparecer a mensagem de erro acima, você deve habilitar a opção de virtualização na BIOS do computador. Para tal, desligue-o e pressionando a tecla para abrir a BIOS assim que ligá-lo de volta (normalmente é a tecla "delete"). Agora, procure a opção SVM Mode e habilite-a (pode ser diferente para cada placa-mãe, então se não a achar, recomendo pesquisar como fazer para a sua).<br> Após isso, recomece o passo-a-passo do zero.

2. Instalar o Git: [https://git-scm.com/book/pt-br/v2/Começando-Instalando-o-Git](url)
3. Instalar o GCC: [Como instalar o compilador no WSL/Ubuntu #8](https://github.com/orgs/emap-ic-20241/discussions/8) (obrigado [@szacomelli](https://github.com/szacomelli) (: )
4. Instalar e configurar o VS Code: [https://learn.microsoft.com/pt-br/windows/wsl/tutorials/wsl-vscode](url) <br>
Detalhes IMPORTANTES: <br>
Instalar o VS Code em um diretório do WINDOWS;<br>
Durante a instalação, quando for solicitado a "Selecionar Tarefas Adicionais", marcar a opção ADICIONAR AO PATH;<br>
Instalar o [pacote de extensão Desenvolvimento Remoto](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack)

5. Instalar a extensão para programar em C no VS Code: [https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools](url) 
