#include "fileProcessor.h"
#include "World.h"
fileProcessor::fileProcessor(std::string input, std::string output){
    inputTxt = input;
    outputTxt = output;
    arr = new int[8];
    fullOutputBlock = "";
}

fileProcessor::~fileProcessor(){
    delete[] arr;
}

int fileProcessor::processFile(){
    std::string val;
    std::ifstream inputFile(inputTxt);
    if(inputFile.is_open()){
        int i = 0;
        //these populate input file 
        while(std::getline(inputFile, val)){
            if(i > 2){
                arr[i] = arr[1]*arr[1]* arr[i]/100; //percent convert to spaces
            }else{
                arr[i] = stoi(val);
            }
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
//get array at that index of array of 
int fileProcessor::accessVal(int index){
    return arr[index];
}


//printing to file
int fileProcessor::outputFile(){
    std::ifstream outputFile(outputTxt);
}

void fileProcessor::addToOutput(std::string txt){
    fullOutputBlock += txt;
}
