# python3

import sys

class Bracket:
    def __init__(self, bracket_type, position):
        self.bracket_type = bracket_type
        self.position = position

    def Match(self, c):
        if self.bracket_type == '[' and c == ']':
            return True
        if self.bracket_type == '{' and c == '}':
            return True
        if self.bracket_type == '(' and c == ')':
            return True
        return False

class Stack(object):
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items)-1]

    def size(self):
        return len(self.items)

def parChecker(text):
    s = Stack()
    for index, char in enumerate(text, start=1):
        if char in ("[", "(", "{"):
            item = Bracket(char, index)
            s.push(item)
        elif char in ("]", ")", "}"):
            if s.isEmpty():
                return index
            
            top = s.pop()
            if not top.Match(char):
                return index

    if not s.isEmpty():
        top = s.pop()
        return top.position
    return "Success"
    
        
if __name__ == "__main__":
    text = sys.stdin.read()

    print(parChecker(text))
