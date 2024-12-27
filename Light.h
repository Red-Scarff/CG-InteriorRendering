static int animation = 1;
static GLboolean lightSwitch = GL_TRUE;
static int directionalLight = 0;


static float lightAngle = 0.0, lightHeight = 0;
GLfloat ang = 0;  
GLfloat angle2 = 0;   

int moving, startx, starty;
int lightMoving = 0, lightStartX, lightStartY;

// 第一个光源
static GLfloat lightPosition[4];
static GLfloat lightColor[] = { 1.0f, 1.0f, 0.8f, 0.5f }; //光线颜色

static void idle(void) {
	if (!lightMoving) {
		lightAngle += 0.005f;
	}
	glutPostRedisplay();
}

void enableFog() {
    glEnable(GL_FOG);
    GLfloat fogColor[4] = { 0.5f, 0.5f, 0.5f, 1.0f }; // 雾效颜色
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_DENSITY, 0.05f);  // 雾的密度
    glFogf(GL_FOG_START, 10.0f);     // 雾的起始距离（从相机位置开始）
    glFogf(GL_FOG_END, 50.0f);     // 雾的结束距离（覆盖整个画布）
    glHint(GL_FOG_HINT, GL_NICEST);
}