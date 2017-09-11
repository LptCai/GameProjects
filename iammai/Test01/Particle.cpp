#include"stdafx.h"
#include"Particle.h"
extern void ATLLoadTexture(char *fileName, GLuint &texture);
extern void ATLLoadTextureWithAlpha(char *fileName, GLuint &texture);
extern void texture(GLuint textr);
ParticalSystem::ParticalSystem()
{
	//ctor  
}

ParticalSystem::~ParticalSystem()
{
	//dtor  
}

void ParticalSystem::init()
{
	ATLLoadTextureWithAlpha("res\\butterfly0.bmp", tex[0]);
	ATLLoadTextureWithAlpha("res\\butterflyw.bmp", tex[1]);
	int i;
	srand(unsigned(time(0)));
	Color colors[3] = { { 0,0,1,1 },{ 1,0,1,1 } };
	for (i = 0; i<ptlCount; i++)
	{
		//theta =(rand()%361)/360.0* 2*PI;  
		Particle tmp = { Point3(0,0,0),Point3(((rand() % 100) - 26.0f),((rand() % 100) - 26.0f),((rand() % 100) - 26.0f)),Point3(0,0,0),colors[rand() % 2],0.0f,0.5 + 0.05*(rand() % 10),0.3f };
		particles.push_back(tmp);
	}
	mySphere = gluNewQuadric();
}
void ParticalSystem::simulate(float dt)
{
	aging(dt);
	applyGravity();
	kinematics(dt);
}
void ParticalSystem::aging(float dt)
{
	for (vector<Particle>::iterator iter = particles.begin(); iter != particles.end(); iter++)
	{
		iter->age += dt;
		if (iter->age>iter->life)
		{
			iter->position = Point3(0, 0, 0);
			iter->age = 0.0;
			iter->velocity =Point3(((rand() % 30) - 15.0f), ((rand() % 30) - 11.0f), ((rand() % 30) - 15.0f));
		}
	}
}
void ParticalSystem::applyGravity()
{
	for (vector<Particle>::iterator iter = particles.begin(); iter != particles.end(); iter++)
		iter->acceleration = Point3(0, g, 0);
}

void ParticalSystem::kinematics(float dt)
{
	for (vector<Particle>::iterator iter = particles.begin(); iter != particles.end(); iter++)
	{
		iter->position = iter->position + iter->velocity*dt;
		iter->velocity = iter->velocity + iter->acceleration*dt;
	}
}
void ParticalSystem::render()
{
	for (vector<Particle>::iterator iter = particles.begin(); iter != particles.end(); iter++)
	{
		//float alpha = 1 - iter->age / iter->life;//calculate the alpha value according to the age of particle. 
		/*b不要计算Alpha值*/
		Point3 tmp = iter->position;
		glColor4f(1.0, 1.0, 1.0, 1.0);
		texture(tex[1]);
		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);
		glPushMatrix();
		glTranslatef(tmp.x, tmp.y, tmp.z);
		glScalef(5,5,5);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_ALPHA);
		glPopMatrix();
	}
}
bool ParticalSystem::isStop()
{
	return true;
}
	