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
#include <tgmath.h>

bool isValid(char *s);
bool isCloser(char op, char cl);
bool isOpener(char op);

int main()
    {
    char *str1 = "()"; //valid
    char *str2 = "()[]{}";
    char *str3 = "(]";
    
    isValid(str1) ?
	printf("%s is valid\n", str1) : printf("%s is not valid\n", str1);
    isValid(str2) ?
	printf("%s is valid\n", str2) : printf("%s is not valid\n", str2);
    isValid(str3) ?
	printf("%s is valid\n", str3) : printf("%s is not valid\n", str3);

    return (0);
    }

bool isValid(char *s)
    {
    int const leng = strlen(s);
    char str[leng];
    strcpy(str, s);
    //avoid WPB (weird pointer bs)
    char nested
	[(int) ((ceil(leng)/2)+1)];
    //only need to house half of the parenthesis
    //at a time
    size_t nest_pos = 0;
    bool ret = false;
    
    for (size_t pos = 0; pos < leng;++pos)
	{
	if(isOpener(str[pos]))
	    {
	    nested[nest_pos] = str[pos];
	    ++nest_pos;
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
		    fprintf(stderr, "nest_pos out of bounds error, trying to write "
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
