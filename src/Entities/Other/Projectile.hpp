#pragma once
#define _USE_MATH_DEFINES
#include "Hitbox.hpp"
#include "SoundManager.hpp"

class Projectile {
    protected:
        std::pair<float, float> position = std::pair<float, float>(0, 0);
        HitBox hitBox = HitBox();
        float angle = 90;
        int speed = 6;

    public: 
        bool del = false;
        int ID;
        inline static std::vector<Projectile> projectiles;

        Projectile(float x, float y, int ID) {
            this->position.first = x;
            this->position.second = y;
            this->hitBox = HitBox(x, y, 10, 15); //hitboxes were too small so it didnt register the collision
            this->ID = ID;
        }

        Projectile(float x, float y, float angle, int ID) {
            this->position.first = x;
            this->position.second = y;
            this->hitBox = HitBox(x, y, 10, 15); //hitboxes were too small so it didnt register the collision
            this->angle = angle;
            this->ID = ID;
        }

        HitBox getHitBox() { return hitBox; }
        std::pair<double, double> getPosition() { return position; }

        void draw();
        void update();
        static void CleanProjectiles();
        static void ProjectileCollision();

};
