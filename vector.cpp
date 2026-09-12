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
Vector* Vector::populateList(int n){
    Vector* arr = new Vector[n*n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i+j].setX(i);
            arr[i+j].setY(j);
            arr[i+j].setChosen(false);
        }
    }
    delete[] arr;
}