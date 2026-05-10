#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

struct TPoint {
    int x, y;
};

class GameUnit {
protected:
    TPoint Position, Target;
    int Condition;      // 0 - 100
    int MoveSpeed;      // 0 - 5
    int AttackSpeed;    // 0 - 5
    int TactMoveSpeed, TactAttackSpeed;

public:
    GameUnit(int x, int y, int tx, int ty, int cond, int ms, int as)
        : Condition(cond), MoveSpeed(ms), AttackSpeed(as),
        TactMoveSpeed(0), TactAttackSpeed(0) {
        Position = { x, y };
        Target = { tx, ty };
    }

    virtual void attack() = 0;
    virtual void move() {
        if (MoveSpeed == 0) return;
        TactMoveSpeed++;
        if (TactMoveSpeed < (5 - MoveSpeed)) return;
        TactMoveSpeed = 0;

        int dx = Target.x - Position.x;
        int dy = Target.y - Position.y;

        if (abs(dx) > abs(dy))
            Position.x += (dx > 0) ? 1 : -1;
        else if (dy != 0)
            Position.y += (dy > 0) ? 1 : -1;
    }

    virtual void print() const {
        cout << "(" << Position.x << ", " << Position.y << ")";
    }

    virtual ~GameUnit() = default;
};

class Knight : public GameUnit {
    int Sword, Armor;

public:
    Knight(int x, int y, int tx, int ty, int cond, int ms, int as, int sword, int armor)
        : GameUnit(x, y, tx, ty, cond, ms, as), Sword(sword), Armor(armor) {
    }

    void attack() override {
        if (AttackSpeed == 0) return;
        TactAttackSpeed++;
        if (TactAttackSpeed < (5 - AttackSpeed)) return;
        TactAttackSpeed = 0;
        cout << "Knight attacks with sword power " << Sword << endl;
    }

    void print() const override {
        cout << "Knight at ";
        GameUnit::print();
    }
};

class Monster : public GameUnit {
    int Nails, Teeth;

public:
    Monster(int x, int y, int tx, int ty, int cond, int ms, int as, int nails, int teeth)
        : GameUnit(x, y, tx, ty, cond, ms, as), Nails(nails), Teeth(teeth) {
    }

    void attack() override {
        if (AttackSpeed == 0) return;
        TactAttackSpeed++;
        if (TactAttackSpeed < (5 - AttackSpeed)) return;
        TactAttackSpeed = 0;
        cout << "Monster attacks with teeth power " << Teeth << endl;
    }

    void print() const override {
        cout << "Monster at ";
        GameUnit::print();
    }
};

class GameEngine {
    vector<GameUnit*> Units;

public:
    void addUnit(GameUnit* unit) {
        Units.push_back(unit);
    }

    void tick() {
        for (auto unit : Units) {
            unit->move();
            unit->attack();
            unit->print();
            cout << endl;
        }
    }

    ~GameEngine() {
        for (auto unit : Units)
            delete unit;
    }
};

int main() {
    GameEngine engine;

    engine.addUnit(new Knight(0, 0, 5, 5, 100, 3, 2, 7, 6));
    engine.addUnit(new Monster(10, 10, 0, 0, 90, 2, 1, 5, 9));

    for (int i = 0; i < 10; ++i) {
        cout << "Tick " << i << ":" << endl;
        engine.tick();
        cout << "--------------" << endl;
    }

    return 0;
}
