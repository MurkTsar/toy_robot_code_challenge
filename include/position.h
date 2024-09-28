#ifndef POSITION_H
#define POSITION_H

struct Position {
    int x;
    int y;
    
    Position(int xPos = 0, int yPos = 0) : x(xPos), y(yPos) {}  // Default constructor

    bool operator==(const Position& pos) const {
        return x == pos.x && y == pos.y;
    }

    bool operator<(const Position& pos) const {
        return y < pos.y && x < pos.x;
    }

    bool operator>(const Position& pos) const {
        return y > pos.y && x > pos.x;
    }

    bool operator<=(const Position& pos) const {
        return y <= pos.y && x <= pos.x;
    }

    bool operator>=(const Position& pos) const {
        return y >= pos.y && x >= pos.x;
    }
};

#endif // POSITION_H