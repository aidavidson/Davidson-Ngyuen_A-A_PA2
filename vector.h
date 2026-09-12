#ifndef VECTOR_H
#define VECTOR_H
class Vector{
    private:
        char type;
        int x;
        int y;
        bool chosen;

    public:
        Vector();
        ~Vector();
        int getX();
        int getY();
        bool getChosen();
        char getType();
        void setX(int newX);
        void setY(int newY);
        void setChosen(bool chosen);
        void setType(char c);
        static Vector* populateList(int n);


};
#endif