#include <iostream>
#include <vector>

int idPlayer = 0;
int width = 0;
int height = 0;
std::vector<std::string> grid;

void println(std::string message){
    std::cout << message << std::endl;
}

void println(std::string message, int number){
    std::cout << message << number << std::endl;
}

std::string input(){
    std::string message;
    std::getline(std::cin, message);
    return message;
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

    if(nextInputMustBe("START player")){
        std::getline(std::cin, message);
        idPlayer = std::stoi(message);
        nextInputMustBe("STOP player");
    }

    if(nextInputMustBe("START settings")) {
        std::string inputSetting;
        do {
            std::getline(std::cin, inputSetting);
            //TODO use settings
        } while(inputSetting != "STOP settings");
    }

    int turn = 1;

    while (true){
        std::string message;

        std::string expectedInput = "START turn " + intStr(turn);
        if(nextInputMustBe(expectedInput)) {
            //TODO set grid ect
            std::cin >> message;
            width = std::stoi(message);
            std::cin >> message;
            height = std::stoi(message);

            for (int j = 0; j < height; j++) {
                std::getline(std::cin, message);
                //println(message);
                grid.push_back(message);
            }

            expectedInput = "STOP turn " + intStr(turn);
            nextInputMustBe(expectedInput);
        }

        println("START action ", turn);
        println("U");
        println("STOP action ", turn);
        turn += 1;
    }
}