float angle = 0.0f; //������Ƕ�
float lx = 0.0f, lz = -1.0f; //�������������
float cx = -1.0f, cy = 1.0f, z = 13.0f; //�����λ������

float _angle = 0.0f;
float _cameraAngle = -30.0f;

//�����������
void handleSpecialKeypress(
		int key, 
		int x,
		int y
) {
	float fraction = 0.8f;

	//���ݼ���������������λ�������뷽������
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

//���»���
void update(int value) {
	_angle += 1.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

// �������ӽṹ
struct Particle {
    float x, y, z; // λ��
    float vx, vy, vz; // �ٶ�
    float life; // ��������
};

const int NUM_PARTICLES = 500; // ��������
Particle particles[NUM_PARTICLES]; // ��������

void initParticles() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = (rand() % 100 - 50) / 10.0f; // ��С��ʼ�ֲ���Χ
        particles[i].y = (rand() % 100 - 50) / 10.0f;
        particles[i].z = (rand() % 100 - 50) / 10.0f;

        particles[i].vx = (rand() % 100 - 50) / 2000.0f; // �����ٶ�
        particles[i].vy = (rand() % 100 - 50) / 2000.0f;
        particles[i].vz = (rand() % 100 - 50) / 2000.0f;

        particles[i].life = (rand() % 100) / 100.0f;
    }
}

void updateParticles() {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        if (rand() % 2 == 0) { // ���ٸ���Ƶ��
            particles[i].x += particles[i].vx;
            particles[i].y += particles[i].vy;
            particles[i].z += particles[i].vz;
        }

        particles[i].life -= 0.02f; // �ӿ���������˥���ٶ�
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
    glColor4f(0.8f, 0.8f, 0.8f, 0.3f); // ʹ�ø���͵���ɫ��͸����

    for (int i = 0; i < NUM_PARTICLES; i++) {
        glPushMatrix();
        glTranslatef(particles[i].x, particles[i].y, particles[i].z);
        glutSolidSphere(0.02f, 10, 10); // ��С���Ӵ�С
        glPopMatrix();
    }

    glDisable(GL_BLEND);
}