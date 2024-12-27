float angle = 0.0f; //摄像机角度
float lx = 0.0f, lz = -1.0f; //摄像机方向向量
float cx = -1.0f, cy = 1.0f, z = 13.0f; //摄像机位置向量

float _angle = 0.0f;
float _cameraAngle = -30.0f;

//处理键盘输入
void handleSpecialKeypress(
		int key, 
		int x,
		int y
) {
	float fraction = 0.8f;

	//根据键盘输入更新摄像机位置向量与方向向量
	switch (key) {
		case GLUT_KEY_LEFT:
			angle -= 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT:
			angle += 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP:
			cx += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN:
			cx -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}

//重新绘制
void update(int value) {
	_angle += 1.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

// 定义粒子结构
struct Particle {
    float x, y, z; // 位置
    float vx, vy, vz; // 速度
    float life; // 生命周期
};

const int NUM_PARTICLES = 500; // 粒子数量
Particle particles[NUM_PARTICLES]; // 粒子数组

void initParticles() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = (rand() % 100 - 50) / 10.0f; // 缩小初始分布范围
        particles[i].y = (rand() % 100 - 50) / 10.0f;
        particles[i].z = (rand() % 100 - 50) / 10.0f;

        particles[i].vx = (rand() % 100 - 50) / 2000.0f; // 减慢速度
        particles[i].vy = (rand() % 100 - 50) / 2000.0f;
        particles[i].vz = (rand() % 100 - 50) / 2000.0f;

        particles[i].life = (rand() % 100) / 100.0f;
    }
}

void updateParticles() {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        if (rand() % 2 == 0) { // 减少更新频率
            particles[i].x += particles[i].vx;
            particles[i].y += particles[i].vy;
            particles[i].z += particles[i].vz;
        }

        particles[i].life -= 0.02f; // 加快生命周期衰减速度
        if (particles[i].life <= 0.0f) {
            particles[i].x = (rand() % 100 - 50) / 10.0f;
            particles[i].y = (rand() % 100 - 50) / 10.0f;
            particles[i].z = (rand() % 100 - 50) / 10.0f;
            particles[i].life = (rand() % 100) / 100.0f;
        }
    }
}

void drawParticles() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.8f, 0.8f, 0.8f, 0.3f); // 使用更柔和的颜色和透明度

    for (int i = 0; i < NUM_PARTICLES; i++) {
        glPushMatrix();
        glTranslatef(particles[i].x, particles[i].y, particles[i].z);
        glutSolidSphere(0.02f, 10, 10); // 减小粒子大小
        glPopMatrix();
    }

    glDisable(GL_BLEND);
}