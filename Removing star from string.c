char* removeStars(char* s) {
    int index=0;
    int i;
    char* stack=malloc(strlen(s)+1);
    while(s[i]!='\0'){
        if(s[i]=='*'){
            index--;
        }
        else{
            stack[index]=s[i];
            index++;

        }
        i++;
        }
        stack[index]='\0';
        return stack;
    }
