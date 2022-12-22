/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: calculator
 File Name: calculator.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/11/28
 Brief description of this program: A lab project.
    visit https://box.nju.edu.cn/f/dd2244548a2b43bcb59a/ to find more.
----------------------- END -----------------------
**************************************************/

/*----------Begin of Include Section----------*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
/*----------End of Include Section----------*/

/*----------Begin of Typedef Section----------*/
typedef struct value {
    enum {
        Int, Float, ErrorVal
    } type;
    union {
        int intValue;
        double floatValue;
    };
} value;

typedef struct token {
    enum {
        Operator, Value, Bracket, Equal, Variable, ErrorToken
    } type;
    char src[500];
    value val;
    int bracketIdentifier;
} token;

typedef struct expression {
    enum {
        Calc, Assignment, ErrorExpr
    } type;
    token src[1200];//start from 1;
    int tokenCnt;
} expression;

typedef struct variable {
    char name[500];
    value val;
} variable;
int varCnt = 0;
variable varMap[150];
/*----------End of Typedef Section----------*/

/*----------Begin of Function Section----------*/

/*---- Process Token----*/
bool isValidOperator(char *src) {
    const char validOperator[][2] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; i++) {
        if (!strcmp(src, validOperator[i])) {
            return true;
        }
    }
    return false;
}

bool isNumber(char *src) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        if (!((isdigit(src[i])) || src[i] == '.')) {
            return false;
        }
    }
    return true;
}

int processInteger(char *src) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        if (!(isdigit(src[i]))) {
            return -1;
        }
    }
    if (src[0] == '0') {
        return -1;
    }
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret += (src[i] - '0');
        ret *= 10;
    }
    ret /= 10;
    return ret;
}

double processFloat(char *src) {
    if (src[0] == '.') {
        return -1;
    }
    int len = strlen(src);
    int pointPos = 0;
    for (int i = 1; i < len; i++) {
        if (!pointPos && src[i] == '.') {
            pointPos = i;
        } else if (pointPos && src[i] == '.') {
            return -1;
        }
    }
    if (pointPos != 1 && src[0] == '0') {
        return -1;
    }
    if (pointPos == len - 1) {
        return -1;
    }
    double ret = 0;
    for (int i = 0; i < len; i++) {
        if(i==pointPos){
            continue;
        }
        ret += (src[i] - '0');
        ret *= 10;
    }
    ret/=10;
    for(int i=1;i<=((len - 1 - pointPos));i++){
        ret/=10;
    }
    //ret += (afterPoint * pow(10, -(len - 1 - pointPos)));
    return ret;
}

bool isValidVariable(char *src) {
    if (isdigit(src[0])) {
        return false;
    }
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        if (!((isalpha(src[i])) || (isdigit(src[i])) || src[i] == '_')) {
            return false;
        }
    }
    return true;
}

bool isBracket(char *src) {
    if (strcmp(src, "(") == 0 || strcmp(src, ")") == 0) {
        return true;
    }
    return false;
}

void printExprEval(expression src) {
    if (src.type == ErrorExpr) {
        printf("This expression could not be analyzed\n");
        return;
    }
    printf("---Token--List---\n");
    printf("Num\tDetail\tType\tEtc\n");
    for (int i = 1; i <= src.tokenCnt; i++) {
        printf("%d\t%s\t%d\t", i, src.src[i].src, src.src[i].type);
        if (src.src[i].type == Bracket) {
            printf("%d\t", src.src[i].bracketIdentifier);
        }
        if (src.src[i].type == Value) {
            printf("%d(type)\t",src.src[i].val.type);
            printf("%lf(float)\t", src.src[i].val.floatValue);
            printf("%d(int)\t", src.src[i].val.intValue);
        }
        printf("\n");
    }
    printf("---End--of--Token--List---\n");
}

