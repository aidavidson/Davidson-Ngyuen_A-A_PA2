#ifndef VECTOR_H
#define VECTOR_H
class Vector{
    private:
        char type;
        int x;
        int y;
        bool chosen; //randomize, choose spaces. if already chosen, return true, send it to back of the array

    public:
        Vector();
        ~Vector();
        int getX(); //setting and getting y values for level
        int getY(); //setting and getting x values for level
        bool getChosen(); //getter here
        char getType();
        void setX(int newX);
        void setY(int newY);
        void setChosen(bool chosen); //setter here
        void setType(char c);
        static Vector* populateList(int n);


};
#endif