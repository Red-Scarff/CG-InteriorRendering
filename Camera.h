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
