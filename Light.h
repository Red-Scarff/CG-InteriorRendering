static int animation = 1;
static GLboolean lightSwitch = GL_TRUE;
static int directionalLight = 0;


static float lightAngle = 0.0, lightHeight = 0;
GLfloat ang = 0;  
GLfloat angle2 = 0;   

int moving, startx, starty;
int lightMoving = 0, lightStartX, lightStartY;

static GLfloat lightPosition[4];
static GLfloat lightColor[] = { 1.0f, 1.0f, 0.8f, 0.5f }; //������ɫ

static void idle(void) {
	if (!lightMoving) {
		lightAngle += 0.005f;
	}
	glutPostRedisplay();
}

