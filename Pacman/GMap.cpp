#include "GMap.h"

#define A true
#define B false
bool Stage_1::initData[MAPLENGTH][MAPLENGTH] = {
    B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B,
    B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B,
    B, A, A, B, A, A, B, B, B, A, B, B, B, A, A, B, A, A, B,
    B, A, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, A, B,
    B, A, B, A, A, A, B, B, B, A, B, B, B, A, A, A, B, A, B,
    B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B,
    B, A, A, A, A, A, B, B, A, A, A, B, B, A, A, A, A, A, B,
    B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B,
    B, A, B, A, A, A, A, A, B, A, B, A, A, A, A, A, B, A, B,
    A, A, A, A, A, A, A, A, B, B, B, A, A, A, A, A, A, A, A,
    B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B,
    B, A, B, A, A, B, A, A, A, A, A, A, A, B, A, A, B, A, B,
    B, A, B, A, B, B, B, A, A, A, A, A, B, B, B, A, B, A, B,
    B, A, A, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B,
    B, A, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, A, B,
    B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B,
    B, A, A, A, A, B, B, B, A, B, A, B, B, B, A, A, A, A, B,
    B, A, A, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B,
    B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B,
};
#undef A
#undef B
Stage_1::Stage_1()
{
    for (int i = 0; i < MAPLENGTH; i++) {
        for (int j = 0; j < MAPLENGTH; j++) {
                this->WallData[i][j] = !this->initData[i][j];
                this->BeanData[i][j] = this->initData[i][j];
        }
    }

}

#define A true
#define B false
bool Stage_2::initData[MAPLENGTH][MAPLENGTH] = {
    B, B, B, B, B, B, B, B, B, A, B, B, B, A, B, B, B, B, B,
    A, A, A, A, A, A, A, B, A, A, B, A, A, A, B, A, B, A, A,
    B, A, A, A, B, A, A, B, A, A, B, A, B, A, B, A, B, A, B,
    B, B, B, A, B, A, A, B, B, A, B, A, B, A, B, A, B, A, B,
    B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, A, A, A, B,
    B, A, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B,
    B, A, A, B, A, A, A, B, B, B, B, B, B, A, A, B, A, A, B,
    B, A, A, B, A, B, A, A, A, A, A, A, A, A, A, B, A, A, B,
    B, A, A, B, A, B, A, A, B, A, B, A, A, B, A, B, A, A, B,
    A, A, A, B, A, B, A, A, B, B, B, A, A, B, A, B, A, A, A,
    B, A, A, B, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B,
    B, A, A, B, A, A, A, B, B, B, B, B, A, B, A, A, A, A, B,
    B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B,
    B, A, A, A, B, B, B, B, B, B, B, A, A, A, A, A, A, A, B,
    B, A, A, A, A, A, A, A, A, A, A, A, A, B, A, A, A, A, B,
    B, B, A, B, B, A, A, A, A, B, B, B, A, B, A, A, A, A, B,
    B, A, A, A, B, B, B, A, A, A, A, B, A, B, B, B, A, A, B,
    A, A, A, A, B, A, A, A, A, A, A, B, A, A, A, B, A, A, A,
    B, B, B, B, B, B, B, B, B, A, B, B, B, A, B, B, B, B, B,
};
#undef A
#undef B
Stage_2::Stage_2()
{
    for (int i = 0; i < MAPLENGTH; i++) {
        for (int j = 0; j < MAPLENGTH; j++) {
            this->WallData[i][j] = !this->initData[i][j];
            this->BeanData[i][j] = this->initData[i][j];
        }
    }

}

