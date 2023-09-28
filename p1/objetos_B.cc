//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B.h"


//*************************************************************************
// _puntos3D
//*************************************************************************


_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}



//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}



//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
//aristas con glline	
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	//vértices indexados con las caras
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}



//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

//TODO	
void _triangulos3D::draw_solido(float r, float g, float b)
{
int i;
//aristas con glline	
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	//vértices indexados con las caras
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();


}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

//todo	
void _triangulos3D::draw_solido_colores( )
{
int i;
//aristas con glline	
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	//vértices indexados con las caras
	glColor3f(colores[i].r,colores[i].g,colores[i].b);
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

void _triangulos3D::asignar_gama_verdes(){
	for(int i = 0; i < colores.size(); i++){
		colores[i].r = 0.0;
		colores[i].g = 0.5 + (i * 0.05);
		colores[i].b = 0.0;
	}
}

void _triangulos3D::asignar_gama_rojos(){
	for(int i = 0; i < colores.size(); i++){
		colores[i].r = 0.5 + (i * 0.05);
		colores[i].g = 0.0;
		colores[i].b = 0.0;
	}
}

void _triangulos3D::asignar_randomColor(){
	for(int i = 0; i < colores.size(); i++){
		colores[i].r = (rand() % 100) / 100.0;
		colores[i].g = (rand() % 100) / 100.0;
		colores[i].b = (rand() % 100) / 100.0;
	}
}




//*************************************************************************
// clase cubo
//*************************************************************************

//8 vertices y 12 triángulos TODO
_cubo::_cubo(float tam)
{
//vertices
vertices.resize(8); 
vertices[0].x=0;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=0;
vertices[3].x=0;vertices[3].y=0;vertices[3].z=0;
vertices[4].x=0;vertices[4].y=tam;vertices[4].z=tam;
vertices[5].x=tam;vertices[5].y=tam;vertices[5].z=tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=0;
vertices[7].x=0;vertices[7].y=tam;vertices[7].z=0;


// triangulos
caras.resize(12);
//cara baja
caras[0]._0=3;caras[0]._1=1;caras[0]._2=0;
caras[1]._0=3;caras[1]._1=2;caras[1]._2=1;

//cara arriba
caras[2]._0=4;caras[2]._1=5;caras[2]._2=6;
caras[3]._0=4;caras[3]._1=6;caras[3]._2=7;

//cara izquierda
caras[4]._0=3;caras[4]._1=0;caras[4]._2=7;
caras[5]._0=0;caras[5]._1=4;caras[5]._2=7;

//cara delante
caras[6]._0=0;caras[6]._1=1;caras[6]._2=4;
caras[7]._0=1;caras[7]._1=5;caras[7]._2=4;

//cara derecha
caras[8]._0=1;caras[8]._1=2;caras[8]._2=5;
caras[9]._0=2;caras[9]._1=6;caras[9]._2=5;

//cara trasera
caras[10]._0=2;caras[10]._1=3;caras[10]._2=6;
caras[11]._0=3;caras[11]._1=6;caras[11]._2=7;

colores.resize(12);
// 12 colores
colores[0].x = 1.0; colores[0].y = 0.0; colores[0].z = 0.0; // Rojo
colores[1].x = 0.0; colores[1].y = 1.0; colores[1].z = 0.0; // Verde
colores[2].x = 0.0; colores[2].y = 0.0; colores[2].z = 1.0; // Azul
colores[3].x = 1.0; colores[3].y = 1.0; colores[3].z = 0.0; // Amarillo
colores[4].x = 1.0; colores[4].y = 0.0; colores[4].z = 1.0; // Magenta
colores[5].x = 0.0; colores[5].y = 1.0; colores[5].z = 1.0; // Cian
colores[6].x = 0.5; colores[6].y = 0.5; colores[6].z = 0.0; // Amarillo oscuro
colores[7].x = 0.0; colores[7].y = 0.5; colores[7].z = 0.5; // Verde azulado
colores[8].x = 0.5; colores[8].y = 0.0; colores[8].z = 0.5; // Morado
colores[9].x = 0.5; colores[9].y = 0.5; colores[9].z = 0.5; // Gris
colores[10].x = 0.0; colores[10].y = 0.0; colores[10].z = 0.5; // Azul oscuro
colores[11].x = 0.0; colores[11].y = 0.0; colores[11].z = 0.3; // ??





}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float  tam, float al)
{
	//vertices 
	vertices.resize(5); 
	vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
	vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
	vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
	vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
	vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

	//caras
	caras.resize(6);
	caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
	caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
	caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
	caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
	caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
	caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;

	colores.resize(6);
	// 12 colores
	colores[0].x = 1.0; colores[0].y = 0.0; colores[0].z = 0.0; // Rojo
	colores[1].x = 0.0; colores[1].y = 1.0; colores[1].z = 0.0; // Verde
	colores[2].x = 0.0; colores[2].y = 0.0; colores[2].z = 1.0; // Azul
	colores[3].x = 1.0; colores[3].y = 1.0; colores[3].z = 0.0; // Amarillo
	colores[4].x = 1.0; colores[4].y = 0.0; colores[4].z = 1.0; // Magenta
	colores[5].x = 0.0; colores[5].y = 1.0; colores[5].z = 1.0; // Cian





}


