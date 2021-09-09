from dataclasses import dataclass
from __future__ import annotations
from typing import NewType

Topic = NewType('Topic', int)
NO_HELP_TOPIC: Topic = -1


@dataclass
class HelpHandler:
    topic : int = NO_HELP_TOPIC
    successor : HelpHandler = None

    def HasHelp(self) -> bool:
        return self.topic == NO_HELP_TOPIC

    def SetHandler(self, helpHandler : HelpHandler, topic: Topic):
        self.successor = helpHandler
        self.topic = topic

    def HandleHelp(self):
        if self.successor is None:
            return
        self.successor.HandleHelp()


class Widget(HelpHandler):    
    def __init__(self, parent):
        self.parent: Widget = parent
 

class Button(Widget):
    def __init__(self, w: Widget , t: Topic = NO_HELP_TOPIC):
        self.topic = w.topic
        self.parent = w.parent
        #self.successor = w.successor         

    def HandleHelp(self):
        if self.HasHelp():
            print("Button : HandleHelp")
        else:
            self.successor.HandleHelp()


class Dialog(Widget):
    def HandleHelp(self):
        if self.successor is None:
            return
        self.successor.HandleHelp()
    

class Application(HelpHandler):
    def HandleHelp(self):
        if self.successor is None:
            return
        self.successor.HandleHelp()


def main():
    print("Hello World!")
    w = Widget()

if __name__ == '__main__':
    main()
