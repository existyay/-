#include<bits/stdc++.h>
using namespace std;
bool isNumber(char* token) {
    return strlen(token) > 1 || ('0' <= token[0] && token[0] <= '9');
}

int evalRPN(char** tokens, int tokensSize) {
    int n = tokensSize;
    int stk[n], top = 0;
    for (int i = 0; i < n; i++) {
        char* token = tokens[i];
        if (isNumber(token)) {
            stk[top++] = atoi(token);
        } else {
            int num2 = stk[--top];
            int num1 = stk[--top];
            switch (token[0]) {
                case '+':
                    stk[top++] = num1 + num2;
                    break;
                case '-':
                    stk[top++] = num1 - num2;
                    break;
                case '*':
                    stk[top++] = num1 * num2;
                    break;
                case '/':
                    stk[top++] = num1 / num2;
                    break;
            }
        }
    }
    return stk[top - 1];
}
int main(){
	int a,b;
	char string;
	
} 