expression expressionEval(char *srcStr) {
    /* initialize */
    expression ret;
    ret.tokenCnt = 0;
    int len = strlen(srcStr);
    ret.type = Calc;

    /* preprocess source string */
    char tmp[100], tmpCnt = 0;
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < len; i++) {
        if (srcStr[i] == ' ') {
            if((tmpCnt)&&(strcmp(tmp," ")!=0)){
                strcpy((char *) &(ret.src[++ret.tokenCnt].src), tmp);
                memset(tmp, 0, sizeof(tmp));
                tmpCnt = 0;
            }
        } else {
            tmp[tmpCnt++] = srcStr[i];
        }
    }
    if((tmpCnt)&&(strcmp(tmp," ")!=0)){
        strcpy((char *) &(ret.src[++ret.tokenCnt].src), tmp);
    }

    /* analyze token */
    for (int i = 1; i <= ret.tokenCnt; i++) {
        if (!strcmp(ret.src[i].src, "=")) {
            //here will be more actions
            ret.type = Assignment;
            ret.src[i].type = Equal;
        } else if (isValidOperator(ret.src[i].src)) {
            ret.src[i].type = Operator;
        } else if (isNumber(ret.src[i].src)) {
            if (processInteger(ret.src[i].src) < 0 && processFloat(ret.src[i].src) < 0) {
                ret.type = ErrorExpr;
                ret.src[i].type = ErrorToken;
                return ret;
            }
            if (processInteger(ret.src[i].src) != -1) {
                ret.src[i].type = Value;
                ret.src[i].val.type = Int;
                ret.src[i].val.intValue = processInteger(ret.src[i].src);
            } else {
                ret.src[i].type = Value;
                ret.src[i].val.type = Float;
                ret.src[i].val.floatValue = processFloat(ret.src[i].src);
            }
        } else if (isValidVariable(ret.src[i].src)) {
            ret.src[i].type = Variable;
        } else if (isBracket(ret.src[i].src)) {
            ret.src[i].type = Bracket;
        } else {
            ret.type = ErrorExpr;
            ret.src[i].type = ErrorToken;
            return ret;
        }
    }

    /* match brackets */
    token *stack[40];
    int top = 0;
    int identifier = 0;
    for (int i = 1; i <= ret.tokenCnt; i++) {
        if (ret.src[i].type == Bracket) {
            if (strcmp(ret.src[i].src, "(") == 0) {
                stack[++top] = &(ret.src[i]);
            } else {
                if (!top) {
                    ret.type = ErrorExpr;
                    ret.src[i].type = ErrorToken;
                    return ret;
                }
                if (strcmp(stack[top]->src, "(") == 0) {
                    stack[top]->bracketIdentifier = ++identifier;
                    ret.src[i].bracketIdentifier = identifier;
                    top--;
                } else {
                    ret.type = ErrorExpr;
                    ret.src[i].type = ErrorToken;
                    return ret;
                }
            }
        }
    }
    if (top) {
        ret.type = ErrorExpr;
        return ret;
    }

    /* return */
    return ret;
}
/*----End of Process Token----*/

/*----Calculate Value----*/
int checkExistValAmount(int l, int r, expression src) {
    int valAmount = 0;
    for (int i = l; i <= r; i++) {
        if (src.src[i].type == Value || src.src[i].type == Variable) {
            valAmount++;
        }
    }
    return valAmount;
}

bool isValidMinusExpr(int l, int r, expression src) {
    if (checkExistValAmount(l, r, src) != 1) {
        return false;
    }
    for (int i = l; i <= r; i++) {
        token now = src.src[i];
        if (!((now.type == Value || now.type == Variable) || strcmp(now.src, "-") == 0)) {
            return false;
        }
    }
    if (src.src[r].type != Value && src.src[r].type != Variable) {
        return false;
    }
    return true;
}

bool isMinus(int pos, int l, expression src){
    if(pos==l){
        return true;
    }
    if(src.src[pos-1].type==Operator){
        return true;
    }
    return false;
}