_tronco_piramide::_tronco_piramide(float tam1, float tam2, float alt){
	//vertices 
	vertices.resize(8); 
	vertices[0].x=-tam1;vertices[0].y=0;vertices[0].z=tam1;
	vertices[1].x=tam1;vertices[1].y=0;vertices[1].z=tam1;
	vertices[2].x=tam1;vertices[2].y=0;vertices[2].z=-tam1;
	vertices[3].x=-tam1;vertices[3].y=0;vertices[3].z=-tam1;
	vertices[4].x=-tam2;vertices[4].y=alt;vertices[4].z=tam2;
	vertices[5].x=tam2;vertices[5].y=alt;vertices[5].z=tam2;
	vertices[6].x=tam2;vertices[6].y=alt;vertices[6].z=-tam2;
	vertices[7].x=-tam2;vertices[7].y=alt;vertices[7].z=-tam2;

	// triangulos
	caras.resize(12);
	//cara baja
	caras[0]._0=3;caras[0]._1=1;caras[0]._2=0;
	caras[1]._0=3;caras[1]._1=2;caras[1]._2=1;

	//cara arriba
	caras[2]._0=4;caras[2]._1=5;caras[2]._2=6;
	caras[3]._0=4;caras[3]._1=6;caras[3]._2=7;

	//cara izquierda
	caras[4]._0=3;caras[4]._1=0;caras[4]._2=7;
	caras[5]._0=0;caras[5]._1=4;caras[5]._2=7;

	//cara delante
	caras[6]._0=0;caras[6]._1=1;caras[6]._2=4;
	caras[7]._0=1;caras[7]._1=5;caras[7]._2=4;

	//cara derecha
	caras[8]._0=1;caras[8]._1=2;caras[8]._2=5;
	caras[9]._0=2;caras[9]._1=6;caras[9]._2=5;

	//cara trasera
	caras[10]._0=2;caras[10]._1=3;caras[10]._2=6;
	caras[11]._0=3;caras[11]._1=6;caras[11]._2=7;

	

	colores.resize(12);
	// 12 colores
	colores[0].x = 1.0; colores[0].y = 0.0; colores[0].z = 0.0; // Rojo
	colores[1].x = 0.0; colores[1].y = 1.0; colores[1].z = 0.0; // Verde
	colores[2].x = 0.0; colores[2].y = 0.0; colores[2].z = 1.0; // Azul
	colores[3].x = 1.0; colores[3].y = 1.0; colores[3].z = 0.0; // Amarillo
	colores[4].x = 1.0; colores[4].y = 0.0; colores[4].z = 1.0; // Magenta
	colores[5].x = 0.0; colores[5].y = 1.0; colores[5].z = 1.0; // Cian
	colores[6].x = 0.5; colores[6].y = 0.5; colores[6].z = 0.0; // Amarillo oscuro
	colores[7].x = 0.0; colores[7].y = 0.5; colores[7].z = 0.5; // Verde azulado
	colores[8].x = 0.5; colores[8].y = 0.0; colores[8].z = 0.5; // Morado
	colores[9].x = 0.5; colores[9].y = 0.5; colores[9].z = 0.5; // Gris
	colores[10].x = 0.0; colores[10].y = 0.0; colores[10].z = 0.5; // Azul oscuro
	colores[11].x = 0.0; colores[11].y = 0.0; colores[11].z = 0.3; // ??
}