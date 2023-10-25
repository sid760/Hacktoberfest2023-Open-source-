// Program to convert mathematical expressioni in infix notation to postfix notation
// uses stack
// status : works for expression excluding parenthesis

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// mapping operator precedence
unordered_map<char, int> op_precedence = {
    {'(', 0},
    {'/', 1},
    {'*', 1},
    {'+', 2},
    {'-', 2},
};

// Converts infix notation to postfix notation
string postfix(string str)
{
    // declare stack
    stack<char> st;

    // string to store the result, and return
    string res;

    // traverse the original string
    int i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            st.push(str[i]);

        else if (str[i] == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }

        // case when symbol is a character or a number i.e. 0-9, a-z, A-Z
        else if (str[i] >= 48 && str[i] <= 57 ||
                 str[i] >= 65 && str[i] <= 90 ||
                 str[i] >= 97 && str[i] <= 122)
            res += str[i];

        // case when symbol is an operator, i.e. +, -, /, *
        else if (op_precedence.count(str[i]))
        {
            if (!st.empty())
            {
                if (op_precedence[str[i]] > op_precedence[st.top()])
                {
                    res += st.top();
                    st.pop();
                }
            }
            st.push(str[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string expr;
    cout << "Enter a mathematical expression: ";
    getline(cin, expr);

    cout << "postfix notation: " << postfix(expr) << endl;

    return 0;
}
