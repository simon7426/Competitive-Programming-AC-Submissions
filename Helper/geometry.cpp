#include<bits/stdc++.h>
using namespace std;

#define pb push_back


double EPS=1e-12;
double INF=1e100;


struct PT
{
	double x,y;
	PT(){}
	PT(double x,double y): x(x),y(y){}
	PT(const PT &p) : x(p.x),y(p.y){}
	PT operator +(const PT &p) const
	{
		return PT(x+p.x,y+p.y);
	}
	PT operator - (const PT &p) const
	{
		return PT(x-p.x,y-p.y);
	}
	PT operator *(const double &c) const
	{
		return PT(x*c,y*c);
	}
	PT operator / (double c)  const
	{
		return PT(x/c,y/c);
	}
};
double dot(PT p, PT q)
{
	return p.x*q.x+p.y*q.y;
}
double dist2(PT p,PT q)
{
	return dot(p-q,p-q);
}
double Sq(double a)
{
	return (a)*(a);
}
double cross(PT p,PT q)
{
	return p.x*q.y-p.y*q.x;
}

//rotate a point CCW or CW around the origin
PT rotateCCW90(PT p)
{
	return PT(-p.y, p.x);
}
PT rotateCW90(PT p)
{
	return PT(p.y, -p.x);
}
PT rotateCCW(PT p,double t)
{
	return PT(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}

/* 
	Project point c onto line through a &  b
    assuming a ! = b
*/
PT ProjectPointLine(PT a,PT b,PT c)
{
	return a+(b-a)*dot(c-a,b-a)/dot(b-a,b-a);
}


//Project point c onto line segment through a and b
PT ProjectPointSegment(PT a,PT b,PT c)
{
	double r= dot(b-a,b-a);
	if(fabs(r)<EPS) return a;
	r=dot(c-a,b-a)/r;
	if(r<0 )
		return a;
	if(r>1)
		return b;
	return a+(b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a,PT b,PT c)
{
	return sqrt(dist2(c,ProjectPointSegment(a,b,c)));
}


// compute distance between point(x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x,double y,double z,
						double a,double b,double c,double d)
{
	return (a*x+b*y+c*z-d)/sqrt(Sq(a)+Sq(b)+Sq(c));
}

// determine if lines from a to b and c and d are parallel or collinear
bool LinesParallel(PT a,PT b,PT c,PT d)
{
	return fabs(cross(b-a,c-d))<EPS;
}

bool LinesCollinear(PT a,PT b,PT c,PT d)
{
	return LinesParallel(a,b,c,d) 
		&& fabs(cross(a-b,a-c))<EPS 
		&& fabs(cross(c-d,c-a))<EPS;
}

// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(PT a,PT b,PT c,PT d)
{
	if(LinesCollinear(a,b,c,d))
	{
		if(dist2(a,c)<EPS || dist2(a,d)<EPS
		|| dist2(b,c)<EPS || dist2(b,d)<EPS) return true;

		if(dot(c-a,c-b)>0 && dot(d-a,d-b)>0 
		&& dot(c-b,d-b) > 0)
		return false;

		return true; 
	}

	if(cross(d-a,b-a) * cross(c-a,b-a)>0) return false;
	if(cross(a-c,d-c) * cross(b-c,d-c)>0) return false;
	return true;
}

/*
	Compute Intersection of line passing through a and b
	with line passing through c and d, assuming that unique
	intersection exists; for segment intersection, check if
	segment intersect first
*/
PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
	b=b-a;
	d=c-d;
	c=c-a;
	assert(dot(b,b)> EPS && dot(d,d)>EPS);
	return a+b*cross(c,d)/cross(b,d);
}

// Compute center of circle given three points
PT ComputeCircleCenter(PT a,PT b,PT c,PT d)
{
	b=(a+b)/2;
	c=(a+c)/2;
	return ComputeLineIntersection(b,b+rotateCW90(a-b),c,c+rotateCW90(a-c));
}

