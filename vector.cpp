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
    
    //preserves the index of the 1d array which is being populated
    int index = 0;
    
    //a for loop which allows the method to set row index and column index properly
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            //set the proper instance variables of the objects
            arr[index].setX(i);
            arr[index].setY(j);
            arr[index].setChosen(false);

            //incrememnts index so we know one has been filled so we move to the next
            index++;
        }
    }
    return arr;
}