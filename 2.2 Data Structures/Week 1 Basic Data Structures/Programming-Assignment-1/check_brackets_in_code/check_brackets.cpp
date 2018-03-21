#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    
    int err_pos = 0;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket item(next, position+1);
            opening_brackets_stack.push(item);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty()){
                err_pos = position + 1;
                break;
            }
            
            Bracket top = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if(!top.Matchc(next)){
                err_pos = top.position;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if(err_pos == 0 && opening_brackets_stack.empty()){
        cout << "Success";
    }
    else{
        if(err_pos == 0){
            while(opening_brackets_stack.size() > 1){
                opening_brackets_stack.pop();
            }
            err_pos = opening_brackets_stack.top().position;
        }
        cout << err_pos;
    }

    return 0;
}
