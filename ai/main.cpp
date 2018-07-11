#include <iostream>

int idPlayer = 0;

void println(std::string message){
    std::cout << message << std::endl;
}

void println(std::string message, int number){
    std::cout << message << number << std::endl;
}

bool nextInputMustBe(std::string input){
    std::string message;
    std::getline(std::cin, message);
    if (message == input){
        return true;
    }
    return false;
}

std::string intStr(int i){
    return std::to_string(i);
}

int main() {
    std::string message;
    std::getline(std::cin, message);

    if(nextInputMustBe("START player"))
        idPlayer = std::stoi(message);

    nextInputMustBe("STOP player");

    if(nextInputMustBe("START settings")){
        std::string line;
        std::getline(std::cin, line);
        while(line != "STOP settings"){
            std::getline(std::cin, line);
        }
    }

    int turn = 1;

    while (true){
        std::string message;
        std::getline(std::cin, message);
        println(message);
        std::string input = "START turn " + intStr(turn);
        if(nextInputMustBe(input)){
            //println(input);
        }

        println("START ACTION ", turn);
        println("U");
        println("STOP ACTION ", turn);
        turn += 1;
    }
}