#define A true
#define B false
bool Stage_3::initData[MAPLENGTH][MAPLENGTH] = {
    B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B,
    A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A,
    B, A, A, B, A, A, B, B, B, B, B, B, B, A, A, A, B, A, B,
    B, A, B, B, A, A, A, A, A, A, A, A, B, A, A, A, B, A, B,
    B, A, B, A, A, A, B, B, B, B, B, B, B, A, A, A, B, A, B,
    B, A, B, A, B, B, B, A, A, A, A, A, B, B, B, A, B, A, B,
    B, A, A, A, B, A, B, A, A, A, A, A, A, A, A, A, B, A, B,
    B, A, B, A, B, A, A, A, A, A, A, A, A, B, A, A, B, A, B,
    B, A, B, A, B, B, A, A, B, A, B, A, A, B, A, A, B, A, B,
    B, A, A, A, A, B, A, A, B, B, B, A, A, B, A, A, B, A, B,
    B, A, B, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B,
    B, A, B, A, A, B, A, A, A, A, A, A, B, B, B, A, B, A, B,
    B, A, B, A, A, B, A, B, B, B, B, B, B, A, B, A, B, A, B,
    B, A, B, A, A, B, A, A, A, A, A, A, A, A, B, A, B, A, B,
    B, A, B, B, A, B, B, B, B, B, B, A, B, A, B, A, B, A, B,
    B, A, A, A, A, B, A, A, A, A, A, A, B, A, B, A, B, A, B,
    B, B, B, B, B, B, A, A, B, B, B, A, B, A, B, A, B, A, B,
    A, A, A, A, A, A, A, A, B, A, A, A, A, A, B, A, A, A, A,
    B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B,
};
#undef A
#undef B
Stage_3::Stage_3()
{
    for (int i = 0; i < MAPLENGTH; i++) {
        for (int j = 0; j < MAPLENGTH; j++) {
            this->WallData[i][j] = !this->initData[i][j];
            this->BeanData[i][j] = this->initData[i][j];
        }
    }


}

#define A true
#define B false
bool Stage_4::initData[MAPLENGTH][MAPLENGTH] = {
    B, B, B, B, A, B, B, B, B, B, B, B, B ,B, A, B, B, B, B,
    B, A, A, A, A, A, A, A, A, B, A, A, A, A, A, A, A, A, B,
    B, A, B, B, A, B, A, B, A, A, A, B, A, B, A, B, B, A, B,
    B, A, B, B, A, B, A, B, B, B, B, B, A, B, A, B, B, A, B,
    B,A,A,A,A,A,A,A,A,B,A,A,A,A,A,A,A,A,B,
    B,B,B,B,A,B,B,B,A,B,A,B,B,B,A,B,B,B,B,
    A,A,A,B,A,B,A,A,A,A,A,A,A,B,A,B,A,A,A,
    B,B,B,B,A,B,A,B,A,A,A,B,A,B,A,B,B,B,B,
    A,A,A,A,A,A,A,B,A,A,A,B,A,A,A,A,A,A,A,
    B,B,B,B,A,B,A,B,B,B,B,B,A,B,A,B,B,B,B,
    A,A,A,B,A,B,A,A,A,A,A,A,A,B,A,B,A,A,A,
    B,B,B,B,A,B,A,B,B,B,B,B,A,B,A,B,B,B,B,
    B,A,A,A,A,A,A,A,A,B,A,A,A,A,A,A,A,A,B,
    B,A,B,B,A,B,B,B,A,B,A,B,B,B,A,B,B,A,B,
    B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,
    B,B,A,B,A,B,A,B,B,B,B,B,A,B,A,B,A,B,B,
    B,B,A,B,A,B,A,B,B,B,B,B,A,B,A,B,A,B,B,
    B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,
    B,B,B,B,A,B,B,B,B,B,B,B,B,B,A,B,B,B,B
};
#undef A
#undef B
Stage_4::Stage_4()
{
    for (int i = 0; i < MAPLENGTH; i++) {
        for (int j = 0; j < MAPLENGTH; j++) {
            this->WallData[i][j] = !this->initData[i][j];
            this->BeanData[i][j] = this->initData[i][j];
        }
    }


}
