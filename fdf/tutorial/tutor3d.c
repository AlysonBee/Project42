
#include <math.h>

typedef struct 
{
	short x, y;
} _2D;

typedef struct 
{
	float x, y, z;
} _3D;

typedef struct 
{
	_3D Local;
	_3D World;
	_3D Aligned;
} Vertex_t;

float matrix[4][4];

void	MAT_Copy(float source[4][4], float dest[4][4])
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			dest[i][j] = source[i][j];
}

void	MAT_Mult(float mat1[4][4], float mat2[4][4], float dest[4][4])
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			dest[i][j] = mat1[i][0] * mat2[0][j] +
				mat1[i][1] * mat2[1][j] + 
				mat1[i][2] * mat2[2][j] +
				mat1[i][3] * mat2[3][j];
}

void	VEC_MultMatrix(_3D *Source, float mat[4][4], _3D *Dest)
{
	Dest->x = Source->x * mat[0][0] +
		Source->y * mat[1][0] +
		Source->z * mat[2][0] +
		mat[3][0];
	Dest->y = Source->x * mat[0][1] +
		Source->y * mat[1][1] +
		Source->z * mat[2][1] +
		mat[3][1];
	Dest->z = Source->x * mat[0][2] +
		Source->y * mat[1][2] +
		Source->z * mat[2][2] +
		mat[3][2];

}

float SinTable[256], CosTable[256];

#define SIN(x) SinTable[ABS((int)x & 255)]
#define COS(x) CosTable[ABS((int)x & 255)]

void 	M3D_Init()
{
	int		d;
	for (d = 0; d < 256; d++)
	{
		SinTable[d] = sin(d * M_PI / 128.0);
		CosTable[d] = cos(d * M_PI / 128.0);
	}
}

/*
 **  Transformation matrices in C 
 */

float mat1[4][4], mat2[4][4];

void 	MAT_Identity(float mat[4][4])
{
	mat[0][0]=1; mat[0][1]=0; mat[0][2]=0; mat[0][3]=0;
	mat[1][0]=0; mat[1][1]=1; mat[1][2]=0; mat[1][3]=0;
	mat[2][0]=0; mat[2][1]=0; mat[2][2]=1; mat[2][3]=0;
	mat[3][0]=0; mat[3][1]=0; mat[3][2]=0; mat[3][3]=1;
}

void	TR_Translate(float matrix[4][4], float tx, float ty, float tz)
{
	float 	tmat[4][4];

	tmat[0][0] = 1; tmat[0][1] = 0; tmat[0][2] = 0; tmat[0][3] = 0;
	tmat[1][0] = 0; tmat[1][1] = 1; tmat[1][2] = 0; tmat[1][3] = 0;
	tmat[2][0] = 0; tmat[2][1] = 0; tmat[2][2] = 1; tmat[2][3] = 0;
	tmat[3][0] = tx; tmat[3][1] = ty; tmat[3][2] = tz; tmat[3][3] = 1;
	MAT_Mult(matrix, tmat, mat1);
	MAT_Copy(mat1, matrix);
}

void	TR_Scale(float matrix[4][4], float sx, float sy, float sz)
{
	float smat[4][4];

	smat[0][0] = sx; smat[0][1] = 0; smat[0][2] = 0; smat[0][3] = 0;
	smat[1][0] = 0; smat[1][1] = sy; smat[1][2] = 0; smat[1][3] = 0;
	smat[2][0] = 0; smat[2][1] = 0; smat[2][2] = sz; smat[2][3] = 0;
	smat[3][0] = 0; smat[3][1] = 0; smat[3][2] = 0; smat[3][3] = 1;
	MAT_Mult(matrix, smat, mat1);
	MAT_Copy(mat1, matrix);
}

