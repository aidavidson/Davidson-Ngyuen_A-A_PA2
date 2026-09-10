#ifndef LEVEL_H
#define LEVEL_H

class Level {
    private:
        char** grid;
        bool warpPipe = false;
        bool complete = false;
        char c;
        char m;
        char g; 
        char k; 
        char b; 
        char x; 
        char w;
        int n;
    public:
        Level();
        Level(int n, int coins, int mushrooms, int goombas, int koopaTroopas, int nothing);
        ~Level();
};



#endif LEVEL_H