int findMainOperator(int l, int r, expression *src) {
    int bracketStatus = 0, mainOperatorPos = 0, mainOperatorType = 0, haveOperator=0;//1 for +-, 2 for */
    for (int i = l; i <= r; i++) {
        token now = (*src).src[i];
        if (now.type == Bracket && (!bracketStatus)) {
            bracketStatus = now.bracketIdentifier;
        } else if (now.type == Bracket && bracketStatus == now.bracketIdentifier) {
            bracketStatus = 0;
        }
        if ((!bracketStatus) && now.type == Operator) {
            haveOperator=1;
            if ((strcmp(now.src, "*") == 0 || strcmp(now.src, "/") == 0) && (mainOperatorType != 1)) {
                mainOperatorPos = i;
                mainOperatorType = 2;
            } else if ((strcmp(now.src, "+") == 0 || (strcmp(now.src, "-") == 0 && (!isMinus(i,l,*src))))) {
                mainOperatorPos = i;
                mainOperatorType = 1;
            }
        }
    }
    if(!haveOperator){
        return -1;
    }
    return mainOperatorPos;//0 for no main operator found;
}

value valueCalc(value src1, value src2, char op) {
    value ret;
    if (src1.type == ErrorVal || src2.type == ErrorVal) {
        ret.type = ErrorVal;
        return ret;
    }
    if (src1.type != src2.type) {
        ret.type = Float;
        switch (op) {
            case '+':
                if (src1.type == Float) {
                    ret.floatValue = src1.floatValue + src2.intValue;
                } else {
                    ret.floatValue = src1.intValue + src2.floatValue;
                }
                break;
            case '-':
                if (src1.type == Float) {
                    ret.floatValue = src1.floatValue - src2.intValue;
                } else {
                    ret.floatValue = src1.intValue - src2.floatValue;
                }
                break;
            case '*':
                if (src1.type == Float) {
                    ret.floatValue = src1.floatValue * src2.intValue;
                } else {
                    ret.floatValue = src1.intValue * src2.floatValue;
                }
                break;
            case '/':
                if (src1.type == Float) {
                    ret.floatValue = src1.floatValue / src2.intValue;
                } else {
                    ret.floatValue = src1.intValue / src2.floatValue;
                }
                break;
            default:
                ret.type = ErrorVal;
                return ret;
                break;
        }
    } else {
        if (src1.type == Int) {
            ret.type = Int;
            switch (op) {
                case '+':
                    ret.intValue = src1.intValue + src2.intValue;
                    break;
                case '-':
                    ret.intValue = src1.intValue - src2.intValue;
                    break;
                case '*':
                    ret.intValue = src1.intValue * src2.intValue;
                    break;
                case '/':
                    ret.intValue = src1.intValue / src2.intValue;
                    break;
                default:
                    ret.type = ErrorVal;
                    return ret;
                    break;
            }
        } else if (src1.type == Float) {
            ret.type = Float;
            switch (op) {
                case '+':
                    ret.floatValue = src1.floatValue + src2.floatValue;
                    break;
                case '-':
                    ret.floatValue = src1.floatValue - src2.floatValue;
                    break;
                case '*':
                    ret.floatValue = src1.floatValue * src2.floatValue;
                    break;
                case '/':
                    ret.floatValue = src1.floatValue / src2.floatValue;
                    break;
                default:
                    ret.type = ErrorVal;
                    return ret;
                    break;
            }
        } else {
            ret.type = ErrorVal;
            return ret;
        }
    }
    return ret;
}

