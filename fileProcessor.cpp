#include "fileProcessor.h"
fileProcessor::fileProcessor(std::string input, std::string output){
    inputTxt = input;
    outputTxt = output;
    arr = new int[8];
}

fileProcessor::~fileProcessor(){
    delete[] arr;
}

int fileProcessor::processFile(){
    std::string val;
    std::ifstream inputFile(inputTxt);
    if(inputFile.is_open()){
        int i = 0;
        while(std::getline(inputFile, val)){
            arr[i] = stoi(val);
            i++;
        }
    }
    int total = 0;
    for(int i = 3; i < 8; i++){
        total += arr[i];
    }
    if(total > 100){
        std::cout << "input percentages do not equate to 100%" << std::endl;
        return 1;
    }
    inputFile.close();
    return 0;
}
int fileProcessor::accessVal(int index){
    return arr[index];
}