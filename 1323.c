int maximum69Number (int num) {
    char str[10];
    sprintf(str, "%d",  num);

    for(int i=0; i<10; i++){
        if(str[i] == '6'){
            str[i] = '9';
            break;
        }
    }
    return atoi(str);
}