void TR_Rotate(float matrix[4][4],int ax,int ay,int az)
{
	float xmat[4][4], ymat[4][4], zmat[4][4];
	xmat[0][0]=1;        xmat[0][1]=0;        xmat[0][2]=0;        xmat[0][3]=0;
	xmat[1][0]=0;        xmat[1][1]=COS(ax);  xmat[1][2]=SIN(ax);  xmat[1][3]=0;
	xmat[2][0]=0;        xmat[2][1]=-SIN(ax); xmat[2][2]=COS(ax);  xmat[2][3]=0;
	xmat[3][0]=0;        xmat[3][1]=0;        xmat[3][2]=0;        xmat[3][3]=1;

	ymat[0][0]=COS(ay);  ymat[0][1]=0;        ymat[0][2]=-SIN(ay); ymat[0][3]=0;
	ymat[1][0]=0;        ymat[1][1]=1;        ymat[1][2]=0;        ymat[1][3]=0;
	ymat[2][0]=SIN(ay);  ymat[2][1]=0;        ymat[2][2]=COS(ay);  ymat[2][3]=0;
	ymat[3][0]=0;        ymat[3][1]=0;        ymat[3][2]=0;        ymat[3][3]=1;

	zmat[0][0]=COS(az);  zmat[0][1]=SIN(az);  zmat[0][2]=0;        zmat[0][3]=0;
	zmat[1][0]=-SIN(az); zmat[1][1]=COS(az);  zmat[1][2]=0;        zmat[1][3]=0;
	zmat[2][0]=0;        zmat[2][1]=0;        zmat[2][2]=1;        zmat[2][3]=0;
	zmat[3][0]=0;        zmat[3][1]=0;        zmat[3][2]=0;        zmat[3][3]=1;

	MAT_Mult(matrix,ymat,mat1);
	MAT_Mult(mat1,xmat,mat2);
	MAT_Mult(mat2,zmat,matrix);
}

#define FOCAL_DISTANCE 200


/*****************************************************
 *  												 *
 *	  				Polygon Structure		         *
 *													 *
 *****************************************************/

typedef struct
{
	_2D 	Points[20];
	int		PointsCount;
	int		Texture;
}	Polygon2D_t;

typedef struct
{
	int		Count;
	int		*Vertex;
	int		Texture;
	Vertex_t	P,M,N;
}	Polygon_t;

typedef struct
{
	int			VertexCount;
	int			PolygonCount;
	Vertex_t	*Vertex;
	Polygon_t	*Polygon;
	_3D			Scaling;
	_3D			Position;
	_3D			Angle;
	int			NeedUpdate;
}		Object_t;

void		POLY_Draw(Polygon2D_t *Polygon)
{
	_2D		P1, P2, P3;
	int		i;

	P1 = Polygon->Points[0];
	for (i = 1; i < PointsCount - 1; i++)
	{
		P2 = Polygon->Points[i];
		P3 = Polygon->Points[i + 1];
		POLY_Triangle(P1, P2, P3, Polygon->Texture);
	}
}


#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a < b) ? (b) : (a))
#define MaxPoint(a, b) ((a.y > b.y) ? a : b)
#define MinPoint(a, b) ((b.y > a.y) ? a : b)

#define MaxPoint3(a, b, c) MaxPoint(MaxPoint(a, b), MaxPoint(b, c))
#define MidPoint3(a, b, c) MaxPoint(MinPoint(a, b), MinPoint(a, c))
#define MinPoint3(a, b, c) MinPoint(MinPoint(a, b), MinPoint(b, c))


void		POLY_Triangle(_2D p1, _2D p2, _2D p3, char c)
{
	_2D 	p1d, p2d, p3d;
	int		xd1, yd1, xd2, yd2, i;
	int		Lx, Rx;

	p1d = MinPoint3(p1, p2, p3);
	p2d = MidPoint3(p2, p3, p1);
	p3d = MaxPoint3(p3, p1, p2);
	if (p2.y < p1.y)
	{
		p1d = MinPoint3(p2, p1, p3);
		p2d = MidPoint3(p1, p3, p2);
	}
	xd1 = p2d.x - p1d.x;
	yd1 = p2d.y - p1d.y;
	xd2 = p3d.x - p1d.x;
	yd2 = p3d.y - p1d.y;
	if (yd1)
	{
		for (i = p1d.y; i < p2d.y; i++)
		{
			Lx = p1d.x + ((i - p1d.y) * xd1) / yd1;
			Rx = p1d.x + ((i - p1d.y) * xd2) / xd2;
			if (Lx != Rx)
				VID_HLine(MIN(Lx, Rx), MAX(Lx, Rx), i, c);
		}
	}
	xd1=p3d.x-p2d.x;
	yd1=p3d.y-p2d.y;

	if(yd1)
		for(i   = p2d.y;   i <= p3d.y;   i++)
		{
			Lx =   p1d.x   + ((i   - p1d.y)   * xd2) / yd2;
			Rx =   p2d.x   + ((i   - p2d.y)   * xd1) / yd1;
			if(Lx!=Rx)
				VID_HLine(MIN(Lx,Rx),MAX(Lx,Rx),i,c);
		}
}	


void		VID_HLine(int x1, int x2, int y, char c)
{
	int		x;

	for (x = x1, x <= x2; x++)
		/* putpixel here */
}




int main(void)
{
	return (0);
}
