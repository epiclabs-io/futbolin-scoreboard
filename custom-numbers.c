// Custom numbers to print in an LCD.
// XXXXX|XXXXX
// XXXXX|XXXXX
// XXXXX|XXXXX
// XXXXX|XXXXX
// XXXXX|XXXXX
// -----------
// XXXXX|XXXXX
// XXXXX|XXXXX
// XXXXX|XXXXX
// XXXXX|XXXXX
// XXXXX|XXXXX

// order is Top Left, Top Right, Bottom Left, Bottom Right

// 
// 0
// 
byte zero[4][8] = {
    {
        0b00000,
        0b00111,
        0b01111,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
    },
    {
        0b00000,
        0b11100,
        0b11110,
        0b00110,
        0b01110,
        0b10110,
        0b10110,
        0b10110,
    },
    {
        0b01101,
        0b01101,
        0b01101,
        0b01110,
        0b01100,
        0b01111,
        0b00111,
        0b00000,
    },
    {
        0b00110,
        0b00110,
        0b00110,
        0b00110,
        0b00110,
        0b11110,
        0b11100,
        0b00000,
    }};

//
// 1
//
byte one[4][8] = {
    {0b00000,
     0b00011,
     0b00111,
     0b01111,
     0b01111,
     0b00001,
     0b00001,
     0b00001,
     0b00},
    {01,

     0b00000,
     0b11000,
     0b11000,
     0b11000,
     0b11000,
     0b11000,
     0b11000,
     0b11000},
    {

        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b01111,
        0b01111,
        0b00000,
    },
    {

        0b11000,
        0b11000,
        0b11000,
        0b11000,
        0b11000,
        0b11110,
        0b11110,
        0b00000,
    }};

//
// 2
//
byte two[4][8] = {
    {
        0b00000,
        0b00011,
        0b00111,
        0b01100,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
    },
    {
        0b00000,
        0b11100,
        0b11110,
        0b01110,
        0b01110,
        0b01110,
        0b01110,
        0b11110,
    },
    {
        0b00001,
        0b00011,
        0b00011,
        0b00111,
        0b01110,
        0b01111,
        0b01111,
        0b00000,
    },
    {
        0b11100,
        0b11000,
        0b10000,
        0b00000,
        0b00000,
        0b11110,
        0b11110,
        0b00000,
    }};
//
// 3
//
byte three[4][8] = {
    {
        0b00000,
        0b00011,
        0b00111,
        0b01100,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
    },
    {
        0b00000,
        0b11100,
        0b11110,
        0b01110,
        0b00110,
        0b00110,
        0b01110,
        0b11100,
    },
    {
        0b00001,
        0b00000,
        0b00000,
        0b00000,
        0b01100,
        0b00111,
        0b00011,
        0b00000,
    },
    {
        0b11100,
        0b11100,
        0b01110,
        0b01110,
        0b11110,
        0b11100,
        0b11000,
        0b00000,
    }};
//
// 4
//
byte four[4][8] = {
    {
        0b00000,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b01110,
        0b00111,
        0b00011,
    },
    {
        0b00000,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b11100,
        0b11100,
    },
    {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
    },
    {
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b11110,
        0b11110,
        0b00000,
    }};
//
// 5
//
byte five[4][8] = {
    {
        0b00000,
        0b00111,
        0b01111,
        0b01110,
        0b01110,
        0b01110,
        0b01111,
        0b01111,
    },
    {
        0b00000,
        0b11110,
        0b11110,
        0b00110,
        0b00000,
        0b00000,
        0b11110,
        0b11110,
    },
    {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b01100,
        0b01111,
        0b01111,
        0b00000,
    },
    {
        0b00110,
        0b00110,
        0b00110,
        0b00110,
        0b01110,
        0b11110,
        0b11110,
        0b00000,
    }};
//
//6
//
byte six[4][8] = {
    {
        0b00000,
        0b00111,
        0b01111,
        0b01110,
        0b01110,
        0b01110,
        0b01111,
        0b01111,
    },
    {
        0b00000,
        0b11110,
        0b11110,
        0b00110,
        0b00000,
        0b00000,
        0b11000,
        0b11100,
    },
    {
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b01110,
        0b01111,
        0b01111,
        0b00000,
    },
    {
        0b00110,
        0b00110,
        0b00110,
        0b00110,
        0b01110,
        0b11110,
        0b11110,
        0b00000,
    }};
//
//7
//
byte seven[4][8] = {
    {
        0b00000,
        0b01111,
        0b01111,
        0b01100,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
    },
    {
        0b00000,
        0b11100,
        0b11100,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b11110,
    },
    {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
    },
    {
        0b11110,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b11110,
        0b11110,
        0b00000,
    }};
//
//8
//
byte eight[4][8] = {
    {
        0b00000,
        0b00111,
        0b01111,
        0b01100,
        0b01100,
        0b01110,
        0b01111,
        0b01111,
    },
    {
        0b00000,
        0b11100,
        0b11110,
        0b00110,
        0b00110,
        0b00110,
        0b11110,
        0b11110,
    },
    {
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b01111,
        0b00111,
        0b00000,
    },
    {
        0b00110,
        0b00110,
        0b00110,
        0b00110,
        0b00110,
        0b11110,
        0b11100,
        0b00000,
    }};
//
//9
//
byte nine[4][8] = {
    {
        0b00000,
        0b00001,
        0b00111,
        0b01110,
        0b01100,
        0b01100,
        0b01100,
        0b01110,
    },
    {
        0b00000,
        0b11000,
        0b11100,
        0b01110,
        0b00110,
        0b00110,
        0b00110,
        0b01110,
    },
    {
        0b00111,
        0b00011,
        0b00000,
        0b00000,
        0b01100,
        0b01111,
        0b00111,
        0b00000,
    },
    {
        0b11110,
        0b10110,
        0b00110,
        0b00110,
        0b00110,
        0b11100,
        0b11000,
        0b00000,
    }};