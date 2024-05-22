#include "../include/gpm.hpp"
#include "parser.cpp"
#include "dispatcher.cpp"
#include "inputhandler.cpp"

    auto main -> int() {
        Parser parser = new Parser();
        Dispatcher dispatch = new Dispatcher();
        InputHandler input = new InputHandler();

        while (true) {
            auto in = input.getInput();
            auto command = parser.parse(in);
            auto output = dispatch.send(command);
            std::cout << "success";
        }
    }