value valueEval(int l, int r, expression *src) {
    /* preprocess */
    value ret;
    if (l > r) {
        ret.type = ErrorVal;
        return ret;
    }
    if (l == r) {
        if ((*src).src[l].type == Value) {
            return (*src).src[l].val;
        } else if ((*src).src[l].type == Variable) {
            bool variableFound = 0;
            for (int i = 1; i <= varCnt; i++) {
                if (strcmp((*src).src[l].src, varMap[i].name) == 0) {
                    variableFound = 1;
                    return varMap[i].val;
                }
            }
            if (!variableFound) {
                ret.type = ErrorVal;
                return ret;
            }
        } else {
            ret.type = ErrorVal;
            return ret;
        }
    }
    if ((*src).src[l].type == Bracket && (*src).src[r].type == Bracket &&
            (*src).src[l].bracketIdentifier == (*src).src[r].bracketIdentifier) {
        return valueEval(l + 1, r - 1, src);
    }

    /* find main operator */
    int mainOperatorPos = findMainOperator(l, r, (src));
    if (!mainOperatorPos) {
        ret = valueEval(l + 1, r, src);
        if(ret.type==Float){
            ret.floatValue = (-1.0)*ret.floatValue;
        }else if(ret.type==Int){
            ret.intValue = -ret.intValue;
        }else{
            ret.type = ErrorVal;
            return ret;
        }
        return ret;
    } else if(mainOperatorPos!=-1) {
        if (strcmp((*src).src[mainOperatorPos].src, "+") == 0) {
            return valueCalc(valueEval(l, mainOperatorPos - 1, src), valueEval(mainOperatorPos + 1, r, src), '+');
        } else if (strcmp((*src).src[mainOperatorPos].src, "-") == 0) {
            return valueCalc(valueEval(l, mainOperatorPos - 1, src), valueEval(mainOperatorPos + 1, r, src), '-');
        } else if (strcmp((*src).src[mainOperatorPos].src, "*") == 0) {
            return valueCalc(valueEval(l, mainOperatorPos - 1, src), valueEval(mainOperatorPos + 1, r, src), '*');
        } else if (strcmp((*src).src[mainOperatorPos].src, "/") == 0) {
            return valueCalc(valueEval(l, mainOperatorPos - 1, src), valueEval(mainOperatorPos + 1, r, src), '/');
        } else {
            ret.type = ErrorVal;
            return ret;
        }
    }else{
        ret.type = ErrorVal;
        return ret;
    }
}
/*----End of Calculate Value----*/

/*----Assign Value----*/
value assignValue(expression src) {
    int lastEqualPos = 0;
    value ret;
    for (int i = src.tokenCnt; i >= 1; i--) {
        token now = src.src[i];
        if (now.type == Equal) {
            lastEqualPos = i;
            break;
        }
    }
    ret = valueEval(lastEqualPos + 1, src.tokenCnt, &src);
    for(int i=lastEqualPos;i>=1;i--){
        token now=src.src[i];
        if (now.type != Equal && now.type != Variable) {
            ret.type = ErrorVal;
            return ret;
        }else if(now.type==Equal){
            if(src.src[i-1].type!=Variable){
                ret.type = ErrorVal;
                return ret;
            }
        }
    }
    for (int i = lastEqualPos; i >= 1; i--) {
        token now = src.src[i];
        if (now.type == Variable) {
            bool variableFound = false;
            for (int j = 1; j <= varCnt; j++) {
                if (strcmp(now.src, varMap[j].name) == 0) {
                    variableFound = true;
                    varMap[j].val.type=ret.type;
                    varMap[j].val.floatValue=ret.floatValue;
                    varMap[j].val.intValue=ret.intValue;
                }
            }
            if (!variableFound) {
                varMap[++varCnt].val = ret;
                strcpy(varMap[varCnt].name, now.src);
            }
        }
    }
    return ret;
}

/*----End of assign Value----*/

void printVal(value src) {
    if (src.type == Float) {
        printf("%.6lf\n", src.floatValue);
    } else if (src.type == Int) {
        printf("%d\n", src.intValue);
    } else if (src.type == ErrorVal) {
        printf("Error\n");
    }
}

/*----------End of Function Section----------*/

/*----------Main Function Section----------*/
int main() {

    freopen("in","r",stdin);
//    freopen("out","w",stdout);

    char input[1200];
    while (gets(input) != NULL) {
        expression expr = expressionEval(input);
        if (expr.type == Assignment) {
            printVal(assignValue(expr));
        } else if (expr.type == Calc) {
            printVal(valueEval(1, expr.tokenCnt, &expr));
        } else if (expr.type == ErrorExpr) {
            printf("Error\n");
        }
    }

    return 0;
}
/*----------End of Main Function Section----------*/