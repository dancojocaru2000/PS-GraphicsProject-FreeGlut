#ifndef GLUTDATA_H_INCLUDED
#define GLUTDATA_H_INCLUDED

#include <list>

#include <pthread.h>
extern pthread_mutex_t lock;


struct __Point2D
{
    int X;
    int Y;
    float r,g,b;

    __Point2D()
    {
	r=g=b=1;
    }
};

class GlutData
{
    public:
	static GlutData* getInstance();

	void addPoint(int x, int y);
	std::list<__Point2D>& getPoints();

	void addLine(int x1, int y1, int x2, int y2);
	std::list<__Point2D>& getLines();

	void addTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
	void addTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float r, float g, float b);
	std::list<__Point2D>& getTriangles();

	void removeAll();
    private:

	GlutData();
	std::list<__Point2D> points;
	std::list<__Point2D> lines;
	std::list<__Point2D> triangles;
	static GlutData *instance;
};

#endif // GLUTDATA_H_INCLUDED