/*
	Determine if point is in a possibly non-convex polygon(By William
	Pandolph Frankling); return 1 for strictly interior points, 0 for
	strictly exterior point , o or 1 for the remaining points.
	Note that it's possible to convert this into an *exact* test using
	integer arithmetic by taking care of the division appropriately
	(making sure to deal with signs properly) and then by writing exact
	tests for checking point on polygon boundary
*/
bool PointInPolygon(const vector<PT> &p,PT q)
{
	bool c=0;
	for(int i=0;i<p.size();i++)
	{
		int j=(i+1)%p.size();
		if((p[i].y <= q.y && q.y<p[j].y
		 || p[j].y <= q.y && q.y<p[i].y) &&
			q.x < p[i].x + (p[j].x - p[i].x)*(q.y - p[i].y)/(p[j].y-p[i].y));
			c=!c;
	}
	return c;
} 

// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p,PT q)
{
	for(int i=0;i<p.size();i++)
		if(dist2(ProjectPointSegment(p[i],p[(i+1)%p.size()],q),q)<EPS)
			return true;
	return false;
}


/*
	Compute intersection of line through points a and b with
	circle centered at c with radius r>0 
*/
vector<PT> ComputeLineIntersection(PT a,PT b,PT c,double r)
{
	vector<PT> ret;
	b=b-a;
	a=a-c;
	double A= dot(b,b);
	double B= dot(a,b);
	double C= dot(a,a)-Sq(r);
	double D= B*B - A*C;
	if(D < -EPS)
		return ret;
	ret.pb(c+a+b*(-B+sqrt(D+EPS))/A);
	if(D>EPS)
		ret.pb(c+a+b*(-B-sqrt(D))/A);
	return ret;
}

/*
	Compute intersection of circle centered at a with radius r
	with circle centered at b with radius R
*/
vector<PT> ComputeCircleIntersection(PT a, PT b,double r, double R)
{
	vector<PT> ret;
	double d= sqrt(dist2(a,b));
	if(d > r+R || d+min(r,R)<max(r,R)) return ret;
	double x = (d*d-R*R+r*r)/(2*d);
	double y = sqrt(r*r-x*x);
	PT v=(b-a)/d;
	ret.pb(a+v*x+rotateCCW90(v)*y);
	if(y>0)
		ret.pb(a+v*x-rotateCCW90(v)*y);
	return ret;
}

/*
	This code computes the area or centroid of a (possibly convex)
	polygon, assuming that the co-ordinates are listed in a clockwise/
	counterclockwise fashion. Note  that centroid is ofter known as 
	"center of gravity/mass"	 
*/
double ComputeSignedArea(const vector<PT> & p)
{
	double area=0;
	for(int i=0;i<p.size();i++)
	{
		int j=(i+1)%p.size();
		area+=cross(p[i],p[j]);
	}
	return area/2.0;
}

double ComputeArea(const vector<PT> &p)
{
	return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT> &p)
{
	PT c(0,0);
	double scale= 6.0 * ComputeSignedArea(p);
	for(int i=0;i<p.size();i++)
	{
		int j = (i+1)%p.size();
		c=c+(p[i]+p[j])* cross(p[i],p[j]);
	}
	return c / scale;
}
// Tests whether or not a given polygon(in CW or CCW order ) is simple

bool isSimple(const vector<PT> &p)
{
	for(int i=0;i<p.size();i++)
	{
		for(int k=i+1;k<p.size();k++)
		{
			int j=(i+1)%p.size();
			int l=(k+1)%p.size();

			if(i==l ||j==k)
				continue;
			if(SegmentsIntersect(p[i],p[j],p[k],p[l]))
				return false;
		}
	}
	return true;
}
bool chk(PT a,PT b,PT c)
{
	return a.x<=b.x && b.x<=c.x || a.x<=b.y && b.y<=c.y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	PT p,q,a,b,c,d,f,g;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>p.x>>p.y>>q.x>>q.y>>f.x>>f.y>>g.x>>g.y;
		a.x=min(f.x,g.x);
		a.y=min(f.y,g.y);
		b.x=max(f.x,g.x);
		b.y=max(f.y,g.y);
		c.x=a.x;
		c.y=a.y;
		d.x=b.x;
		d.y=b.y;
		if(SegmentsIntersect(p,q,a,c)|| SegmentsIntersect(p,q,a,d)|| SegmentsIntersect(p,q,b,c) || SegmentsIntersect(p,q,b,d) || chk(a,p,c) || chk(b,q,d))
			puts("T");
		else puts("F");

	}	
}