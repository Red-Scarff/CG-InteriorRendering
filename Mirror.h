void drawObjectsforMirror() {
	drawTable();
	book1();
	book1top();
	book2();
	book2top();
	book3();
	book3top();
	pages();
	glasscube();
	drawWallM();
	drawFloor();
}

void drawMirrors() {
    GLint buffers = GL_NONE; // ���ڴ洢��ǰ����ɫ������
    glGetIntegerv(GL_DRAW_BUFFER, &buffers); // ��ȡ��ǰ����ɫ������

    glClearStencil(0x00); // ����ģ�建���������ֵΪ0
    glEnable(GL_STENCIL_TEST); // ����ģ�����
    glColorMask(0, 0, 0, 0); // ������ɫд�루��������ɫ����Ļ��

    // ����ģ�����������ͨ��ģ����ԣ�����1�滻ģ�建�����е�ֵ
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE); // ����ģ�����Ϊ�滻
    glStencilFunc(GL_ALWAYS, 1, 0xffffffff); // ����ͨ��ģ����ԣ�����ģ�建�����е�ֵ����Ϊ1

    // ������Ȳ��ԣ���ʼ����ģ������
    glDisable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);


    glNormal3f(0.0f, 0.0f, 1.0f); // ���÷�������
    glVertex3f(-roomSize, -2.0f, -roomSize); // ���ö�������
    glVertex3f(roomSize, -2.0f, -roomSize);
    glVertex3f(roomSize, 8.0f, -roomSize);
    glVertex3f(-roomSize, 8.0f, -roomSize);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-roomSize, 8.0f, roomSize);
    glVertex3f(roomSize, 8.0f, roomSize);
    glVertex3f(roomSize, -2.0f, roomSize);
    glVertex3f(-roomSize, -2.0f, roomSize);
    glEnd();
    ////////////////////////////////////////////////

    // ����������ɫд��
    glDrawBuffer((GLenum)buffers); // �ָ�֮ǰ����ɫ������
    glColorMask(1, 1, 1, 1); // ������ɫд��

    // ����ģ����ԣ�����ģ�建����ֵΪ1�ĵط�����
    glStencilFunc(GL_EQUAL, 1, 0xffffffff); // ����ģ�建����ֵΪ1�ĵط�ͨ������
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); // ����ģ�����Ϊֻ�������޸�ģ�建������

    // �����ɫ����������Ȼ�����
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ������Ȳ��ԣ���ʼ���ƾ���
    glEnable(GL_DEPTH_TEST);
    glPushMatrix(); // ���浱ǰ����״̬

    // ���ƾ���ͼ��
    // ͨ��������ź�ƽ�ƣ����ɾ���Ч��
    for (float k = 2.0f; k < 20; k = k + 2) {
        glScalef(1.0f, 1.0f, -1.0f); 
        glTranslatef(0.0f, 0.0f, k * roomSize); 
        drawObjectsforMirror(); 
    }

    glPopMatrix(); // �ָ�����״̬

    // ����ģ����Ժ���ɫд��
    glDisable(GL_STENCIL_TEST); // ����ģ�����
    glDrawBuffer(GL_NONE); // ������ɫд��

    // �ָ�֮ǰ����ɫ������
    glDrawBuffer((GLenum)buffers);
}