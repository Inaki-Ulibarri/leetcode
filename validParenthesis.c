/****************************************************************************************************************************/
/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. */
/* 															    */
/* An input string is valid if:												    */
/*     Open brackets must be closed by the same type of brackets.							    */
/*     Open brackets must be closed in the correct order.								    */
/* Solution by Iñaki Ulibarri Utrilla											    */
/****************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s);
bool isCloser(char op, char cl);
bool isOpener(char op);

int main()
    {
    char *str1 = "()"; 
    char *str2 = "(({}[()[]]))";
    char *str3 = "(]";
    char *str4 = "([]){}[(";
    char *str5 = "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[";

    isValid(str1) ?
	printf("%s is valid\n", str1) : printf("%s is not valid\n", str1);
    isValid(str2) ?
	printf("%s is valid\n", str2) : printf("%s is not valid\n", str2);
    isValid(str3) ?
	printf("%s is valid\n", str3) : printf("%s is not valid\n", str3);
    isValid(str4) ?
	printf("%s is valid\n", str4) : printf("%s is not valid\n", str4);
    isValid(str5) ?
	printf("%s is valid\n", str5) : printf("%s is not valid\n", str5);

    return (0);
    }

bool isValid(char *s)
    {
    int const leng = strlen(s)+1;
    char str[leng];
    strcpy(str, s);
    //avoid WPB (weird pointer bs)
    char *nested = calloc(leng, sizeof(char));
    //don't try to half it, results in WPB
    size_t nest_pos = 0;
    bool ret = false;
    
    for (int pos = 0; pos < leng && str[pos];++pos)
	{
	if(isOpener(str[pos]))
	    {
	    nested[nest_pos] = str[pos];
	    ++nest_pos;
	    ret = false;
	    }
	else if (!(isOpener(str[pos])) &&
	    (nest_pos == 0))
	    {
	    ret = false;
	    break;
	    }
	else
	    {
	    nested[nest_pos] = str[pos];
	    if (isCloser(nested[nest_pos-1],
		    nested[nest_pos]))
		{
		if (nest_pos > 0)
		    {
		    nested[nest_pos] = 0;
		    nested[nest_pos-1] = 0;
		    nest_pos -= 1;
		    ret = true;
		    }
		else
		    {
		    fprintf(stderr, "Error: nest_pos out of bounds error, trying to write "
			"under the stack\n");
		    exit (1);
		    }		
		}
	    else
		{
		ret = false;
		break;
		}
	    }
	}

    free(nested);
    return (ret);
    }

bool isCloser(char op, char cl)
    {
    bool ret = false;
    switch(op)
	{
	case '(':
	    if (cl == ')')
		ret = true;
	    break;

	case '{':
	    if (cl == '}')
		ret = true;
	    break;

	case '[':
	    if (cl == ']')
		ret = true;
	    break;

	default:
	    fprintf(stderr, "Error comparing '%c' and '%c'\n",
		op, cl);
	    break;
	}
    return (ret);		
    }

bool isOpener(char op)
    {
    return (op == '(' ||
	op == '{' ||
	op == '[');
    }
