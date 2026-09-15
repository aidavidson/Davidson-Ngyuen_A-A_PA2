#include <stdexcept>
#include "fileProcessor.h"
#include "World.h"

fileProcessor::fileProcessor(std::string input, std::string output){
    inputTxt = input;
    outputTxt = output;
    arr = new int[8];
    fullOutputBlock = "";
    outputStream.open(outputTxt);
    if (!outputStream.is_open()) {
        throw std::runtime_error("Could not open output file");
    }
}

fileProcessor::~fileProcessor(){
    delete[] arr;
}

int fileProcessor::processFile() {
    std::ifstream inputFile(inputTxt);

    if (!inputFile.is_open()) {
        std::cout << "Could not open input file.\n";
        return 1;
    }

    std::string val;
    int i = 0;

    while (std::getline(inputFile, val)) {
        arr[i] = std::stoi(val);
        i++;
    }

    if (i != 8) {
        return 1;
    }

    int total = 0;
    for (int j = 3; j < 8; j++) {
        total += arr[j];
    }

    if (total != 100) {
        std::cout << "Input percentages must sum to 100.\n";
        return 1;
    }

    // Convert percentages into tile counts.
    for (int j = 3; j < 8; j++) {
        arr[j] = (arr[1] * arr[1] * arr[j]) / 100;
    }

    inputFile.close();
    return 0;
}
//get array at that index of array of 
int fileProcessor::accessVal(int index){
    return arr[index];
}


//printing to file
int fileProcessor::outputFile(){
    std::ofstream outputFile(outputTxt);
}

void fileProcessor::addToOutput(std::string txt) {
    outputStream << txt;
    outputStream.flush(); // Makes progress visible while debugging.
}
// void fileProcessor::addToOutput(std::string txt){
//     fullOutputBlock += txt;
// }
