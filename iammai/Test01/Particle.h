#pragma once
#include <vector>  
#include <math.h>  
#include <time.h>  
#include <stdlib.h>  
#include <iostream>  
#include <GL/gl.h>  
#include <GL/glu.h>  
#include"Data.h"
#define PI 3.1415926  
using namespace std;
typedef struct
{
	float r;
	float g;
	float b;
	float alpha;
}Color;

typedef struct
{
	Point3 position;
	Point3 velocity;
	Point3 acceleration;
	Color color;
	float age;
	float life;
	float size;
}Particle;
class ParticalSystem
{
public:
	GLuint tex[2];
	ParticalSystem();
	ParticalSystem(int _count, float _gravity) { ptlCount = _count; g = _gravity; };
	void init();
	void simulate(float dt);
	void aging(float dt);
	void applyGravity();
	void kinematics(float dt);
	void render();
	bool isStop();
	virtual ~ParticalSystem();
protected:
private:
	int ptlCount;
	float g;
	GLUquadricObj *mySphere;
	vector<Particle> particles;
};

