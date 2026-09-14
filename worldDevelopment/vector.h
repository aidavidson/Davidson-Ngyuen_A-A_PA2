#ifndef VECTOR_H
#define VECTOR_H
class Vector{
    private:
        // type of space on the map
        char type;
        // row index
        int x;
        // col index
        int y;
        bool chosen; //randomize, choose spaces. if already chosen, return true, send it to back of the array

    public:
        //constructor / destructor
        Vector();
        ~Vector();
        int getX(); //setting and getting y values for level
        int getY(); //setting and getting x values for level
        bool getChosen(); //getter here
        char getType(); // allows you to get the type to any of the possible characters in the grid
        void setX(int newX); // allows you to change the x of a already instantiated object
        void setY(int newY); // allows you to change the y of a already instantiated object
        void setChosen(bool chosen); //setter here
        void setType(char c); // allows you to set the type to any of the possible characters in the grid
        static Vector* populateList(int n); // populates the list with all of the objects with a correct x and y


};
#endif