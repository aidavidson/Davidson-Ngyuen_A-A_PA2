#include "vector.h"

Vector::Vector(){
    
}

Vector::~Vector(){

}
int Vector::getX(){
    return x;
}
int Vector::getY(){
    return y;
}
bool Vector::getChosen(){
    return chosen;
}
char Vector::getType(){
    return type;
}
void Vector::setX(int newX){
    x = newX;
}
void Vector::setY(int newY){
    y = newY;
}
void Vector::setChosen(bool chosen){
    this->chosen = chosen;
}
void Vector::setType(char c){
    type = c;
}
//set to normal placeholder indexes, empty. empty vectors. not random. 
Vector* Vector::populateList(int n){
    Vector* arr = new Vector[n*n];
    //for each element in the array
    //convert to n * n matrix to 1d array of grids
    for(int i = 0; i < n; i++){ //to be fixed
        for(int j = 0; j < n; j++){
            arr[i+j].setX(i);
            arr[i+j].setY(j);
            arr[i+j].setChosen(false);
        } //pass by reference, from vector
    }


    delete[] arr;
}