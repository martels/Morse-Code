#ifndef ENIGMA_H
#define ENIGMA_H

class wheel
{
    private:
    char side1[26];
    char side2[26];

    public:
    wheel(char*, char*);
    wheel(int);
    void rotate();
    void set();
    void get();
};

class pulgBoard
{

};

class enigma
{



};



#endif