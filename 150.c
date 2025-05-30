int evalRPN(char** tokens, int tokensSize) {
    int *pilha = (int *)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++){
        if(strcmp(tokens[i], "+")==0){
            int b = pilha[top--];
            int a = pilha[top--];  
            pilha[++top] = a + b;
        }else
         if(strcmp(tokens[i], "-")==0){
            int b = pilha[top--];
            int a = pilha[top--];  
            pilha[++top] = a - b;
        }else
        if(strcmp(tokens[i], "*")==0){
            int b = pilha[top--];
            int a = pilha[top--];  
            pilha[++top] = a * b;
        }else
        if(strcmp(tokens[i], "/")==0){
            int b = pilha[top--];
            int a = pilha[top--];  
            pilha[++top] = a / b;
        }else{
            pilha[++top] = atoi(tokens[i]);
        }
    }
     
    int result = pilha[top];
    free(pilha);
    return result;
}