char* gcdOfStrings(char* str1, char* str2) {
    int len1=strlen(str1);
    int len2=strlen(str2);
    int totallen=len1+len2;
    for(int i=0;i<totallen;i++){
        char char1=(i<len1)?str1[i]:str2[i-len1];
        char char2=(i<len2)?str2[i]:str1[i-len2];
        if(char1 != char2){
            return "";
        }
    }
    int a=len1;
    int b=len2;
    while(b!=0){
        int remainder=a%b;
        a=b;
        b=remainder;
    }
    int gcdLength=a;
    
    str1[gcdLength]='\0';
    return str1;
}
